#include "stdafx.h"
#include "SingletonSocket.h"

//Aucune instance n'est actuellement cr��e
bool SingletonSocket::isCreated = false;

//Winsock n'est pas encore initialis�
bool SingletonSocket::isInitialized = false;

//Aucune connexion n'est encore �tablie
bool SingletonSocket::isConnected = false;

//Il faut d�clarer instance dans le .cpp
SingletonSocket SingletonSocket::instance;

SingletonSocket::SingletonSocket() {
	//Empeche une 2eme instance du singleton.
	if (isCreated) throw logic_error("Vous ne pouvez pas cr�er une seconde instance de la classe Singleton.");
	
	//Emp�che une double initialisation
	if (!isInitialized) {
		try {
			InitWS2();
		}
		catch (const Erreur& e) {
			cout << "Erreur : " << e.what() << endl;
			throw Erreur(-1, "Abort socket construction");
		}
		isInitialized = true;
	}
	
	//Initialisation du socket
	sock = socket(familleAdresses, typeSocket, protocole);
	if (sock == INVALID_SOCKET)	throw Erreur(WSAGetLastError(), "Failed initialize socket");

	///Repr�sentant local
	sockaddr.sin_family = AF_INET;

	//Conversion de adr en wchar_t *
	size_t size = strlen(adr) + 1;
	wchar_t *wadr = new wchar_t[size];
	size_t outsize;
	mbstowcs_s(&outsize, wadr, size, adr, size - 1);

	InetPton(sockaddr.sin_family, wadr, &sockaddr.sin_addr.s_addr);

	//on free la m�moire
	delete[]wadr;

	// inet_addr() convertit de l'ASCII en entier

	sockaddr.sin_port = htons(port);

	// htons() assure que le port est bien inscrit dans le format du 
	// r�seau (little-endian ou big-endian)

	//Affectation de la variable singleton
	instance = *this;

	//La variable est cr��e
	isCreated = true;
}

void SingletonSocket::InitWS2() {
	//Initialisation de la librairie Winsock2
	int r;
	WSADATA wsaData;
	r = WSAStartup(MAKEWORD(2, 0), &wsaData);
	if (r) throw Erreur(-1, "Failed intializing Winsock2");
}

SingletonSocket::~SingletonSocket() {
	if (isConnected) {
		int r = shutdown(sock, SD_SEND);
		if (r == SOCKET_ERROR) {
			//debug
		}
		closesocket(sock);
		WSACleanup(); //De-init winsock DLL
		isConnected = false;
	}
	isCreated = false;
}

SingletonSocket& SingletonSocket::getInstance() { 
	if (!isCreated) SingletonSocket();
	return instance; 
}

bool SingletonSocket::IsConnected(){ return isConnected; }

void SingletonSocket::Connect(){
	if (!isCreated) SingletonSocket();
	if (isCreated && !isConnected) {
		int r = connect(instance.sock, (SOCKADDR *)&instance.sockaddr, sizeof(sockaddr));
		if (r == SOCKET_ERROR) throw Erreur(WSAGetLastError(), "Connexion au serveur impossible");
		isConnected = true;
	}
}

void SingletonSocket::Send(const char * msg){
	if (!isConnected) Connect();
	int r = send(instance.sock, msg, strlen(msg), 0);
	if (r == SOCKET_ERROR) throw Erreur(WSAGetLastError(), "Erreur lors de l'envoi de message");
}

const SOCKET SingletonSocket::getSocket() const { return sock; }

bool SingletonSocket::operator==(const SOCKET& socket) const { return sock == socket; }