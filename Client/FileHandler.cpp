#include "stdafx.h"
#include "FileHandler.h"
#include "ShapeManager.h"
#include "VisitorXML.h"

#include <fstream>

#include "tinyxml2.h"

using namespace tinyxml2;

string FileHandler::path = string("");

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

			XMLNode* root = XMLShape.FirstChild();	//Retrieve root node -> Shape specification
			if (root == nullptr) break;				//Check if XML is not empty

			//root->Value();





		}
		myfile.close();
	}
}
