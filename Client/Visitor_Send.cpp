#include "stdafx.h"
#include "Visitor_Send.h"
#include "SingletonSocket.h"

void Visitor_Send::visit(Shape * vs) {
	SingletonSocket socket = SingletonSocket::getInstance();
	string str = vs->Draw() +"\r\n";
	socket.Send(str.c_str());
}