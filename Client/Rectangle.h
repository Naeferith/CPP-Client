#pragma once
#include "Shape.h"

using namespace std;

/**
	@brief Repr�sente un cercle.

	Un Circle est une Shape particuli�re d�fini par un rayon.
*/
class Rectangle : public Shape {
private:

	/** @brief Le rayon du cercle. */
	short unsigned int width;
	short unsigned int height;

public:
	/** @brief Le constructeur par d�faut. */
	Rectangle();

	/** @brief Le constructeur par Vecteur. */
	Rectangle(const Vector2D&);

	/** @brief Le constructeur par valeurs. */
	Rectangle(const Vector2D&, const short unsigned int width,const short unsigned int height, const shared_ptr<const Color>& couleur);

	/** @brief Le constructeur par r�f�rence. */
	Rectangle(const Rectangle&);

	/** @brief Le destructeur. */
	~Rectangle();

	/** @brief Accesseur de width. */
	const short unsigned int getWidth() const;

	/** @brief Accesseur de height. */
	const short unsigned int getHeight() const;

	/** @brief Impl�mentation de la methode accept du DP Visitor. */
	string* accept(Visitor* v);

	/** @brief Retourne le nom de la classe. */
	string getName() const;

	/** @brief Mutateur de width. */
	void setWidth(const unsigned short int);

	/** @brief Mutateur de height. */
	void setHeight(const unsigned short int);

	/** @brief Remplace le tableau de sommets. */
	void setVertices(const vector<Vector2D>& sommets);

	/** @brief Change l'origin du rectangle. */
	void setOrigin(const Vector2D&);

	operator string() const;

	/** @brief Suppression de l'op�rateur +. */
	Shape operator+(const Vector2D & vecteur) = delete;

	/** @brief Suppression de l'op�rateur --. */
	Shape operator--() = delete;
};