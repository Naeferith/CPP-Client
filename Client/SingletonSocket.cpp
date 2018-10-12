#include "stdafx.h"
#include "SingletonSocket.h"

//Aucune instance n'est actuellement créée
bool SingletonSocket::isCreated = false;

//Il faut déclarer instance dans le .cpp
SingletonSocket SingletonSocket::instance;

SingletonSocket::SingletonSocket() {
	//Empeche une 2eme instance du singleton.
	if (isCreated) throw logic_error("Vous ne pouvez pas créer une seconde instance de la classe Singleton.");
	
	//Initialisation de la librairie Winsock2
	int r;
	WSADATA wsaData;
	r = WSAStartup(MAKEWORD(2, 0), &wsaData);
	if (r) throw - 1;

	//Initialisation du socket
	sock = socket(familleAdresses, typeSocket, protocole);

	if (sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;

		// pour les valeurs renvoyées par WSAGetLastError() : 
		// cf. doc réf winsock

		throw -2;
	}

	//
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


	///Connexion au serveur
	r = connect(sock, (SOCKADDR *)&sockaddr, sizeof(sockaddr));

	// renvoie une valeur non nulle en cas d'échec.

	// Le code d'erreur peut être obtenu par un appel à WSAGetLastError()

	if (r == SOCKET_ERROR) {
		cout << "Erreur maggle" << endl;
		throw - 3;
	}

	//Affectation de la variable singleton
	instance = *this;

	//La variable est créée
	isCreated = true;
}

SingletonSocket::~SingletonSocket() {
	isCreated = false;
}

SingletonSocket& SingletonSocket::getInstance() { 
	if (!isCreated) SingletonSocket();
	return instance; 
}

const SOCKET SingletonSocket::getSocket() const { return sock; }

bool SingletonSocket::operator==(const SOCKET& socket) const { return sock == socket; }