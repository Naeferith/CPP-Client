#include "stdafx.h"
#include "NodeInterface.h"

#include <string>
using namespace tinyxml2;

NodeInterface::NodeInterface() {}

NodeInterface::NodeInterface(NodeInterface* ni) {
	next = ni;
}

NodeInterface::~NodeInterface() {
	delete drawable;
	delete next;
}

const string NodeInterface::getDescription() const { return drawable->getName(); }

const NodeInterface * NodeInterface::getNext() const { return next; }

bool NodeInterface::canInterpret(const string & str) const { return getDescription() == str; }

void NodeInterface::interact(XMLDocument& xml) {
	if (canInterpret(xml.FirstChild()->Value())) executeRequest(xml);
	else if (next != nullptr) next->interact(xml);
}

shared_ptr<const Color> NodeInterface::retrieveColor(XMLDocument & doc) {
	XMLElement* colorNode = doc.FirstChild()->FirstChildElement("color");
	if (colorNode == nullptr) 
		Erreur(_XML_ERROR, "XML Error : color node absent");
	double R = ::atof(colorNode->FirstChildElement("r")->GetText());
	double G = ::atof(colorNode->FirstChildElement("g")->GetText());
	double B = ::atof(colorNode->FirstChildElement("b")->GetText());
	return make_shared<const Color>(Color::retrieveDefaultColor(R, G, B));
}

const vector<Vector2D> NodeInterface::retrieveVertices(XMLDocument &doc) {
	vector<Vector2D> vertices = vector<Vector2D>();
	double x, y;
	XMLElement* verticesNode = doc.FirstChild()->FirstChildElement("vertices");
	if (verticesNode == nullptr) throw Erreur(_XML_ERROR, "XML Error : vertices node absent");
	for (XMLElement* e = verticesNode->FirstChildElement("vertice"); e != nullptr; e = e->NextSiblingElement("vertice")) {
		x = ::atof(e->FirstChildElement("x")->GetText());
		y = ::atof(e->FirstChildElement("y")->GetText());
		vertices.emplace_back(x, y);
	}
	return vertices;
}

const double NodeInterface::retrieveDoubleProperty(XMLDocument& doc, const string& prop) {
	XMLElement* radiusNode = doc.FirstChild()->FirstChildElement(prop.c_str());
	if (radiusNode == nullptr) throw Erreur(_XML_ERROR, "XML Error : radius node absent");
	return ::atof(radiusNode->GetText());
}