#pragma once

#include <exception>
#include <string>

using namespace std;

/**
	@brief Exception basique.
*/
class Erreur : public exception {
private:
	/** @brief Texte de l'erreur. */
	string errorLabel;

	/** @brief Code d'erreur. */
	int errorCode;

public:
	/** @brief Le constructeur par valeurs. */
	Erreur(int code, const string& label) throw();

	/** @brief Le destructeur. */
	virtual ~Erreur() throw();

	/** @brief Acceseur de errorLabel. */
	virtual const char* what() const throw();
};