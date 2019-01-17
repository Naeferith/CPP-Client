#pragma once

#include "DrawableGroup.h"
#include <vector>
#include <memory>

class ShapeManager : public DrawableGroup {
	private:
		static ShapeManager* instance;
		ShapeManager();

	public:
		virtual ~ShapeManager();

		static ShapeManager* getInstance();

		/** @brief Implémentation de la methode accept du DP Visitor. */
		string  accept(Visitor* v);
};