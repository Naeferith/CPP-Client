#include "stdafx.h"
#include "NodeInterface_ShapeGroup.h"
#include "FileHandler.h"

NodeInterface_ShapeGroup::NodeInterface_ShapeGroup(NodeInterface * ni) : NodeInterface(ni) {
	drawable = new ShapeGroup();
}

NodeInterface_ShapeGroup::~NodeInterface_ShapeGroup() {}

void NodeInterface_ShapeGroup::executeRequest(XMLDocument& xml) {
	shared_ptr<ShapeGroup> shapeGroup = make_shared<ShapeGroup>();
	ShapeManager::getInstance()->operator+ (shapeGroup);
	auto shapes = ShapeManager::getInstance()->getShapes();
	FileHandler::load(xml.FirstChild()->ToDocument());
	//Shapes are loaded after the vector<Drawable*> located at (size-1)
	//Next shapes must be moved into the vector
	for (int i = shapes.size(); i != ShapeManager::getInstance()->getShapes().size(); shapes.pop_back()) {
		((vector<shared_ptr<Drawable>>)shapeGroup->getShapes()).push_back(shapes.back());
	}
	shapeGroup->setColor(retrieveColor(xml));
}

const vector<Vector2D> NodeInterface_ShapeGroup::retrieveVertices(XMLDocument & doc) {
	vector<Vector2D> vertices = vector<Vector2D>();

	for (XMLElement* shape = doc.FirstChild()->NextSiblingElement(); shape != nullptr; shape = shape->NextSiblingElement()) {

	}

	return vertices;
}
