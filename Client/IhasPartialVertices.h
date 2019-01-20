#pragma once

#include <vector>
#include <memory>
#include "Vector2D.h"

/**
	@brief Interface pour les Shape partiellement définies

	Certaines formes comme les Rectangle peuvent etre défini par un Vector2D ainsi qu'une longueur et une largeur.
	Or, cette figure dispose de 4 points. L'interface permet donc de calculer les points restants à partir des données qui la définissent.
*/
class IhasPartialVertices {
	public:
		/** @brief Le destructeur. */
		virtual ~IhasPartialVertices() {}

		/** @brief Récupére la totalité des sommets d'une forme IhasPartialVertices. */
		virtual vector<Vector2D> getCurrentVertices() const = 0;
};