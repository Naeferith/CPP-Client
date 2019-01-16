// Client.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <Ws2tcpip.h>

#include "Circle.h"
#include "ShapeGroup.h"
#include "ShapeManager.h"
#include "SocketInOut.h"
#include "FileHandler.h"

#include "SingletonWSA.h"
#include "VisitorXML.h"

#define _DEBUG_GRAPHIC_

using namespace std;

int main()
{
#ifdef _DEBUG_MANAGER_
	ShapeManager* shapes = ShapeManager::getInstance();

	vector<Vector2D> sommets = {
		Vector2D(50, 50),
		Vector2D(100, 50),
		Vector2D(100, 100),
		Vector2D(50, 100),
	};

	shared_ptr<const Color> color = make_shared<const Color>(Color::RED);

	Shape* s0 = new Shape(sommets, color);

	*shapes + s0;


#endif

#ifdef _DEBUG_GRAPHIC_
	FileHandler::load("import");
	ShapeManager* shapes = ShapeManager::getInstance();

	shared_ptr<const Color> color = make_shared<const Color>(Color::retrieveDefaultColor(1,0,0));
	shared_ptr<const Color> color2 = make_shared<const Color>(Color::retrieveDefaultColor(0,1,0));
	
	shared_ptr<Circle> cercle = make_shared<Circle>(Vector2D(400,100), 20, color);

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
	
	Shape* shape = new Shape(sommets, color);
	Circle* circle = new Circle(Vector2D(), 50, color);
	shape::Rectangle* rect = new shape::Rectangle(Vector2D(100, 100), color2, 50, 50);
	ShapeGroup* shpgrp = new ShapeGroup(color);

	try {
		SingletonWSA::getInstance();
		//SocketInOut socket = SocketInOut();

		cout << *shape << endl;
		cout << *circle << endl;
		cout << *rect << endl;
		*shpgrp + shape;
		*shpgrp + circle;
		*shpgrp + rect;
		*shpgrp - shape;
		cout << *shpgrp << endl;
		
	}
	catch (const Erreur& e) {
		std::cout << "ERREUR : " << e.what() << endl;
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
system("pause");
	return 0;
}