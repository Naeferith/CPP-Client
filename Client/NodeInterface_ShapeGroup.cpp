#include "stdafx.h"
#include "NodeInterface_ShapeGroup.h"
#include "FileHandler.h"

NodeInterface_ShapeGroup::NodeInterface_ShapeGroup(NodeInterface * ni) : NodeInterface(ni) {
	drawable = new ShapeGroup();
}

NodeInterface_ShapeGroup::~NodeInterface_ShapeGroup() {}

void NodeInterface_ShapeGroup::executeRequest(XMLDocument& xml) {
	shared_ptr<ShapeGroup> shapeGroup = make_shared<ShapeGroup>();
	shapeGroup->setColor(retrieveColor(xml));
	ShapeManager* manager = ShapeManager::getInstance();
	manager->add(shapeGroup);
	
	int sizeBefore = manager->getShapes().size();

	FileHandler::loadShapeGroupFromXML(xml);
	//Shapes are loaded after the vector<Drawable*> located at (size-1)
	//Next shapes must be moved into the vector

	bool flag = false;
	auto shapes = &manager->getShapes();
	for (auto it = shapes->begin(); it != shapes->end(); it++) {
		if (!flag) flag = (*it) == shapeGroup;
		else {
			auto deleteIt = it;
			while (deleteIt != shapes->end()) {
				shapeGroup->add(*deleteIt);
				((shared_ptr<Drawable>)*deleteIt).reset();
				deleteIt = ((vector<shared_ptr<Drawable>>*)shapes)->erase(deleteIt);
			}
			break;
		}
	}
}