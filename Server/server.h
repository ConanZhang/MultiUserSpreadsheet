//server.h 
#ifndef SERVER_H
#define SERVER_H

#include "session.h"

using boost::asio::ip::tcp;

class server
{
    public:
        server(boost::asio::io_service& ios, int port);
        ~server();

        void acceptHandler(tcp::socket* _socket, const boost::system::error_code& error);// Callback for asynchronous accept call
        
    private:
        // Private members
        boost::asio::io_service& _io_service;// Connects sockets to operating system
        session* _session;// Connection reading and writing
        tcp::acceptor _acceptor;// Listens for connections

        void beginAccept();// Tells server to start listening for connections
};

#endif
