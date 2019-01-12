#include "stdafx.h"
#include "Erreur.h"

Erreur::Erreur(int code, const string & label) throw() : errorCode(code), errorLabel(label) {}

Erreur::~Erreur() throw() {}

const char* Erreur::what() const throw() { return errorLabel.c_str(); }
