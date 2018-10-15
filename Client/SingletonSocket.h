#pragma once

#include <sstream>
#include <Ws2tcpip.h>


/** 
	@brief Socket de dialogue. 
	
	C'est un socket unique (singleton) comportant des information pré-remplies comme la famille d'adresse utilisé ou le protocole.
*/
class SingletonSocket {
private:
	/** @brief Instance singleton. */
	static SingletonSocket instance;

	/** @brief Booléen sur la création de instance. */
	static bool isCreated;

	/** @brief Booléen sur l'initialisation de la librairie Winsock2. */
	static bool isInitialized;

	/** @brief Booléen sur la connexion au serveur. */
	static bool isConnected;

	/** @brief Le socket. */
	SOCKET sock;

	/** @brief La famille d'adresse (IPV4-IPV6). */
	int familleAdresses = AF_INET;

	/** @brief Le type de socket. */
	int typeSocket = SOCK_STREAM;

	/** @brief Le protocole réseau utilisé. */
	int protocole = IPPROTO_TCP;

	/** @brief L'adresse du serveur distant. */
	const char* adr = "127.0.0.1";

	/** @brief Le port du serveur distant. */
	short port = 9003;

	/** @brief Informations concernant le serveur avec lequel on va communiquer. */
	SOCKADDR_IN sockaddr;
	
	/** @brief Le constructeur par défaut. */
	SingletonSocket();

	/** @brief Connexion au serveur. */
	static void Connect();

	/** @brief Initialisation de la libririe Winsock2. */
	static void InitWS2();

public:
	/** @brief Le destructeur. */
	~SingletonSocket();

	/** @brief Accesseur de l'instance. */
	static SingletonSocket& getInstance();

	/** @brief Accesseur de l'état de connexion. */
	static bool IsConnected();

	static void Send(const char* msg, const int length);

	/** @brief Accesseur de sock. */
	const SOCKET getSocket() const;

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const SOCKET& socket) const;
};