//spreadsheet.h
#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

#include <set>
#include <string>
#include <queue>
#include <stack>

#include "ssheet_model.h"
#include "session.h"
using boost::asio::ip::tcp;
class session;
struct request
{
    tcp::socket* socket;
    std::string message;
    boost::asio::streambuf* data;

};

class spreadsheet
{
    public:
  spreadsheet(std::string _filename, session* currentSession);
        ~spreadsheet();

        // Adds a user who can edit this spreadsheet.
        void addClient(tcp::socket* _socket);

        std::string getFilename();

    
    private:
        // Member variables
        std::string filename;
        std::set<tcp::socket*> connectedClients;
        std::set<std::string> userNames;
	session* runningSession;
        ssheet_model model;
        bool isProcessing;

        // Handlers
        void readHandler(tcp::socket* _socket, boost::asio::streambuf*  _data, const boost::system::error_code& error, size_t size);// Call back for asynchronous read call
        void writeHandler(tcp::socket* _socket, boost::asio::streambuf*   _data, const boost::system::error_code& error);// Call back for asynchronous write call
        void singleWriteHandler(const boost::system::error_code& error);// Call back for asynchronous single write call

        // Queue of edits to process
        std::queue<request> editQueue;
        boost::mutex editLock;

        // Stack of undos to process
        std::stack<std::vector<std::string> > undoHistory;
        boost::mutex undoLock;

        // Send lock
        boost::mutex sendLock;

        // Helper methods
        void removeClient(tcp::socket* _socket);
        std::vector<std::string> stringSplit(std::string command, char delimiter);
        void processUndo();
        std::string processCell(std::vector<std::string> values, std::string message);
        void processQueue();
	void saveUsernames();
	std::set<std::string> openUsernames();
};

#endif
