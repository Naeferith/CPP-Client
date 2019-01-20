#pragma once

#include "tinyxml2.h"

using namespace tinyxml2;

/** @brief Classe abstraite représentant un maillon

	Tout maillon représentant un expert de chargement ou d'écriture
	d'une forme dans un fichier devra hériter de cette classe.
	
*/

class NodeInterface {
private:
	/** @brief Prochain maillon de la chaine. */
	NodeInterface* next = nullptr;

protected:
	
	/** @brief La forme chargé par l'expert. */
	Drawable* drawable  = nullptr;

public:
	/** @brief Constructeur par défaut. */
	NodeInterface();

	/** @brief Constructeur par maillon. */
	NodeInterface(NodeInterface* ni);

	virtual ~NodeInterface();

	/** @brief Ajout de la forme au format XML dans le fichier. */
	virtual void executeRequest(tinyxml2::XMLDocument& xml) = 0;

	/** @brief Retourne le nom de la forme contenue. */
	virtual const string getDescription() const;

	/** @brief Retourne le maillon suivant. */
	const NodeInterface* getNext() const;

	/** @brief Tentative de reconnaissance de l'expert
		@param str doit être le nom du Drawable.
	*/
	bool canInterpret(const string& str) const;

	/** @brief Tentative de reconnaissance par le maillon du document XML. */
	void interact(tinyxml2::XMLDocument& xml);

	/** @brief Récupération de la couleur du fichier XML. */
	shared_ptr<const Color> retrieveColor(tinyxml2::XMLDocument& doc);

	/** @brief Récupération des vertices du fichier XML. */
	virtual const vector<Vector2D> retrieveVertices(tinyxml2::XMLDocument& doc);

	/** @brief Récupération du radius du fichier XML. */
	const double retrieveDoubleProperty(tinyxml2::XMLDocument& doc, const string& prop);
};