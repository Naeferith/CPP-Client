#include "stdafx.h"
#include "VisitorXML.h"
#include "SocketInOut.h"
#include "SingletonWSA.h"
#include "Rectangles.h"
#include "Circle.h"
#include "Shape.h"

string VisitorXML::strVector(const Vector2D& vs) const {
	stringstream oss;
	oss	<<
		"<vertice>" <<
			"<x>" <<
				vs.x <<
			"</x>" <<
			"<y>" <<
				vs.y <<
			"</y>" <<
		"</vertice>";
	return oss.str();
}

string VisitorXML::strColor(const Color& col) const {
	stringstream oss;
	oss <<
		"<color>" <<
			"<r>" <<
				col.x <<
			"</r>" <<
			"<g>" <<
				col.y <<
			"</g>" <<
			"<b>" <<
				col.z <<
			"</b>" <<
		"</color>";
	return oss.str();
}

string* VisitorXML::strXML(const Shape* vs, const string& param = "") const {
	stringstream result;
	string name = vs->getName();

	/* Retourne une chaine selon la nomenclature : Name - ID - Color - Param - Vertices
	   Les paramètres sont des attributs propres qui ne sont pas des sommets, comme 
	   le radius du cercle*/
	result << "<" << name << " id=\"" << this << "\">" << strColor(vs->getColor()) << param <<
		"<vertices>";
	for (auto &vertice : vs->getVertices()) result << strVector(vertice);

	result << "</vertices></" << name << ">";

	return new string(result.str());
}

string* VisitorXML::visit(const Shape * vs) const{
	return strXML(vs);
}

string* VisitorXML::visit(const Circle* vs) const {
	stringstream param;
	//Un cercle possède un radius qui n'est pas un sommet. On l'ajoute donc en paramètre.
	param << "<radius>" << vs->getRadius() << "</radius>";

	return strXML(vs, param.str());
}

string* VisitorXML::visit(const Rectangles* vs) const {
	stringstream param;
	//Un rectangle possède une hauteur et une largeur qui n'est pas un sommet. On l'ajoute donc en paramètre.
	param << "<width>" << vs->getWidth() << "</width><height>" << vs->getHeight() << "</height>";

	return strXML(vs, param.str());
}