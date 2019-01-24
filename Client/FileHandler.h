#pragma once

#include "NodeInterface.h"

/**
	@brief Classe de gestion d'import et d'export des fichiers.
*/
class FileHandler {
private:
	/** @brief Chemin du fichier. */
	static string path;

	/** @brief Ordre des maillons de la chaine. */
	static NodeInterface* chain;
	
	/** 
		@brief Chargement d'un fichier DOM équivalent. 
		@param doc Le tinyxml2::XMLDocument à parser.
		@see FileHandler.load(const string& name)
		@see FileHandler.load(tinyxml2::XMLDocument* doc)
	*/
	static void _load(tinyxml2::XMLDocument& doc);

public:
	/** 
		@brief Sauvegarde des formes dans un fichier. 
		@param name Le nom du fichier de sortie.
	*/
	static void save(const string& name);

	/** 
		@brief Chargement des formes selon un fichier. 
		@param name Le nom du fichier à charger.
	*/
	static void load(const string& name);

	/**
		@brief Chargement d'un fichier selon un DOM.
		@param doc Le tinyxml2::XMLDocument à charger.
	*/
	static void load(tinyxml2::XMLDocument* doc);

	/**
		@brief Chargement individuellement les formes contenues dans u ShapeGroup.
		@param doc Le tinyxml2::XMLDocument source.
	*/
	static void loadShapeGroupFromXML(tinyxml2::XMLDocument& doc);
};