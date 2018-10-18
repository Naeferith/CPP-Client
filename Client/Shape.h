#pragma once

#include <vector>
#include "Drawable.h"

using namespace std;

/**
	@brief Représente une forme dessinable.

	Une Shape est définie par une collection de sommets.
*/
class Shape : public Drawable {
protected:
	/** @brief La liste des sommets. */
	vector<Vector2D> vertices;

public:
	/** @brief Le constructeur par défaut. */
	Shape();

	/** @brief Le constructeur par valeurs. */
	Shape(vector<Vector2D, allocator<Vector2D>>& sommets, const Color* couleur);
	
	/** @brief Le destructeur. */
	~Shape();

	/** @brief Accesseur pour vertices. */
	const vector<Vector2D> getVertices() const;

	/**	@see Drawable.setColor() */
	void setColor(const Color * c);

	/** @brief Mutateur pour vertices. */
	void setVertices(const vector<Vector2D>& sommets);

	/** @brief Surcharge de l'opérateur ==. */
	bool operator==(const Shape& shape) const;

	/**	@see Drawable.Translate() */
	void Translate(const Vector2D& vecteur);

	/**	@see Drawable.Scale() */
	void Scale(const Vector2D& point, const double ratio);

	/**	@see Drawable.Rotate() */
	void Rotate(const Vector2D& point, const double angle);

	/** @brief Envoie une requete au serveur de dessin. */
	virtual string Draw();

	/** @brief Implémentation de la methode accept du DP Visitor. */
	virtual void accept(Visitor* v);
};