#pragma once

#include "NodeInterface.h"

class FileHandler {
private:
	/** @brief Chemin du fichier. */
	static string path;

	/** @brief Ordre des maillons de la chaine. */
	static NodeInterface* chain;
	
	/** @brief Tentative des chargement de l'experts. */
	static void _load(tinyxml2::XMLDocument& doc);

public:
	/** @brief Sauvegarde de la forme dans un fichier. */
	static void save(const string& name);

	/** @brief Chargement des formes d'un fichier. */
	static void load(const string& name);

	/** @brief lancement de l'interprétation par les experts. */
	static void load(tinyxml2::XMLDocument* doc);
	static vector<shared_ptr<Drawable>> loadShapeGroupFromXML(tinyxml2::XMLDocument& doc);
};

class XMLInterpreter {

};