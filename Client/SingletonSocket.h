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

	/** @brief Le socket. */
	SOCKET sock;

	/** @brief La famille d'adresse (IPV4-IPV6). */
	int familleAdresses = AF_INET;

	/** @brief Le type de socket. */
	int typeSocket = SOCK_STREAM;

	/** @brief Le protocole réseau utilisé. */
	int protocole = IPPROTO_TCP;

	/** @brief Le constructeur par défaut. */
	SingletonSocket();

public:
	/** @brief Le destructeur. */
	~SingletonSocket();

	/** @brief Accesseur de l'instance. */
	static SingletonSocket& getInstance();

	/** @brief Accesseur de sock. */
	const SOCKET getSocket() const;

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const SOCKET& socket) const;
};