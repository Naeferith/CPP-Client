#pragma once

#include "Visitor.h"

/**
	@brief Fonctionnalité du DP Visieur.

	Envoie une requete au serveur distant.
*/
class Visitor_Send : public Visitor {
public:
	virtual void visit(Shape* vs);
};