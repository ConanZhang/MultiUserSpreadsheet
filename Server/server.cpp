//server.cpp
/*
 *Echo server
 *Set up to echo client text.
 * Conan Zhang, Bahrath G. 
 */
#include "server.h" 
#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
    // Default port
    int port = 2115;

    // If the user provided one argument for the port
    if(argc == 2)
    {
        std::istringstream argument(argv[1]);
       
        // Make sure user only provides integers for a port 
        if((argument >> port).fail())
        {
            std::cout << "Please provide a value that is a port." << std::endl;
            return 0;
        }
    }

    // Make IO service and server
    boost::asio::io_service ios;
    server s(ios, port);

    return 0;
}

/*
 * Server constructor makes new server with given IO service and port number.
 */
server::server(boost::asio::io_service& ios, int port):_io_service(ios), _acceptor(ios, tcp::endpoint(tcp::v4(), port))
{
    try
    {
        _session = new session(_io_service);
        beginAccept();

        // Begin communications with operating system for asynchronous operations
        ios.run();
    }
    catch(std::exception& exception)
    {
        std::cout << "Exception: " << exception.what() << std::endl;
    }
}

/*
 * Server destructor
 */
server::~server()
{
  delete _session;
}

/*
 * Server callback for when an accept happens.
 */
void server::acceptHandler(tcp::socket* _socket, const boost::system::error_code& error)
{
    if(!error)
    {
       _session->addClient(_socket); // Start session because a client has connected
       // Listen for more connections
       beginAccept(); 
    }
    else
    {
        delete _session;
        std::cout << "Server deleted session."<< std::endl;
    }
}

/*
 * Function to tell server to listen for socket connections.
 */
void server::beginAccept()
{
    // Create holder socket for connection
    tcp::socket* _socket = new tcp::socket(_io_service); 

    // Set asynchronous acceptor to the new session's socket and attach acceptHandler callBack
    _acceptor.async_accept( *_socket, 
                            boost::bind(&server::acceptHandler, 
                            this, 
                            _socket, 
                            boost::asio::placeholders::error));

    std::cout << "Begin accepting." << std::endl;

}

