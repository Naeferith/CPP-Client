#pragma once

#include "NodeInterface.h"

class NodeInterface_Rectangle : public NodeInterface {
public:
	NodeInterface_Rectangle(NodeInterface* ni);
	~NodeInterface_Rectangle();

	void executeRequest(XMLDocument& xml) override;
};