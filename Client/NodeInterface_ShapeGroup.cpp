#include "stdafx.h"
#include "NodeInterface_ShapeGroup.h"

NodeInterface_ShapeGroup::NodeInterface_ShapeGroup(NodeInterface * ni) {
	drawable = new ShapeGroup();
}

NodeInterface_ShapeGroup::~NodeInterface_ShapeGroup() {}

void NodeInterface_ShapeGroup::executeRequest(XMLDocument& xml) {
}
