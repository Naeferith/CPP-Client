#pragma once

#include <memory>
#include "Color.h"

class ShapeGroup;
class Visitor;

/**
	@brief Représente un element graphique.

	Un Drawable représente tout objet dessinable sur l'écran de dessin. Il est défini par une couleur.
*/
class Drawable {
private:
	static int indexId;

	/** @brief Groupe auquel appartient le Drawable. */
	ShapeGroup* group = NULL;

protected:
	/** @brief La couleur. */
	shared_ptr<const Color> color;

	int id;

public:
	/** @brief Le constructeur par défaut. */
	Drawable();

	/** @brief Le constructeur par valeurs. */
	Drawable(const shared_ptr<const Color>& couleur);

	/** @brief Le constructeur par référence. */
	Drawable(const Drawable& drawable);

	/** @brief Le destructeur. */
	virtual ~Drawable();

	/** @brief Accesseur sur color. */
	const shared_ptr<const Color>& getColor() const;

	/** @brief Accesseur de group. */
	ShapeGroup* getGroup();

	/** @brief Accesseur sur l'id. */
	const int getId() const;

	void setId(const int Id);

	/** @brief Muttateur sur color. */
	virtual void setColor(const shared_ptr<const Color>& couleur) = 0;

	/** @brief Muttateur de group. */
	void setGroup(ShapeGroup* grp);

	/** @brief Retourne le determinant. */
	static double Det(const Vector2D&, const Vector2D&, const Vector2D&);

	/** @brief Retourne l'aire du Drawable. **/
	virtual double Area() const = 0;

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

	/** @brief Retourne le nom de la classe. */
	virtual string getName() const = 0;

	virtual string* accept(Visitor* v) = 0;

	/** @brief Surcharge de l'opérateur ==. */
	virtual bool operator==(const Drawable& drawable) const;

	/** @brief Surcharge de l'opérateur =. */
	virtual const Drawable& operator=(const Drawable& drawable);

	/** @brief Surcharge de l'opérateur String.*/
	virtual operator string() const = 0;

	/** @brief Surcharge de l'opérateur <<. */
	friend ostream& operator<<(ostream& strm, const Drawable& v);
};