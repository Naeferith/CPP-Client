#include "stdafx.h"
#include "Visitor_Send.h"
#include "SingletonSocket.h"

void Visitor_Send::visit(Drawable * vd) {
}

void Visitor_Send::visit(Shape * vs) {
	SingletonSocket socket = SingletonSocket::getInstance();
	string str = vs->Draw() + "\r\n";
	const char * requete = str.c_str();
	int l = strlen(requete);

	socket.Send(requete, l);
}

void Visitor_Send::visit(Circle * vc) {
	SingletonSocket socket = SingletonSocket::getInstance();
	string str = vc->Draw() + "\r\n";
	const char * requete = str.c_str();
	int l = strlen(requete);

	socket.Send(requete, l);
}