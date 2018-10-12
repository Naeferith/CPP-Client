// Client.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <Ws2tcpip.h>

#include "Circle.h"
#include "ShapeGroup.h"
#include "SingletonSocket.h"

#define _DEBUG_NETWORK_

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
	///Création du socket
	 SingletonSocket sock = SingletonSocket::getInstance();
	

	///Création d'un représentant local du serveur distant
	const char* adr = "127.0.0.1";
	short port = 9003;

	SOCKADDR_IN sockaddr; 		// informations concernant le serveur avec lequel on va communiquer
	sockaddr.sin_family = AF_INET;

	//Conversion de adr en wchar_t *
	size_t size = strlen(adr) + 1;
	wchar_t *wadr = new wchar_t[size];
	size_t outsize;
	mbstowcs_s(&outsize, wadr, size, adr, size-1);

	InetPton(sockaddr.sin_family, wadr, &sockaddr.sin_addr.s_addr);

	//on free la mémoire
	delete[]wadr;

	// inet_addr() convertit de l'ASCII en entier

	sockaddr.sin_port = htons(port);

	// htons() assure que le port est bien inscrit dans le format du 
	// réseau (little-endian ou big-endian)


	///Connexion au serveur
	int r = connect(sock.getSocket(), (SOCKADDR *)&sockaddr, sizeof(sockaddr));

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

	r = send(sock.getSocket(), requete, l, 0);
	// envoi de la requête au serveur.
	// le caractère '\0' de fin de string n'est pas transmis 
	// envoie au plus l octets

	if (r == SOCKET_ERROR) throw -4;



#endif // _DEBUG_NETWORK_


	system("pause");
	return 0;
}

