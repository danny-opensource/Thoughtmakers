//***********************************
//
// This will run the socket server.
// The server will be listening 
//
//***********************************

#include <string>
#include"../include/socket.h"

int main ()
{
  std::cout << "running....\n";

  try
    {
      // Create the socket
      Socket server;
      server.create();
      //TODO:Need to change the port accordingly
      server.bind(30000);
      server.listen();
	
      while ( true )
	{

	  Socket new_sock;
	  server.accept ( new_sock );

	  try
	    {
	      while ( true )
		{
		  std::string data;
		  new_sock.send( data );
		  new_sock.recv( data );
		  	  
		}
	    }
	  catch ( ... ) {}

	}
    }
  catch (...)
    {
      std::cout << "Exception was caught:" <<std::endl;
    }

  return 0;
}
