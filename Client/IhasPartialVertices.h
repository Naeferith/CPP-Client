#pragma once

#include <vector>
#include <memory>
#include "Vector2D.h"

/**
	@brief Interface pour les Shape partiellement d�finies

	Certaines formes comme les Rectangle peuvent etre d�fini par un Vector2D ainsi qu'une longueur et une largeur.
	Or, cette figure dispose de 4 points. L'interface permet donc de calculer les points restants � partir des donn�es qui la d�finissent.
*/
class IhasPartialVertices {
	public:
		/** @brief Le destructeur. */
		virtual ~IhasPartialVertices() {}

		/** @brief R�cup�re la totalit� des sommets d'une forme IhasPartialVertices. */
		virtual vector<Vector2D> getCurrentVertices() const = 0;
};