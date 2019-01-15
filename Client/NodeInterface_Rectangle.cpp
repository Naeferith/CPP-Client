#include "stdafx.h"
#include "NodeInterface_Rectangle.h"

NodeInterface_Rectangle::NodeInterface_Rectangle(NodeInterface * ni) : NodeInterface(ni) {
	drawable = new shape::Rectangle();
}

NodeInterface_Rectangle::~NodeInterface_Rectangle() {}

void NodeInterface_Rectangle::executeRequest(XMLDocument& xml) {
	ShapeManager::getInstance()->operator+ (new shape::Rectangle(retrieveVertices(xml).at(0), retrieveColor(xml), retrieveDoubleProperty(xml, "width"), retrieveDoubleProperty(xml, "height")));
}