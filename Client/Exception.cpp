#include "stdafx.h"
#include "Exception.h"

int Exception::Erreur(const string erreur) {
	cout << erreur << endl;
	//exit(-1);
	return -1;
}

int Exception::Erreur(const string erreur, const int code) {
	cout << erreur << endl;
	exit(code);
	return code;
}
