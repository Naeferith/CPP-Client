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

using namespace std;

int main()
{
	

	/************************Rectangle****************************/
	shared_ptr<const Color> blue = make_shared<const Color>(Color::retrieveDefaultColor(0,0,1));
	shared_ptr<shape::Rectangle> R1 = make_shared<shape::Rectangle>(Vector2D(1, -1), blue, 4, 2);


	/************************Triangle*****************************/
	shared_ptr<const Color> green = make_shared<const Color>(Color::retrieveDefaultColor(0, 1, 0));

	vector<Vector2D> vertices = { Vector2D(6, -1),
								 Vector2D(8, 0),
								 Vector2D(6, 1) };

	shared_ptr<Shape> T1 = make_shared<Shape>(vertices, green);

	/************************Cercle*******************************/
	shared_ptr < const Color> yellow = make_shared < const Color>(Color::retrieveDefaultColor(1, 1, 0));
	shared_ptr<Circle> C1 = make_shared<Circle>(Vector2D(11, 0), 2, yellow);

	/************************Groupe*******************************/
	shared_ptr < const Color> red = make_shared < const Color>(Color::retrieveDefaultColor(1, 0, 0));
	shared_ptr<ShapeGroup> G1 = make_shared<ShapeGroup>(red);
	G1->add(R1);
	G1->add(T1);
	G1->add(C1);

	/*************************Translation G1**********************/
	G1->Translate(Vector2D(-1, 0));
	G1->Rotate(Vector2D(0, 0), MY_PI/4);

	/*************************Aire du groupe**********************/
	cout << "Aire :" <<G1->Area()<<endl;

	/**************************Envoie de G1 **********************/
	SingletonWSA::getInstance();
	SocketInOut socket = SocketInOut();

	G1->Scale(Vector2D(0, 0), 30); //AGRANDIRE

	socket.Send(G1->accept(new VisitorXML));

	ShapeManager* file = ShapeManager::getInstance();
	file->add(G1);
	FileHandler::save("mabellefigure1");
	G1.reset();
	/*FileHandler::load("mabellefigure1");

	shared_ptr<ShapeGroup> G2;
	G2 = file->getShapes().back();

	socket.Send(G2->accept(new VisitorXML));*/

	

//system("pause");
	return 0;
}