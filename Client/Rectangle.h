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

		/** @brief Rotation de la forme. */
		double rotationAngle = 0;
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

		/** @brief Accesseur sur color. */
		const double getRotationAngle() const { return rotationAngle; }

		/** @see IhasPartialVertices.getCurrentVertices() */
		vector<Vector2D> getCurrentVertices() const;

		/** @brief Retourne l'aire du Drawable. **/
		virtual double Area() const;

		/**	@see Drawable.Scale() */
		void Scale(const Vector2D& point, const double ratio);

		/**	@see Drawable.Rotate() */
		virtual void Rotate(const Vector2D& point, const double angle);

		/** @brief Implémentation de la methode accept du DP Visitor. */
		string  accept(Visitor* v);

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
	};
}