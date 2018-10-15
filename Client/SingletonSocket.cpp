#include "stdafx.h"
#include "SingletonSocket.h"

//Aucune instance n'est actuellement créée
bool SingletonSocket::isCreated = false;

//Winsock n'est pas encore initialisé
bool SingletonSocket::isInitialized = false;

//Aucune connexion n'est encore établie
bool SingletonSocket::isConnected = false;

//Il faut déclarer instance dans le .cpp
SingletonSocket SingletonSocket::instance;

SingletonSocket::SingletonSocket() {
	//Empeche une 2eme instance du singleton.
	if (isCreated) throw logic_error("Vous ne pouvez pas créer une seconde instance de la classe Singleton.");
	
	//Empèche une double initialisation
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

	///Représentant local
	sockaddr.sin_family = AF_INET;

	//Conversion de adr en wchar_t *
	size_t size = strlen(adr) + 1;
	wchar_t *wadr = new wchar_t[size];
	size_t outsize;
	mbstowcs_s(&outsize, wadr, size, adr, size - 1);

	InetPton(sockaddr.sin_family, wadr, &sockaddr.sin_addr.s_addr);

	//on free la mémoire
	delete[]wadr;

	// inet_addr() convertit de l'ASCII en entier

	sockaddr.sin_port = htons(port);

	// htons() assure que le port est bien inscrit dans le format du 
	// réseau (little-endian ou big-endian)

	//Affectation de la variable singleton
	instance = *this;

	//La variable est créée
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
	isCreated = false;
}

SingletonSocket& SingletonSocket::getInstance() { 
	if (!isCreated) SingletonSocket();
	return instance; 
}

bool SingletonSocket::IsConnected(){ return isConnected; }

void SingletonSocket::Connect(){
	if (!isCreated) throw Erreur(-1, "Socket non créé");
	if (isCreated && !isConnected) {
		int r = connect(instance.sock, (SOCKADDR *)&instance.sockaddr, sizeof(sockaddr));
		if (r == SOCKET_ERROR) throw Erreur(WSAGetLastError(), "Connexion au serveur impossible");
	}
}

void SingletonSocket::Send(const char * msg, const int length){
	if (!isConnected) Connect();
	int r = send(instance.sock, msg, length, 0);
	if (r == SOCKET_ERROR) throw Erreur(-1, "Erreur lors de l'envoi de message");
}

const SOCKET SingletonSocket::getSocket() const { return sock; }

bool SingletonSocket::operator==(const SOCKET& socket) const { return sock == socket; }