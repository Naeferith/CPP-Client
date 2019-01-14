#pragma once

#include "Shape.h"
#include "IhasPartialVertices.h"

namespace shape {

	/**
		@brief Représente un Rectangle.

		Un Rectangle est défini par son sommet superieur gauche, une longueur et une largeur. 
	*/
	class Rectangle : public Shape, public IhasPartialVertices {
	private:
		/** @brief La longueur. */
		double width;

		/** @brief La largeur. */
		double height;
	public:
		/** @brief Le constructeur per défaut. */
		Rectangle();

		/** @brief Le constructeur par valeurs. */
		Rectangle(const Vector2D& topLeft, const shared_ptr<const Color>& couleur, double width, double height);

		/** @brief Le destructeur. */
		virtual ~Rectangle();

		/** @brief Accesseur sur la longueur. */
		const double getWidth() const;

		/** @brief Accesseur sur la largeur. */
		const double getHeight() const;

		/** @brief Accesseur sur le sommet superieur gauche. */
		Vector2D getTopLeft() const;

		/** @see IhasPartialVertices.getCurrentVertices() */
		vector<Vector2D> getCurrentVertices() const;

		/** @brief Implémentation de la methode accept du DP Visitor. */
		string* accept(Visitor* v);
<<<<<<< HEAD
=======

		/** @brief Retourne le nom de la classe. */
		string getName() const;

		/** @brief Surcharge de l'opérateur string. */
		operator string() const;

		/** @brief Suppression du remplacement de tableau de sommets. */
		void setVertices(const vector<Vector2D>& sommets) = delete;

		/** @brief Suppression de l'opérateur +. */
		Shape operator+(const Vector2D & vecteur) = delete;

		/** @brief Suppression de l'opérateur --. */
		Shape operator--() = delete;
>>>>>>> bafa4096d91de08c21b782d05e28f0a16617a716
	};
}