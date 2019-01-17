#pragma once

#include "Drawable.h"
#include <vector>
#include <memory>

class ShapeManager {
	private:
		static ShapeManager* instance;
		std::vector<shared_ptr<Drawable>> shapes;
		ShapeManager();

	public:
		virtual ~ShapeManager();

		static ShapeManager* getInstance();

		const std::vector<shared_ptr<Drawable>> getShapes() const;

		ShapeManager* operator+(shared_ptr<Drawable> drawable);

		/** @brief Implémentation de la methode accept du DP Visitor. */
		string* accept(Visitor* v);
};