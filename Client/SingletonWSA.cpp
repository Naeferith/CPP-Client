#include "stdafx.h"
#include "SingletonWSA.h"

//Unique initialisation de l'instance à NULL
SingletonWSA* SingletonWSA::instance = NULL;

SingletonWSA::SingletonWSA() {
	
	// Initialisation unique de la librairie winsock.
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData)) throw Erreur(WSAGetLastError(),"Failed initializing Winsock2");
	/* MAKEWORD(2,0) sert à indiquer la version de la librairie à utiliser : 1 pour winsock et 2 pour winsock2
	   en cas de succès, wsaData a été initialisée et l'appel a renvoy à la valeur 0. */
}

SingletonWSA::~SingletonWSA() {
	//Si l'instance a bien été crée précédement on libère les librairies init.
	if (instance != NULL) { WSACleanup(); instance = NULL; }
}

const SingletonWSA* SingletonWSA::getInstance() {
	//Initialisation de l'instance unique. 
	if (instance == NULL) { instance = new SingletonWSA(); }
	
	return instance;
}

void SingletonWSA::close() {
	//Suppression de l'objet et réinisialisation de l'instance unique.
	delete(instance);
}
