// Client.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <Ws2tcpip.h>

#include "Circle.h"
#include "ShapeGroup.h"

#define _DEBUG_GRAPHIC_

using namespace std;

int main()
{

#ifdef _DEBUG_GRAPHIC_
	vector<Vector2D> sommets = {
		Vector2D(-1, 1),
		Vector2D(1, 1),
		Vector2D(1, -1),
		Vector2D(-1, -1),
	};

	ShapeGroup group;
	Circle cercle;
	Shape carre(sommets, &Color::BLUE);
	Shape carre2(sommets, &Color::BLUE);
	cout << (carre==carre2) << endl;
	//group + carre; bug

	//carre.Rotate(Vector2D(0, 0), 1.5708);
#endif

#ifdef _DEBUG_NETWORK_
	///Initialisation de la librairie Winsock2
	int r;
	WSADATA wsaData;
	r = WSAStartup(MAKEWORD(2, 0), &wsaData);
	if (r) throw -1;

	///Création de socket
	SOCKET sock;  // informations concernant le socket à créer : 
				  // famille d'adresses acceptées, mode connecté ou 
				  // non, protocole

	int familleAdresses = AF_INET;	// IPv4
	int typeSocket = SOCK_STREAM;	// mode connecté TCP
	int protocole = IPPROTO_TCP;	// protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres

	sock = socket(familleAdresses, typeSocket, protocole);

	if (sock == INVALID_SOCKET)
	{
		ostringstream oss;
		oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;

		// pour les valeurs renvoyées par WSAGetLastError() : 
		// cf. doc réf winsock

		throw -2;
	}

	///Création d'un représentant local du serveur distant
	//const char * adresseServeur = "127.0.0.1";
	short portServeur = 9111;

	SOCKADDR_IN sockaddr; 		// informations concernant le serveur avec lequel on va communiquer

	sockaddr.sin_family = AF_INET;

	//sockaddr.sin_addr.s_addr
	InetPton(sockaddr.sin_family, _T("127.0.0.1"), &sockaddr.sin_addr.s_addr);

	// inet_addr() convertit de l'ASCII en entier

	sockaddr.sin_port = htons(portServeur);

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


	///Envoi d'un message au serveur
	const char * requete = "bonjour \r\n";

	// pour que le serveur réceptionne bien le message, 
	// on le termine par \r\n

	int l = strlen(requete);

	r = send(sock, requete, l, 0);
	// envoi de la requête au serveur.
	// le caractère '\0' de fin de string n'est pas transmis 
	// envoie au plus l octets

	if (r == SOCKET_ERROR) throw -4;



#endif // _DEBUG_NETWORK_


	system("pause");
	return 0;
}

