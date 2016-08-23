//session.h 
#ifndef SESSION_H 
#define SESSION_H 

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

#include <set>
#include <string>

#include "spreadsheet.h"

using boost::asio::ip::tcp;
class spreadsheet;
class session
{
    public:
        session(boost::asio::io_service& ios);
        ~session(); 

        void addClient(tcp::socket* client);

	// Global save lock for all spreadsheets saving usernames
	boost::mutex saveLock;

	// A method to allow other classes to remove open spreadsheets.
	void removeOpenSpreadsheet(spreadsheet* toRemove);

    private:
        // Private members
        std::set<spreadsheet*> spreadsheets;

        std::set<std::string> userNames;
	boost::mutex spreadsheetLock;
        
        // Handlers
        void readHandler(tcp::socket* _socket, boost::asio::streambuf*  _data, const boost::system::error_code& error, size_t size);// Call back for asynchronous read call
        void writeHandler(tcp::socket* _socket, boost::asio::streambuf*   _data, const boost::system::error_code& error);// Call back for asynchronous write call

        // Helper methods
        std::vector<std::string> stringSplit(std::string command, char delimiter);
        bool processConnect(boost::asio::streambuf* _data,  std::vector<std::string> values, tcp::socket* _socket);
	std::set<std::string> openUsernames();
	 
};

#endif
