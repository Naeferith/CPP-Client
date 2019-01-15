#pragma once
#include <Ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

/**
	@brief Singleton de WSA

	C'est un singleton qui initialise une seul fois les DLL WSA avec
	une instance unique statique
*/
class SingletonWSA {
private:
	/** @brief Instance singleton. */
	static SingletonWSA* instance;

	/** @brief Le constructeur par défaut. */
	SingletonWSA();

public:
	/** @brief Le destructeur par défaut. */
	~SingletonWSA();

	/** @brief Accesseur de l'instance unique. Il permet l'initialisation de l'instance
		Si celle-ci n'a pas déja été faite. Notez qu'une fonction static peut être appellé
		Sans nécessairement instancier la classe. SingletonWSA::getInstance() est légal*/
	static const SingletonWSA* getInstance();

	/** @brief Libère la mémoire de l'allocation des DLL WSA et détruit l'instance. */
	static void close();

};