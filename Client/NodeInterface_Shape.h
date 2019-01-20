#pragma once

#include "NodeInterface.h"

/** @brief L'expert de Forme de la COR*/
class NodeInterface_Shape : public NodeInterface {
public:
	/** @brief Le constructeur par défaut. */
	NodeInterface_Shape(NodeInterface* ni);

	/** @brief Le destructeur. */
	virtual ~NodeInterface_Shape();

	/** @see NodeInterface.executeRequest(tinyxml2::XMLDocument& xml) */
	void executeRequest(XMLDocument& xml) override;
};