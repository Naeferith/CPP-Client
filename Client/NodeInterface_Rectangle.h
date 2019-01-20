#pragma once

#include "NodeInterface.h"

/** @brief L'expert de Rectangle de la COR*/
class NodeInterface_Rectangle : public NodeInterface {
public:
	/** @brief Le constructeur par défaut. */
	NodeInterface_Rectangle(NodeInterface* ni);

	/** @brief Le destructeur. */
	virtual ~NodeInterface_Rectangle();

	/** @see NodeInterface.executeRequest(tinyxml2::XMLDocument& xml) */
	void executeRequest(XMLDocument& xml) override;
};