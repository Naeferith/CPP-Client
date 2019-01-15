#pragma once

#include "NodeInterface.h"

class NodeInterface_ShapeGroup : public NodeInterface {
public:
	NodeInterface_ShapeGroup(NodeInterface* ni);
	~NodeInterface_ShapeGroup();

	void executeRequest(XMLDocument& xml) override;
};