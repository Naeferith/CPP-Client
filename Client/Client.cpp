// Client.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <Ws2tcpip.h>

#include "Circle.h"
#include "ShapeGroup.h"
#include "SingletonSocket.h"

#include "Visitor_Send.h"

#define _DEBUG_GRAPHIC_

using namespace std;

int main()
{

#ifdef _DEBUG_GRAPHIC_
	Circle *cercle = new Circle(Vector2D(1,1), 2, &Color::BLUE);

	cercle->accept(new Visitor_Send);

#endif

#ifdef _DEBUG_NETWORK_
	///Création du socket
	 SingletonSocket sock = SingletonSocket::getInstance();

	///Envoi d'un message au serveur
	const char * requete = "bonjour \r\n";

	// pour que le serveur réceptionne bien le message, 
	// on le termine par \r\n

	int l = strlen(requete);

	int r = send(sock.getSocket(), requete, l, 0);
	// envoi de la requête au serveur.
	// le caractère '\0' de fin de string n'est pas transmis 
	// envoie au plus l octets

	if (r == SOCKET_ERROR) throw -4;



#endif // _DEBUG_NETWORK_


	system("pause");
	return 0;
}

