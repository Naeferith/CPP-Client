#pragma once

#include "NodeInterface.h"

class FileHandler {
private:
	static string path;
	static NodeInterface* chain;
	static void _load(tinyxml2::XMLDocument& doc);

public:
	static void save(const string& name);
	static void load(const string& name);
	static void load(tinyxml2::XMLDocument* doc);
	static vector<shared_ptr<Drawable>> loadShapeGroupFromXML(tinyxml2::XMLDocument& doc);
};

class XMLInterpreter {

};