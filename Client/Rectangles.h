#pragma once
#include "Shape.h"

using namespace std;

/**
	@brief Repr�sente un cercle.

	Un Circle est une Shape particuli�re d�fini par un rayon.
*/
class Rectangles : public Shape {
private:

	/** @brief Le rayon du cercle. */
	short int width;
	short int height;

public:
	/** @brief Le constructeur par d�faut. */
	Rectangles();

	/** @brief Le constructeur par Vecteur. */
	Rectangles(const Vector2D&);

	/** @brief Le constructeur par Vecteur et couleur. */
	Rectangles(const Vector2D& v, const shared_ptr<const Color>& couleur);

	/** @brief Le constructeur par valeurs. */
	Rectangles(const Vector2D&, const short int width,const short int height, const shared_ptr<const Color>& couleur);

	/** @brief Le constructeur par r�f�rence. */
	Rectangles(const Rectangles&);

	/** @brief Le destructeur. */
	~Rectangles();

	/** @brief Accesseur de width. */
	const short int getWidth() const;

	/** @brief Accesseur de height. */
	const short int getHeight() const;

	/** @brief Impl�mentation de la methode accept du DP Visitor. */
	string* accept(Visitor* v);

	/** @brief Retourne le nom de la classe. */
	string getName() const;

	/** @brief Mutateur de width. */
	void setWidth(const short int);

	/** @brief Mutateur de height. */
	void setHeight(const short int);

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