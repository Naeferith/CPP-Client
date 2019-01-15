#include "stdafx.h"
#include "NodeInterface_Rectangle.h"

NodeInterface_Rectangle::NodeInterface_Rectangle(NodeInterface * ni) {
	drawable = new shape::Rectangle();
}

NodeInterface_Rectangle::~NodeInterface_Rectangle() {}

void NodeInterface_Rectangle::executeRequest(XMLDocument& xml) {

}
