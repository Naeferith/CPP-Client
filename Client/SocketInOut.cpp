#include "stdafx.h"
#include "SocketInOut.h"

SocketInOut::SocketInOut() : address(AF_INET), typeSocket(SOCK_STREAM), port(9003),
protocol(IPPROTO_TCP), addressIn("127.0.0.1")
{	Init();  }

SocketInOut::SocketInOut(int address, int typeSocket, int protocol,
	const char* addressIn, int port) : address(address), typeSocket(typeSocket),
	protocol(protocol), addressIn(addressIn), port(port) 
{	Init();  }

SocketInOut::~SocketInOut() {
	Close();
}

void SocketInOut::Init() {
	InitSock();
	InitSockIn();
	Connect();
}

void SocketInOut::Connect(){
	//Connection au socket distant.
	if (connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr)) == SOCKET_ERROR)
		throw Erreur(WSAGetLastError(), "Connexion to server impossible");
}

void SocketInOut::InitSock() {
	//Initialisation du socket.
	if (sock = socket(address, typeSocket, protocol) == INVALID_SOCKET)
		throw Erreur(WSAGetLastError(), "Failed initialize socket.\n Did you initialize WSA ?");
}

void SocketInOut::Close() {
	//On coupe la connexion pour l'envoie et la réception.
	if (shutdown(sock, SD_SEND) == SOCKET_ERROR)
		throw Erreur(WSAGetLastError(), "Failed to shut connection");;

	//On ferme le socket.
	if (closesocket(sock))
		throw Erreur(WSAGetLastError(), "Failed to shut Socket");
}

void SocketInOut::InitSockIn() {
	///Représentant local
	sockaddr.sin_family = address;

	//Conversion de adr en wchar_t *
	size_t outsize, size = strlen(addressIn) + 1;
	wchar_t *wadr = new wchar_t[size];
	mbstowcs_s(&outsize, wadr, size, addressIn, size - 1);

	InetPton(sockaddr.sin_family, wadr, &sockaddr.sin_addr.s_addr);

	//on free la mémoire
	delete[]wadr;

	// inet_addr() convertit de l'ASCII en entier

	sockaddr.sin_port = htons(port);
	// htons() assure que le port est bien inscrit dans le format du 
	// réseau (little-endian ou big-endian)
}

void SocketInOut::Send(const char * msg){
	if (send(sock, msg, strlen(msg), 0) == SOCKET_ERROR)
		throw Erreur(WSAGetLastError(), "Error can not send message");
}

const SOCKET SocketInOut::getSocket() const { return sock; }

bool SocketInOut::operator==(const SOCKET& socket) const { return sock == socket; }