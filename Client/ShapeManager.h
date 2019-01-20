#pragma once

#include "DrawableGroup.h"
#include <vector>
#include <memory>

/** @brief Représente les formes lu et à écrire dans un fichier*/
class ShapeManager : public DrawableGroup {
	private:
		/** @brief Instance unique de la classe. */
		static ShapeManager* instance;

		ShapeManager();

	public:
		virtual ~ShapeManager();

		/** @brief Retourne l'instance unique de la classe, sinon la créer. */
		static ShapeManager* getInstance();

		/** @brief Implémentation de la methode accept du DP Visitor. */
		string  accept(Visitor* v);
};