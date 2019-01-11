#pragma once
#include "Shape.h"

using namespace std;

/**
	@brief Représente un cercle.

	Un Circle est une Shape particulière défini par un rayon.
*/
class Rectangles : public Shape {
private:

	/** @brief La rotation du rectange. */
	double rotation;
	Vector2D rotationCenter;

public:
	/** @brief Le constructeur par défaut. */
	Rectangles();

	/** @brief Le constructeur par valeurs. */
	Rectangles(const vector<Vector2D>&, const shared_ptr<const Color>& couleur);

	/** @brief Le constructeur par référence. */
	Rectangles(const Rectangles&);

	/** @brief Le destructeur. */
	~Rectangles();

	/** @brief Accesseur de width. */
	const Vector2D& getUpLeft() const;

	/** @brief Accesseur de height. */
	const Vector2D& getDownRight() const;

	/** @brief Accesseur de rotation. */
	const double getRotation() const;

	/** @brief Retourne les sommets après rotations. */
	const vector<Vector2D> getVertices() const;

	/** @brief Accesseur du centre de rotation. */
	const Vector2D& getRotationCenter() const;

	/** @brief Retourne le centre du rectangle. */
	Vector2D getCenter() const;

	/** @brief Implémentation de la methode accept du DP Visitor. */
	string* accept(Visitor* v);

	/** @brief Retourne le nom de la classe. */
	string getName() const;

	/** @brief Mutateur de width. */
	void setUpLeft(const Vector2D&);

	/** @brief Mutateur de height. */
	void setDownRight(const Vector2D&);

	/** @brief Mutateur de rotation. */
	void setRotation(const double);

	/** @brief Mutateur du centre de rotation. */
	void setRotationCenter(const Vector2D& v);

	/** @brief Remplace le tableau de sommets. */
	void setVertices(const vector<Vector2D>& sommets);

	/**	@see Drawable.Rotate() */
	void Rotate(const Vector2D& point, const double angle);

	/** @brief Surcharge de l'opérateur String. */
	//operator string() const;

	/** @brief Suppression de l'opérateur +. */
	Shape operator+(const Vector2D & vecteur) = delete;

	/** @brief Suppression de l'opérateur --. */
	Shape operator--() = delete;
};