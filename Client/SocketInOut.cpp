#include "stdafx.h"
#include "SocketInOut.h"
#include "SingletonWSA.h"

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
		throw Erreur(WSAGetLastError(), "Failed to connect to Server");
}

void SocketInOut::InitSock() {

	//Initialisation du socket.
	sock = socket(address, typeSocket, protocol);
	if (sock == INVALID_SOCKET)
		throw Erreur(WSAGetLastError(), "Failed initialize socket.\n Did you initialize WSA ?");
}

void SocketInOut::Close() {
	//On coupe la connexion pour l'envoie et la réception.
	if (shutdown(sock, SD_SEND) == SOCKET_ERROR)
		throw Erreur(WSAGetLastError(), "Failed to shut connection");

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

	//Convertit une séquence de caractéres multicotets en caractéres larges.
	if (mbstowcs_s(&outsize, wadr, size, addressIn, size - 1))
		throw Erreur(WSAGetLastError(), "Failed convert characters.");

	//Convertie une IPv4 ou IPv6 en text standart en forme binaire.
	if (InetPton(sockaddr.sin_family, wadr, &sockaddr.sin_addr.s_addr) != 1)
		throw Erreur(WSAGetLastError(), "Failed convert IP to binary.");

	//on free la mémoire
	//delete[]wadr;

	sockaddr.sin_port = htons(port);
	// htons() assure que le port est bien inscrit dans le format du 
	// réseau (little-endian ou big-endian)
}

void SocketInOut::Send(const string& msg){
	string str = msg + "\r\n";
	if (send(sock, str.c_str(), (int)str.size(), 0) == SOCKET_ERROR)
		throw Erreur(WSAGetLastError(), "Error can not send message");
}

const SOCKET SocketInOut::getSocket() const { return sock; }

bool SocketInOut::operator==(const SOCKET& socket) const { return sock == socket; }