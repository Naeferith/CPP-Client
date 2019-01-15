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

	/** @brief Le constructeur par d�faut. */
	SingletonWSA();

public:
	/** @brief Le destructeur par d�faut. */
	~SingletonWSA();

	/** @brief Accesseur de l'instance unique. Il permet l'initialisation de l'instance
		Si celle-ci n'a pas d�ja �t� faite. Notez qu'une fonction static peut �tre appell�
		Sans n�cessairement instancier la classe. SingletonWSA::getInstance() est l�gal*/
	static const SingletonWSA* getInstance();

	/** @brief Lib�re la m�moire de l'allocation des DLL WSA et d�truit l'instance. */
	static void close();

};