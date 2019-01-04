#include "stdafx.h"
#include "Visitor_Send.h"
#include "SocketInOut.h"
#include "SingletonWSA.h"

void Visitor_Send::visit(Shape * vs) {
	SingletonWSA::getInstance();
	SocketInOut socket;
	string str = vs->Draw() + "\r\n";
	socket.Send(str.c_str());
}