#pragma once

#include <exception>
#include <string>

using namespace std;

class Erreur : public exception {
private:
	string errorLabel;
	int errorCode;

public:
	Erreur(int code, const string& label) throw();
	virtual ~Erreur() throw();

	virtual const char* what() const throw();
};