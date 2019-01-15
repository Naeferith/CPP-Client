#pragma once

#include "NodeInterface.h"

class NodeInterface_Circle : public NodeInterface {
public:
	NodeInterface_Circle(NodeInterface* ni);
	~NodeInterface_Circle();

	void executeRequest(XMLDocument& xml) override;
};