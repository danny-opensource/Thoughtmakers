//#include "ServerSocket.h"
#include"socket.h"
#include <string>

int main (/* int argc, int argv[]*/ )
{
  std::cout << "running....\n";

  try
    {
      // Create the socket
      Socket server ( /*30000*/ );
      server.create();
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
		  //new_sock >> data;
		  //new_sock << data;
		  
		}
	    }
	  catch ( ... ) {}

	}
    }
  catch (...)
    {
      std::cout << "Exception was caught:" <<endl;//<< e.description() << "\nExiting.\n";
    }

  return 0;
}
