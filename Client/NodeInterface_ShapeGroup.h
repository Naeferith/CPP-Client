#pragma once

#include "NodeInterface.h"

/** @brief L'expert de groupe de forme de la COR*/
class NodeInterface_ShapeGroup : public NodeInterface {
public:
	/** @brief Le constructeur par défaut. */
	NodeInterface_ShapeGroup(NodeInterface* ni);

	/** @brief Le destructeur. */
	virtual ~NodeInterface_ShapeGroup();

	/** @see NodeInterface.executeRequest(tinyxml2::XMLDocument& xml) */
	void executeRequest(XMLDocument& xml) override;
};