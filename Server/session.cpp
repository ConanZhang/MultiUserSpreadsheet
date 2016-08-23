//session.cpp
/*
 * Handles reading and writing with the boost classes
 */

#include "session.h"

#include <boost/algorithm/string.hpp>

#include <iostream>
#include <sstream>
#include <algorithm>

session::session(boost::asio::io_service& ios)
{
    std::cout << "Session constructor." << std::endl;
}

session::~session()
{
    std::cout << "Session destructor." << std::endl;
}

/*
 * Callback for reading.
 */
void session::readHandler(tcp::socket* _socket, boost::asio::streambuf* _data , const boost::system::error_code& error, size_t size)
{
    // See if last character is NULL indicating client disconnection 
    if(size == 0)
    {
        std::cout << "Client disconnected." << std::endl;
        delete _data; 
        delete _socket;
        return;
    }

    // Parse message accordingly
    if(!error && size)
    {
        // Convert char array to string
        std::ostringstream oss;
        oss << _data;
        std::string message = oss.str();
        std::vector<std::string> values = stringSplit(message, ' ');  

        // If spreadsheet exists
        bool exists = false;

        std::string reply;

        //Check if command is valid
        if(values.size() == 3 && values[0].compare("connect") == 0)
	  {   
	    // Get the current list of usernames.
	    userNames = openUsernames();

            // If the given username is in our list of registered usernames
            if(userNames.find(values[1]) != userNames.end())
	      {
                exists = processConnect(_data, values, _socket);
	      }
            else
	      {
                  reply = "error 4 " + values[1] + '\n';
	      }
        }
        else if(values.size() == 3 && values[0].compare("cell") == 0)
        {
            reply = "error 3 Attempting to edit spreadsheet when not connected to one.\n";
        }
        else
        {
            reply = "error 2 " + message + '\n';
        }

        // Only continue listening to the client when they have not been successfully
        // connected to a spreadsheet.
        if(!exists)
        {
            // Write back data and attach callback writeHandler
            // NOTE: DATA BUFFER IS USED HERE
            boost::asio::async_write(*_socket, 
                    boost::asio::buffer(reply, reply.length()),
                    boost::bind(&session::writeHandler, 
                        this,
                        _socket,
                        _data,
                        boost::asio::placeholders::error));

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
 * Callback for writing.
 */
void session::writeHandler(tcp::socket* _socket, boost::asio::streambuf*  _data, const boost::system::error_code& error)
{
  if(!error)
    {
      std::cout << "Listen for more data." << std::endl;

      // Tell socket to begin reading
      boost::asio::async_read_until(*_socket,
              *_data,
              '\n',
              boost::bind(&session::readHandler,
                  this,
                  _socket,
                  _data,
                  boost::asio::placeholders::error,
                  boost::asio::placeholders::bytes_transferred));
      }
    // Eliminate problematic or useless session
    else
    {
        delete this;
        std::cout << "Write callback deleted session." << std::endl;
    }
}

/*
 * Server passes client to session to be handled.
 */
void session::addClient(tcp::socket* _socket)
{
    // Create own buffer for each client to read from
    boost::asio::streambuf* _data = new boost::asio::streambuf();

    // Tell socket to begin reading
    boost::asio::async_read_until(*_socket,
                                    *_data,
                                    '\n',
                                    boost::bind(&session::readHandler,
                                        this,
                                        _socket,
                                        _data,
                                        boost::asio::placeholders::error,
                                        boost::asio::placeholders::bytes_transferred));
}

/*
 * Splits message by spaces so that we can parse the commmand sent from client.
 */
std::vector<std::string> session::stringSplit(std::string command, char delimeter)
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
 *  Handles a valid connection request.
 */
bool session::processConnect(boost::asio::streambuf* _data,  std::vector<std::string> values, tcp::socket* _socket)
{
    std::set<spreadsheet*>::iterator it;

    // Find the requested spreadsheet or make a new one if it is not yet open.
    for(it = spreadsheets.begin(); it != spreadsheets.end(); it++)
    {
        if((*it)->getFilename() == values[2])
        {
            delete _data;
            // Add the user to the existing spreadsheet.
            (*it)->addClient(_socket);

            return true;
        }
    }

    // Make a new spreadsheet for the client and pass responsibility for listening to the spreadsheet.
    spreadsheet* newSpreadsheet = new spreadsheet(values[2],this);

    newSpreadsheet->addClient(_socket);

    // Add the client to the newly created spreadsheet.
    spreadsheets.insert(newSpreadsheet);

    delete _data;
    return true;
}

std::set<std::string> session::openUsernames()
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

// Stops tracking a spreadsheet as open. Should be called
// when there aren't any clients connected to the spreadsheet.
void session::removeOpenSpreadsheet(spreadsheet* toRemove)
{
  spreadsheets.erase(toRemove);
}
