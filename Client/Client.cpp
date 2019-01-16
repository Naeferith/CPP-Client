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
	
	Shape* shape = new Shape(sommets2, color);
	Circle* circle = new Circle(Vector2D(), 8, color);
	shape::Rectangle* rect = new shape::Rectangle(Vector2D(100, 100), color2, 5, 8);
	ShapeGroup* shpgrp = new ShapeGroup(color);

	try {
		//SingletonWSA::getInstance();
		//SocketInOut socket = SocketInOut();

		/*cout << *shape << endl;
		cout << *circle << endl;
		cout << *rect << endl;*/
		*shpgrp + shape;
		*shpgrp + circle;
		*shpgrp + rect;
		//*shpgrp - shape;
		//cout << *shpgrp->accept(new VisitorXML) << endl;
		
		cout << shape->Area() << endl; //1440m²
		cout << circle->Area() << endl;//201.06m²
		cout << rect->Area() << endl;  //40m²
		cout << shpgrp->Area() << endl;//1681,06m²

	}
	catch (const Erreur& e) {
		std::cout << "ERREUR : " << e.what() << endl;
	}
system("pause");
	return 0;
}