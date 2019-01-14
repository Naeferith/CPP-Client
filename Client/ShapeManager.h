#pragma once

#include "Drawable.h"
#include <map>
#include <memory>

class ShapeManager {
	private:
		static ShapeManager* instance;
		int keyIndex = 0;
		std::map<int, Drawable*> shapes;
		ShapeManager();
	public:
		~ShapeManager();

		static ShapeManager* getInstance();

		const std::map<int, Drawable*> getShapes() const;

		ShapeManager* operator+(Drawable* drawable);

		/** @brief Implémentation de la methode accept du DP Visitor. */
		string* accept(Visitor* v);
};