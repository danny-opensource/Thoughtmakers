#include<iostream>
#include<string>
#include"../include/socket.h"

using namespace std;

int main()
{

try
    {

      //ClientSocket client_socket ( "localhost", 30000 );
	Socket client;	
	string host = "localhost";
	int port = 30000;
	client.create();
	client.connect(host,port);
        string reply;

      try
	{
	  string message = "hello from client";
	  client.send(message);
		
	  client.recv(reply);
	}
      catch ( ... ) {}

      std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;

    }
  catch ( ... )
    {
      //std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}

