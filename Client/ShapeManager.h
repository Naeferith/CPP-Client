#pragma once

#include "Drawable.h"
#include <vector>
#include <memory>

class ShapeManager {
	private:
		static ShapeManager* instance;
		std::vector<Drawable*> shapes;
		ShapeManager();

	public:
		~ShapeManager();

		static ShapeManager* getInstance();

		const std::vector<Drawable*> getShapes() const;

		ShapeManager* operator+(Drawable* drawable);

		/** @brief Implémentation de la methode accept du DP Visitor. */
		string accept(Visitor* v);
};