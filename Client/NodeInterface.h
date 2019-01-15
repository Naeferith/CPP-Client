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
	virtual void executeRequest(XMLDocument& xml) = 0;
	virtual const string& getDescription() const;

	const NodeInterface* getNext() const;
	bool canInterpret(const string& str) const;
	void interact(XMLDocument& xml);

	shared_ptr<const Color> retrieveColor(XMLDocument& doc);
};