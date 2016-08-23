//spreadsheet.cpp
#include "spreadsheet.h"

#include <iostream>
#include <sstream>

spreadsheet::spreadsheet(std::string _filename, session* currentSession):model(_filename, "0")
{
    filename = _filename;
    isProcessing = false;
    runningSession = currentSession;
    std::cout<< "New spreadsheet." << std::endl;
}

spreadsheet::~spreadsheet()
{
    std::cout << "Spreadsheet destructor." << std::endl;
}

/*
 * Call back for asynchronous read call
 */
void spreadsheet::readHandler(tcp::socket* _socket, boost::asio::streambuf*  _data, const boost::system::error_code& error, size_t size)
{
    // See if last character is NULL indicating client disconnection 
    if(size == 0)
    {
        std::cout << "Client disconnected." << std::endl;
	
	// Remove the client from the list of connected clients 
	// and delete is allocated memory.
	connectedClients.erase(_socket);
        delete _data;
        delete _socket;

	// If there are no more sockets connected to this spreadsheet, it is 
	// safe to delete the spreadsheet. 
	if(connectedClients.size() == 0)
	  {
	    model.save();
	    runningSession->removeOpenSpreadsheet(this);
	    delete this;
	  }

        return;
    }

    // Parse message accordingly
    if(!error && size)
    {  
        // Convert char array to string
        std::ostringstream oss;
        oss << _data;
        std::string message = oss.str();

        request req;
        req.socket = _socket;
        req.message = message;
        req.data = _data;

        // Queue up command
        editLock.lock();
        editQueue.push(req);
        editLock.unlock();

        if(!isProcessing)
        {
            processQueue();
        }
    }
    // Eliminate problematic or useless session
    else
    {
        std::cout << "Read Callback deleted session." << std::endl;
        delete this;
    }

}

/*
 * Call back for asynchronous write call
 */
void spreadsheet::writeHandler(tcp::socket* _socket, boost::asio::streambuf*   _data, const boost::system::error_code& error)
{
    if(!error)
    {
        std::cout << "Writing to clients." << std::endl;
        // Tell socket to begin reading
        boost::asio::async_read_until(*_socket,
                *_data,
                '\n',
                boost::bind(&spreadsheet::readHandler,
                    this,
                    _socket,
                    _data,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));
    }
    else
    {
        std::cout << "Error in writing" << std::endl;
    }
}

/*
 * Call back for asynchronous single write call
 */
void spreadsheet::singleWriteHandler(const boost::system::error_code& error)
{
    if(!error)
    {
        std::cout << "Writing once to clients." << std::endl;
        
    }
    else
    {
        std::cout << "Error in writing once" << std::endl;
    }
}

/*
 * Returns filename for use in sessions.
 */
std::string spreadsheet::getFilename()
{
    return filename;
}

/*
 * Add client to current spreadsheet to listen to.
 */
void spreadsheet::addClient(tcp::socket* _socket)
{
    connectedClients.insert(_socket);
    
    std::set<std::string> cells = model.open(filename);

    // Get number of cells
    std::ostringstream oss;
    oss << cells.size();
    std::string cellNumber = oss.str();

    // Write to client connected and cell number
    std::string reply = "connected " + cellNumber + "\n"; 
    

    sendLock.lock();
    boost::asio::async_write(*_socket, 
            boost::asio::buffer(reply, reply.length()),
            boost::bind(&spreadsheet::singleWriteHandler, 
                this,
                boost::asio::placeholders::error));
    sendLock.unlock();
    
    // Send all cells in file
    for(std::set<std::string>::iterator it = cells.begin(); it != cells.end(); ++it)
    {
        reply =  *it + "\n";

        sendLock.lock();       
        boost::asio::async_write(*_socket, 
                boost::asio::buffer(reply, reply.length()),
                boost::bind(&spreadsheet::singleWriteHandler, 
                    this,
                    boost::asio::placeholders::error));
        sendLock.unlock();       
    }
  

    // Create own buffer for each client to read from
    boost::asio::streambuf* buffer = new boost::asio::streambuf();

    // Tell socket to begin reading
    boost::asio::async_read_until(*_socket,
                                    *buffer,
                                    '\n',
                                    boost::bind(&spreadsheet::readHandler,
                                        this,
                                        _socket,
                                        buffer,
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred));
}

/*
 * Remove clients from connected clients of this spreadsheet.
 */
void spreadsheet::removeClient(tcp::socket* client)
{
    connectedClients.erase(client);
}

/*
 * Splits message by spaces so that we can parse the commmand sent from client.
 */
std::vector<std::string> spreadsheet::stringSplit(std::string command, char delimeter)
{
    // Create vector to return
    std::vector<std::string> tempVec;

    // Put string into stream
    std::stringstream ss(command);
    std::string value;

    // Split string by delimeter and put into value to push into vector
    while(ss >> value)
    {
        tempVec.push_back(value);
    }

    return tempVec;
}

/*
 * Process undo command read from read handler.
 */
void spreadsheet::processUndo()
{
    // Get the command to undo from the undo history
    std::vector<std::string>& undoCommand = undoHistory.top();

    // Get values
    std::string undoValue = undoCommand[2];
    std::string oldValue = model.get_cell_contents(undoCommand[1]);

    // Undo model
    model.set_cell_contents(undoCommand[1], undoCommand[2]);

    std::cout << "Undo Value: " << undoValue << "\nOld Value: " << oldValue << std::endl;

    // Put correct message in buffer 
    std::string reply = undoCommand[0] + " " + undoCommand[1] + " " + undoValue + "\n";

    // Propagate undo to all connected clients
    for(std::set<tcp::socket*>::iterator it = connectedClients.begin(); it != connectedClients.end(); ++it)
    {
        sendLock.lock();
        boost::asio::async_write(**it, 
                boost::asio::buffer(reply, reply.length()),
                boost::bind(&spreadsheet::singleWriteHandler, 
                    this,
                    boost::asio::placeholders::error));
        sendLock.unlock();
    }

    undoHistory.pop();
    model.save();
}

/*
 * Process cell command read from read handler.
 */
std::string spreadsheet::processCell(std::vector<std::string> values, std::string message)
{
    std::string reply;

    try
    {
        if(values.size() < 3)
        {
           values.push_back(" "); 
        }
        // Save new value
        std::string newValue = values[2];

        // Overwrite vector with old value
        values[2] = model.get_cell_contents(values[1]);

        // Special case where undo is empty so to send empty string we must attach a return character
        if(values[2] == "")
        {
            values[2] = "\n";
        }

        // Reflect command on model
        model.set_cell_contents(values[1], newValue);

        // Add correct command to undo history
        undoLock.lock();
        undoHistory.push(values);
        undoLock.unlock();

        reply = values[0] + " " + values[1] + " " + newValue + '\n';

        // Propagate change to all connected clients
        for(std::set<tcp::socket*>::iterator it = connectedClients.begin(); it != connectedClients.end(); ++it)
        {
            sendLock.lock();
            boost::asio::async_write(**it, 
                    boost::asio::buffer(reply, reply.length()),
                    boost::bind(&spreadsheet::singleWriteHandler, 
                        this,
                        boost::asio::placeholders::error));
            sendLock.unlock();

        }

        std::cout << "New Value: " << newValue << "\nOld Value: " << values[2] << std::endl;
        model.save();
    }
    // Check for circular dependency error
    catch(int e)
    {
        // 20 is circular dependency
        if(e == 20)
        {
            // Get correct value from model
            values[2] = model.get_cell_contents(values[1]);

            // Put correct message in buffer 
            reply = values[0] + " " + values[1] + " " + values[2] + "\n";

            // Propagate change to all connected clients
            for(std::set<tcp::socket*>::iterator it = connectedClients.begin(); it != connectedClients.end(); ++it)
            {
                sendLock.lock();
                boost::asio::async_write(**it, 
                        boost::asio::buffer(reply, reply.length()),
                        boost::bind(&spreadsheet::singleWriteHandler, 
                            this,
                            boost::asio::placeholders::error));
                sendLock.unlock();
            }
            std::cout << "Circular error." << std::endl;
        }
        // Unforeseen error
        else
        {
            reply = "error 0 Unhandled error";
            std::cout << "Unhandled error." << std::endl;
        }
    }
    return reply;
}

/*
 * Helper method to process queue.
 */
void spreadsheet::processQueue()
{
    if(editQueue.size() == 0)
    {
        isProcessing = false;
        return;
    }
    isProcessing = true;

    // Get request and its properties
    request r = editQueue.front();
    std::string message = r.message;
    
    // Get message values to process
    std::vector<std::string> values = stringSplit(message, ' ');  

    std::string reply;
    
    if(values.size() > 0)
    {
        //Check if command is valid
        if(values[0].compare("cell") == 0)
        {   
            // Append all values after values[2] into one vector
            if(values.size() > 3)
            {
                for(std::vector<std::string>::size_type i = 3; i != values.size(); i++)
                {
                    values[2] = values[2] + values[i]; 
                }
            }

            reply = processCell(values, message); 
        }
        else if(values[0].compare("register") == 0 )
        {
            runningSession->saveLock.lock();
            userNames = openUsernames();

            // If the given username isn't in our list of registered usernames
            if(userNames.find(values[1]) == userNames.end())
            {
                // Register them 
                userNames.insert(values[1]); 

                // Save their username
                saveUsernames();
            }
            else
            {
                reply = "error 4 " + values[1] + "\n"; 
            }
            runningSession->saveLock.unlock();
        }
        else if(values[0].compare("undo") == 0 )
        {
            undoLock.lock();
            //Only process an undo if there are some
            if(undoHistory.size() != 0)
            {
                processUndo();
            }
            else
            {
                reply = "error 3 Undo stack is empty.\n"; 
            }
            undoLock.unlock();
        }
    }
    else
    {
        reply = "error 2 " + r.message + "\n"; 
    }

    // Write back data and attach callback writeHandler
    // NOTE: DATA BUFFER IS USED HERE
    sendLock.lock();
    boost::asio::async_write(*r.socket, 
            boost::asio::buffer(reply, reply.length()),
            boost::bind(&spreadsheet::writeHandler, 
                this,
                r.socket,
                r.data,
                boost::asio::placeholders::error));
    sendLock.unlock();

    // Remove processed message
    editQueue.pop();

    // Keep processing until queue is empty
    processQueue();
}

void spreadsheet::saveUsernames()
{
  std::string filename = "usernames.txt";
  std::ofstream myfile(filename.c_str(),std::ofstream::out);

  if(myfile.is_open())
    {
      for(std::set<std::string>::iterator it = userNames.begin(); it != userNames.end(); ++it)
	{
	  myfile << *it <<"\n";
	}
      myfile.close();
    }
}

std::set<std::string> spreadsheet::openUsernames()
{
  std::set<std::string> s;  
  std::string fname = "usernames.txt";
  std::string line;
  std::ifstream myfile(fname.c_str(),std::ifstream::in);
  if(myfile.is_open())
    {
      while(getline(myfile,line))
	{
	      s.insert(line);
	}
      
      myfile.close();
    }

  return s; 
}
