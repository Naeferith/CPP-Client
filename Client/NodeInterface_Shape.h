#pragma once

#include "NodeInterface.h"

class NodeInterface_Shape : public NodeInterface {
public:
	NodeInterface_Shape(NodeInterface* ni);
	~NodeInterface_Shape();

	void executeRequest(XMLDocument& xml) override;
};