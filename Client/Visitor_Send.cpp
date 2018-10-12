#include "stdafx.h"
#include "Visitor_Send.h"
#include "SingletonSocket.h"

void Visitor_Send::visit(Drawable * vd) {
	cout << "je suis un putain de drawable" << endl;
}

void Visitor_Send::visit(Shape * vs) {
	cout << "je suis un putain de shape" << endl;
}

void Visitor_Send::visit(Circle * vc) {
	SingletonSocket socket = SingletonSocket::getInstance();
	string str = vc->Draw() + "\r\n";
	const char * requete = str.c_str();
	int l = strlen(requete);

	int r = send(socket.getSocket(), requete, l, 0);

	if (r == SOCKET_ERROR) throw - 4;
}
