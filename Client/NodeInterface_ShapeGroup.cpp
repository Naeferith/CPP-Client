#include "stdafx.h"
#include "NodeInterface_ShapeGroup.h"

NodeInterface_ShapeGroup::NodeInterface_ShapeGroup(NodeInterface * ni) {
	drawable = new ShapeGroup();
}

NodeInterface_ShapeGroup::~NodeInterface_ShapeGroup() {}

void NodeInterface_ShapeGroup::executeRequest(XMLDocument& xml) {
}

const vector<Vector2D> NodeInterface_ShapeGroup::retrieveVertices(XMLDocument & doc) {
	vector<Vector2D> vertices = vector<Vector2D>();
	double x;
	double y;

	for (XMLElement* shape = doc.FirstChild()->NextSiblingElement(); shape != nullptr; shape = shape->NextSiblingElement()) {

	}

	return vertices;
}
