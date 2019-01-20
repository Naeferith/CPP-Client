#pragma once

#include "NodeInterface.h"

/** @brief L'expert de Rectangle de la COR*/
class NodeInterface_Rectangle : public NodeInterface {
public:
	NodeInterface_Rectangle(NodeInterface* ni);
	virtual ~NodeInterface_Rectangle();

	void executeRequest(XMLDocument& xml) override;
};