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
	void setColor(const Color* couleur);

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const Drawable& drawable) const;

	/** @brief Surcharge de l'opérateur =. */
	const Drawable& operator=(const Drawable& drawable);

	/** @brief Implémentation de la methode accept du DP Visitor. */
	virtual void accept(Visitor* v);
};



