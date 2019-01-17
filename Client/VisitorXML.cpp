#include "stdafx.h"
#include "VisitorXML.h"
#include "SocketInOut.h"
#include "SingletonWSA.h"

#include <memory>
#include <map>

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

string VisitorXML::strColor(const shared_ptr<const Color>& col) const {
	stringstream oss;
	oss <<
		"<color>" <<
			"<r>" <<
				col->x <<
			"</r>" <<
			"<g>" <<
				col->y <<
			"</g>" <<
			"<b>" <<
				col->z <<
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
	result << 
		"<" << name << " id=\"" << vs->getId() << "\">" << 
			strColor(vs->getColor()) << param <<
		"<vertices>";
			for (auto &vertice : vs->getVertices()) result << strVector(vertice);
	result << 
		"</vertices></" << name << ">";

	return new string(result.str());
}

string VisitorXML::makeMarkup(const string& tagName, const double value) {
	stringstream result;
	result << "<" << tagName << ">" << value << "</" << tagName << ">";
	return result.str();
}

string* VisitorXML::visit(const Shape * vs) const{
	return strXML(vs);
}

string* VisitorXML::visit(const Circle* vs) const {
	stringstream param;
	//Un cercle possède un radius qui n'est pas un sommet. On l'ajoute donc en paramètre.
	param << makeMarkup("radius", vs->getRadius());

	return strXML(vs, param.str());
}

string * VisitorXML::visit(const shape::Rectangle * vs) const {
	Shape* rectangularShape = new Shape(vs->getCurrentVertices(), shared_ptr<const Color>(vs->getColor()));
	rectangularShape->setId(vs->getId());
	return strXML(rectangularShape);
}

string * VisitorXML::visit(const ShapeGroup * vs) const
{
	stringstream oss;
	string *str, name = vs->getName();
	oss << "<" << name << ">";
	for (auto &shape : vs->getShapes()) {
		str = shape->accept(new VisitorXML);
		oss << *str;
		delete(str);
	}
	oss << "</" << name << ">";
	return new string(oss.str());
}

string * VisitorXML::visit(const ShapeManager * vs) const {
	stringstream XMLS;
	string suffix;
	vector<shared_ptr<Drawable>> m = vs->getShapes();
	for (auto s : m) {
		
		suffix = (s == m.back()) ? "" : "\r\n";
		XMLS << *s->accept(new VisitorXML) << suffix;
	}
	return new string(XMLS.str());
}
