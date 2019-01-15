#include "stdafx.h"
#include "FileHandler.h"
#include "ShapeManager.h"
#include "VisitorXML.h"

#include <fstream>

#include "tinyxml2.h"

using namespace tinyxml2;

string FileHandler::filePath(const string& name) {
	stringstream ss;
	ss << name << ".xml";
	return ss.str();
}

void FileHandler::save(const string& name="export") {
	//Generate export file name
	string path = filePath(name);

	//Create output file
	ofstream myfile;
	myfile.open(path);

	//Retrieve current shapes
	myfile << ShapeManager::getInstance()->accept(new VisitorXML);

	//Close file
	myfile.close();
}

void FileHandler::load(const string & name="export") {
	//Generate input file name
	string line, path = filePath(name);

	//Open file
	ifstream myfile(path);
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
