//****************************************************/
//
// File Name   : socket.cpp
// Author      : krao24@gmail.com
// Description : Implementation of the Socket class.
//
//****************************************************/
#include<iostream>
#include <string>
#include <errno.h>
#include <fcntl.h>
#include<string.h>
#include "../include/socket.h"

using namespace std;
//****************************************************/
//
// Constructor for initializing the socket class
//
//****************************************************/
Socket::Socket():
  m_sock ( -1 )
{

  memset ( &m_addr,0,sizeof ( m_addr ) );

}

Socket::~Socket()
{
  if ( is_valid() )
    ::close ( m_sock );
}

//********************************************************************/
// Method to create socket with default parameters
// Parameters : None
// Return value : true if a valid socket is created, false otherwise
//********************************************************************/
bool Socket::create()
{

  cout<<"Creating the socket"<<endl;
  m_sock = socket ( AF_INET,SOCK_STREAM,0 );

  if ( ! is_valid() )
    return false;


  // TIME_WAIT - argh
  int on = 1;
  if ( setsockopt ( m_sock, SOL_SOCKET, SO_REUSEADDR, ( const char* ) &on, sizeof ( on ) ) == -1 )
	{
		cout<<"Failed to setsockopt!"<<endl;
    		return false;
	}


  return true;

}


//******************************************************/
// Method to assign name to the socket
// parameters : port[in] : the port number
// Return value : true if succeeded, false otherwise
//****************************************************/
bool Socket::bind ( const int port )
{

  cout<<"Bindind...."<<endl;

  if ( ! is_valid() )	
    {
      return false;
    }



  m_addr.sin_family = AF_INET;
  m_addr.sin_addr.s_addr = INADDR_ANY;
  m_addr.sin_port = htons ( port );

  int bind_return = ::bind ( m_sock/*File descriptor*/,
			     ( struct sockaddr * ) &m_addr,
			     sizeof ( m_addr ) );


  if ( bind_return == -1 )
    {
	cout<<"Failed to bind the socket"<<endl;
      return false;
    }

  return true;
}


//********************************************************************/
// Method that listens the particular port. The socket will be used 
// to accept the incoming connection requests using accept method
// Parameters : None
// Return value : true if we have not crossed the max connection
//		  false otherwise
//********************************************************************/

bool Socket::listen() const
{
  cout<<"Listening....."<<endl;
  if ( ! is_valid() )
    {
      cout<<"Invalid...listen failed!"<<endl;
      return false;
    }

  int listen_return = ::listen ( m_sock, MAXCONNECTIONS );


  if ( listen_return == -1 )
    {
	cout<<"listen failed"<<endl;
        return false;
    }

  return true;
}

//*****************************************************************************/
// It extracts the first connection request on the queue of pending
// connections for the listening socket,sockfd, creates a new connected socket, 
// and returns a new file descriptor referring to that socket. 
// The newly created socket is not in the listening state. 
// The original socket sockfd is unaffected by this call.
// Parameters : Socket&[in/out]
// Return value : true if a valid socket is created, false otherwise
//*****************************************************************************/

bool Socket::accept ( Socket& new_socket ) const
{
  int addr_length = sizeof ( m_addr );
  new_socket.m_sock = ::accept ( m_sock, ( sockaddr * ) &m_addr, ( socklen_t * ) &addr_length );

  if ( new_socket.m_sock <= 0 )
    return false;
  else
    return true;
}


//********************************************************************/
// Method that transmits a message to another socket 
// Parameters : string s[in]
// Return value : true if send succeeds, false otherwise
//********************************************************************/

bool Socket::send ( const std::string s ) const
{
  cout<<"Sending message"<<s<<endl;
  int status = ::send ( m_sock, s.c_str(), s.size(), MSG_NOSIGNAL );
  if ( status == -1 )
    {
      cout<<"Send failed!"<<endl;
      return false;
    }
  else
    {
      return true;
    }
}


//********************************************************************/
// Method receives messages from the socket 
// to accept the incoming connection requests using accept method
// Parameters : string& s[in/out]
// Return value : true if receive succeeds false otherwise
//********************************************************************/

int Socket::recv ( std::string& s ) const
{
  cout<<"Receiving message"<<endl;
  char buf [ MAXRECV + 1 ];

  s = "";

  memset ( buf, 0, MAXRECV + 1 );

  int status = ::recv ( m_sock, buf, MAXRECV, 0 );

  if ( status == -1 )
    {
      std::cout << "status == -1   errno == " << errno << "  in Socket::recv\n";
      return 0;
    }
  else if ( status == 0 )
    {
      return 0;
    }
  else
    {
      s = buf;
      cout<<"Message received "<<s<<endl;
      return status;
    }
}


//********************************************************************/
// Method connects the socket referred to by the file descriptor 
// sockfd to the address specified by addr. 
// Parameters : host[in] hostname, port[in] the portnumber
// Return value : true if connect succeeds false otherwise
//********************************************************************/

bool Socket::connect ( const std::string host, const int port )
{
  cout<<"Connecting..."<<endl;
  if ( ! is_valid() ) return false;

  m_addr.sin_family = AF_INET;
  m_addr.sin_port = htons ( port );

  int status = inet_pton ( AF_INET, host.c_str(), &m_addr.sin_addr );

  if ( errno == EAFNOSUPPORT ) return false;

  status = ::connect ( m_sock, ( sockaddr * ) &m_addr, sizeof ( m_addr ) );

  if ( status == 0 )
    return true;
  else
    return false;
}

//********************************************************************/
// Method that listens the particular port. The socket will be used 
// to accept the incoming connection requests using accept method
// Parameters : None
// Return value : true if we have not crossed the max connection
//		  false otherwise
//********************************************************************/

void Socket::set_non_blocking ( const bool b )
{

  int opts;

  opts = fcntl ( m_sock,
		 F_GETFL );

  if ( opts < 0 )
    {
      return;
    }

  if ( b )
    opts = ( opts | O_NONBLOCK );
  else
    opts = ( opts & ~O_NONBLOCK );

  fcntl ( m_sock,
	  F_SETFL,opts );

}

//Dummy main function..TODO : Remove this once the socket file is ready
/*int main()
{
return 0;
}*/
