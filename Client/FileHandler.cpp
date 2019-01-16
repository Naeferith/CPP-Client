#include "stdafx.h"
#include "FileHandler.h"
#include "ShapeManager.h"
#include "VisitorXML.h"

#include <fstream>

#include "tinyxml2.h"
#include "NodeInterface_Shape.h"
#include "NodeInterface_ShapeGroup.h"
#include "NodeInterface_Circle.h"
#include "NodeInterface_Rectangle.h"

using namespace tinyxml2;

string FileHandler::path = string("");

//Responsability chain
NodeInterface* FileHandler::chain = 
	new NodeInterface_Shape(
	new NodeInterface_Circle(
	new NodeInterface_Rectangle(
	new NodeInterface_ShapeGroup(
	chain
	))));

void FileHandler::_load(XMLDocument& doc) {
	try {
		chain->interact(doc);
	}
	catch (const Erreur& e) { std::cout << e.what() << std::endl; }
}

void FileHandler::save(const string& name="export") {
	//Generate export file name
	stringstream ss;
	ss << FileHandler::path << name << ".xml";

	//Create output file
	ofstream myfile;
	myfile.open(ss.str());

	//Retrieve current shapes
	myfile << ShapeManager::getInstance()->accept(new VisitorXML);

	//Close file
	myfile.close();
}

void FileHandler::load(const string & name) {
	//Generate input file name
	stringstream ss;
	ss << FileHandler::path << name << ".xml";

	//Open file
	string line; //Line reader
	ifstream myfile(ss.str());
	if (myfile.is_open()) {
		XMLDocument XMLShape;
		XMLError e;

		

		while (getline(myfile, line)) {
			//Each line should be an XML Drawable
			//Thus, interpret each line as an XMLDocument
			
			e = XMLShape.Parse(line.c_str());		//Parse line as XML
			if (e != XML_SUCCESS) break;			//Check if XML is valid

			_load(XMLShape);
		}
		myfile.close();
	}
}

void FileHandler::load(XMLDocument* doc) {
	_load(*doc);
}

vector<shared_ptr<Drawable>> FileHandler::loadShapeGroupFromXML(XMLDocument& doc) {
	vector<shared_ptr<Drawable>> shapes = vector<shared_ptr<Drawable>>();
	XMLElement* shapegroupNode = doc.FirstChildElement();
	for (XMLElement* shape = shapegroupNode->FirstChildElement(); shape != nullptr; shape = shape->NextSiblingElement()) {

	}

	return shapes;
}
