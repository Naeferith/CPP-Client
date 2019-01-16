#pragma once

#include "tinyxml2.h"

using namespace tinyxml2;

class NodeInterface {
private:
	NodeInterface* next = nullptr;
protected:
	Drawable* drawable  = nullptr;

public:
	NodeInterface();
	NodeInterface(NodeInterface* ni);
	virtual ~NodeInterface();
	virtual void executeRequest(tinyxml2::XMLDocument& xml) = 0;
	virtual const string getDescription() const;

	const NodeInterface* getNext() const;
	bool canInterpret(const string& str) const;
	void interact(tinyxml2::XMLDocument& xml);

	shared_ptr<const Color> retrieveColor(tinyxml2::XMLDocument& doc);
	virtual const vector<Vector2D> retrieveVertices(tinyxml2::XMLDocument& doc);
	const double retrieveDoubleProperty(tinyxml2::XMLDocument& doc, const string& prop);
};