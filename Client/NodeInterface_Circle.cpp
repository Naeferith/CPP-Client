#include "stdafx.h"
#include "NodeInterface_Circle.h"

NodeInterface_Circle::NodeInterface_Circle(NodeInterface * ni) : NodeInterface(ni) {
	drawable = new Circle();
}

NodeInterface_Circle::~NodeInterface_Circle() {}

void NodeInterface_Circle::executeRequest(XMLDocument& xml) {
	ShapeManager::getInstance()->add(make_shared<Circle>(retrieveVertices(xml).at(0), retrieveDoubleProperty(xml, "radius"), retrieveColor(xml)));
}