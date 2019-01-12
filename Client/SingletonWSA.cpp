#include "stdafx.h"
#include "SingletonWSA.h"

//Unique initialisation de l'instance � NULL
SingletonWSA* SingletonWSA::instance = NULL;

SingletonWSA::SingletonWSA() {
	
	// Initialisation unique de la librairie winsock.
	WSADATA wsaData;

	if (WSAStartup(MAKEWORD(2, 0), &wsaData)) throw Erreur(WSAGetLastError(),"Failed initializing Winsock2");
	/* MAKEWORD(2,0) sert � indiquer la version de la librairie � utiliser : 1 pour winsock et 2 pour winsock2
	   en cas de succ�s, wsaData a �t� initialis�e et l'appel a renvoy� la valeur 0. */
}

SingletonWSA::~SingletonWSA() {
	//Si l'instance a bien �t� cr�e pr�c�dement on lib�re les librairies init.
	if (instance != NULL) { WSACleanup(); instance = NULL; }
}

const SingletonWSA* SingletonWSA::getInstance() {
	//Initialisation de l'instance unique. 
	if (instance == NULL) { instance = new SingletonWSA(); }
	
	return instance;
}

void SingletonWSA::close() {
	//Suppr�ssion de l'objet et r�inisialisation de l'instance unique.
	delete(instance);
}