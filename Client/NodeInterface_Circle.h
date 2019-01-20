#pragma once

#include "NodeInterface.h"

/** @brief L'expert de Circle de la COR*/
class NodeInterface_Circle : public NodeInterface {
public:
	NodeInterface_Circle(NodeInterface* ni);
	virtual ~NodeInterface_Circle();

	void executeRequest(XMLDocument& xml) override;
};