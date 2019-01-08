// Client.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <Ws2tcpip.h>

#include "Circle.h"
#include "ShapeGroup.h"
#include "SocketInOut.h"

#include "SingletonWSA.h"
#include "VisitorXML.h"

#define _DEBUG_GRAPHIC_

using namespace std;

int main()
{

#ifdef _DEBUG_GRAPHIC_
	shared_ptr<const Color> color = make_shared<const Color>(Color::RED);
	shared_ptr<const Color> color2 = make_shared<const Color>(Color::GREEN);
	
	Circle *cercle = new Circle(Vector2D(1,1), 2, color);

	vector<Vector2D> sommets = {
		Vector2D(50, 50),
		Vector2D(100, 50),
		Vector2D(100, 100),
		Vector2D(50, 100),
	};

	vector<Vector2D> sommets2 = {
		Vector2D(250, 250),
		Vector2D(300, 250),
		Vector2D(300, 300),
		Vector2D(250, 300),
	};
	
	cout << cercle->getColor() << endl;
	Shape *carre = new Shape(sommets, color);
	Circle *circle = new Circle();

	try {
		SingletonWSA::getInstance();
		//SocketInOut socket = SocketInOut();
		//socket.Send(*carre->accept(new VisitorXML));
		//socket.Send(*->accept(new VisitorXML));

		cout << Vector2D(300,500);

	}
	catch (const Erreur& e) {
		cout << "ERREUR : " << e.what() << endl;
	}
	

#endif

#ifdef _DEBUG_NETWORK_
	///Création du socket
	 SocketInOut sock = SocketInOut::getInstance();

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
	return 0;
}