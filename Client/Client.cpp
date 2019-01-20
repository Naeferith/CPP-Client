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
		Vector2D(0, 30),
		Vector2D(10, 0),
		Vector2D(34, 0),
		Vector2D(55, 45),
	};
	
	shared_ptr<Shape> shape = make_shared<Shape>(sommets, color);
	shared_ptr<Circle> circle = make_shared<Circle>(Vector2D(), 8, color);
	shared_ptr<shape::Rectangle> rect = make_shared<shape::Rectangle>(Vector2D(100, 100), color2, 5, 8);

	shared_ptr<ShapeGroup> shpgrp = make_shared<ShapeGroup>(color),
		shpgrp2(new ShapeGroup(color2));

	try {
		SingletonWSA::getInstance();
		SocketInOut socket = SocketInOut();

		ShapeManager* shp = ShapeManager::getInstance();
		

		cout << *shape << endl;
		cout << *circle << endl;
		cout << *rect << endl;

		shp->add(shape);
		shp->add(circle);
		shp->add(rect);
		cout << endl << endl << *shpgrp << endl;

		socket.Send(shp->accept(new VisitorXML));

		shpgrp2->add(shpgrp);
		shpgrp->setColor(color);
		cout << endl << endl << *shpgrp2 << endl << endl;

		cout << endl << endl << shpgrp2->accept(new VisitorXML) << endl << endl;

		//cout << *shpgrp->accept(new VisitorXML) << endl;

		//cout << *shpgrp << endl;
		
		cout << shape->Area() << endl; //1440m²
		cout << circle->Area() << endl;//201.06m²
		cout << rect->Area() << endl;  //40m²
		cout << shpgrp->Area() << endl;//1681,06m²
	}
	catch (const Erreur& e) {
		std::cout << "ERREUR : " << e.what() << endl;
	}

	shape.reset();
	circle.reset();
	rect.reset();

	shpgrp.reset();

//system("pause");
	return 0;
}