#pragma once

#include <sstream>
#include <Ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")


/** 
	@brief Socket de dialogue. 
	
	C'est un socket unique (singleton) comportant des information pré-remplies comme la famille d'adresse utilisé ou le protocole.
*/
class SocketInOut {
private:
	/** @brief Le socket. */
	SOCKET sock;

	/** @brief Informations concernant le serveur avec lequel on va communiquer. */
	SOCKADDR_IN sockaddr;

	/** @brief La famille d'adresse (IPV4-IPV6). */
	int address;

	/** @brief Le type de socket. */
	int typeSocket;

	/** @brief Le protocole réseau utilisé. */
	int protocol;

	/** @brief L'adresse du serveur distant. */
	const char* addressIn;

	/** @brief Le port du serveur distant. */
	short port;

	/** @brief Connexion au serveur. */
	void Connect();

	/** @brief Initialisation du socket. */
	void InitSock();

	/**@brief Initialisation du socket avec lequel on va communiquer. */
	void InitSockIn();


public:
	/** @brief Le constructeur par défaut. */
	SocketInOut();

	/** @brief Le constructeur par valeurs. */
	SocketInOut(int address, int typeSocket, int protocol, const char* addressIn, int port);

	/** @brief Le destructeur. */
	virtual ~SocketInOut();

	/** @brief Ferme tout les sockets et coupe la connection. */
	void Close();
	/** @brief Ouvre tout les sockets et la connexion. */
	void Init();

	/** @brief Envoi d'un message au serveur. */
	void Send(const string& msg);

	/** @brief Accesseur de sock. */
	const SOCKET getSocket() const;

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const SOCKET& socket) const;
};