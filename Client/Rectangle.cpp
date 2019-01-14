#include "stdafx.h"
#include "Rectangle.h"

using namespace shape;

<<<<<<< HEAD
Rectangle::Rectangle() : Shape(), width(0), height(0) {}
=======
Rectangle::Rectangle() : Shape(), width(0), height(0) {
	vertices.reserve(1);
}
>>>>>>> bafa4096d91de08c21b782d05e28f0a16617a716

shape::Rectangle::Rectangle(const Vector2D & topLeft, const shared_ptr<const Color>& couleur, double width, double height) : Shape(vector<Vector2D>(), couleur), width(width), height(height) {
	vertices.reserve(1);
	vertices.emplace_back(topLeft.x, topLeft.y);
}

Rectangle::~Rectangle() {}

const double shape::Rectangle::getWidth() const { return width; }

const double shape::Rectangle::getHeight() const { return height; }

Vector2D shape::Rectangle::getTopLeft() const { return vertices.at(0); }

<<<<<<< HEAD
=======
string Rectangle::getName() const { return "rectangle"; }

>>>>>>> bafa4096d91de08c21b782d05e28f0a16617a716
vector<Vector2D> Rectangle::getCurrentVertices() const {
	Vector2D topLeft = getTopLeft();
	
	vector<Vector2D> currentVertices = {
		topLeft,
		Vector2D(topLeft.x        , topLeft.y + height),
		Vector2D(topLeft.x + width, topLeft.y + height),
		Vector2D(topLeft.x + width, topLeft.y),
	};
	
	Shape temp = Shape(currentVertices, make_shared<const Color>(Color::BLACK));
	temp.Rotate(topLeft, rotationAngle);

	return temp.getVertices();
}

string * Rectangle::accept(Visitor * v) { return v->visit(this); }
<<<<<<< HEAD
=======

Rectangle::operator string() const {
	stringstream oss;
	oss << Shape::operator string() << " Width :" << getWidth() << " Height :" << getHeight();
	return oss.str();
}
>>>>>>> bafa4096d91de08c21b782d05e28f0a16617a716
