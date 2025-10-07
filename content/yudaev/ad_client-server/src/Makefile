CC=g++
CFLAGS=-c -std=c++11 -Wall -pedantic
LDFLAGS=


all: client server

client: client.cpp
	$(CC) client.cpp -o client

server: server.o
	$(CC) server.o -o server

server.o: server.cpp unit.h hero.h dragon.h
	$(CC) $(CFLAGS) server.cpp unit.h dragon.h hero.h


clean:
	    rm -f *.o
	    rm -f *.gch

