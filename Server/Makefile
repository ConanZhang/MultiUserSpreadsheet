# Makefile for Spreadsheet Server

all: server.o session.o spreadsheet.o ssheet_model.o dependency_graph.o
	g++ server.o session.o spreadsheet.o ssheet_model.o dependency_graph.o -o server.out /usr/local/lib/libboost_system.a

server.o: server.cpp server.h session.h 
	g++ -c server.cpp

session.o: session.cpp session.h spreadsheet.h
	g++ -c session.cpp

spreadsheet.o: spreadsheet.cpp spreadsheet.h ssheet_model.h
	g++ -c spreadsheet.cpp

ssheet_model.o: ssheet_model.cpp ssheet_model.h dependency_graph.h
	g++ -c ssheet_model.cpp

dependency_graph.o: dependency_graph.cpp dependency_graph.h
	g++ -c dependency_graph.cpp

run:	all
	./server.out

clean:
	rm -f server.out *.o
