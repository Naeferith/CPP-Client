#include "stdafx.h"
#include "NodeInterface.h"

using namespace tinyxml2;

NodeInterface::NodeInterface() {}

NodeInterface::NodeInterface(NodeInterface* ni) {
	next = ni;
}

NodeInterface::~NodeInterface() {
	delete drawable;
	delete next;
}

const string & NodeInterface::getDescription() const { return drawable->getName(); }

const NodeInterface * NodeInterface::getNext() const { return next; }

bool NodeInterface::canInterpret(const string & str) const { return getDescription() == str; }

void NodeInterface::interact(XMLDocument& xml) {
	if (canInterpret(xml.FirstChild()->Value())) executeRequest(xml);
	else if (next != nullptr) next->interact(xml);
}

shared_ptr<const Color> NodeInterface::retrieveColor(XMLDocument & doc) {
	XMLElement* colorNode = doc.FirstChildElement("color");
	if (colorNode == nullptr) //Exception
	return make_shared<const Color>();
}
