#pragma once

#include "NodeInterface.h"

/** @brief L'expert de Circle de la COR*/
class NodeInterface_Circle : public NodeInterface {
public:
	/** @brief Le constructeur par défaut. */
	NodeInterface_Circle(NodeInterface* ni);

	/** @brief Le destructeur. */
	virtual ~NodeInterface_Circle();

	/** @see NodeInterface.executeRequest(tinyxml2::XMLDocument& xml) */
	void executeRequest(XMLDocument& xml) override;
};