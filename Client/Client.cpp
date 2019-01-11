// Client.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <Ws2tcpip.h>

#include "Circle.h"
#include "Rectangles.h"
#include "ShapeGroup.h"
#include "SocketInOut.h"

#include "SingletonWSA.h"
#include "VisitorXML.h"

#define _DEBUG_GRAPHIC_

using namespace std;

int main()
{

#ifdef _DEBUG_GRAPHIC_
	//définition des couleurs
	shared_ptr<const Color> color = make_shared<const Color>(Color::RED);
	shared_ptr<const Color> color2 = make_shared<const Color>(Color::GREEN);

	//Définition du tableau de Vecteur2D
	vector<Vector2D> sommets = {
		Vector2D(50, 50),
		Vector2D(100, 50),
		Vector2D(100, 100),
		Vector2D(50, 100),
	};
	
	//Création des 3 différentes formes
	Shape *shape = new Shape(sommets, color);
	Rectangles *carre = new Rectangles(vector<Vector2D>{Vector2D(0,1000), Vector2D(1000, 0)}, color);
	Circle *circle = new Circle(Vector2D(500,1000), 10, color);

	//Copie des 3 différentes formes
	Circle circle2 = Circle(*circle);
	Rectangles carre2 = Rectangles(*carre);
	Shape shape2 = Shape(*shape);


	try {

		//Affichage des formes
		cout << "circle " << *circle << endl <<
			"circle2" << circle2 << endl << endl <<
			"carre " << *carre << endl <<
			"carre2" << carre2 << endl << endl <<
			"shape " << *shape << endl <<
			"shape2" << shape2 << endl << endl;

		//Initialisation de la connexion et du socket
		SingletonWSA::getInstance();
		SocketInOut socket = SocketInOut();

		//Envoi des formes
		socket.Send(*carre->accept(new VisitorXML));
		socket.Send(*circle->accept(new VisitorXML));
		socket.Send(*shape->accept(new VisitorXML));

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