#pragma once

#include "Color.h"

class Visitor;

/**
	@brief Représente un element graphique.

	Un Drawable représente tout objet dessinable sur l'écran de dessin. Il est défini par une couleur.
*/
class Drawable {
protected:
	/** @brief La couleur. */
	const Color* color;

public:
	/** @brief Le constructeur par défaut. */
	Drawable();

	/** @brief Le constructeur par valeurs. */
	Drawable(const Color* couleur);

	/** @brief Le constructeur par référence. */
	Drawable(const Drawable& drawable);

	/** @brief Le destructeur. */
	~Drawable();

	/** @brief Accesseur sur color. */
	const Color getColor() const;

	/** @brief Muttateur sur color. */
	virtual void setColor(const Color* couleur) = 0;

	/**
		@brief Applique une translation.
		@param vecteur Le vecteur de translation.
	*/
	virtual void Translate(const Vector2D& vecteur) = 0;

	/**
		@brief Applique une mise à l'échelle.
		@param point Le point invariant.
		@param ratio Le ratio d'échelle.
	*/
	virtual void Scale(const Vector2D& point, const double ratio) = 0;

	/**
		@brief Applique une rotation.
		@param point Le point invariant.
		@param angle L'angle de rotation en radians.
	*/
	virtual void Rotate(const Vector2D& point, const double angle) = 0;

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const Drawable& drawable) const;

	/** @brief Surcharge de l'opérateur =. */
	const Drawable& operator=(const Drawable& drawable);

	/** @brief Implémentation de la methode accept du DP Visitor. */
	virtual void accept(Visitor* v);
};