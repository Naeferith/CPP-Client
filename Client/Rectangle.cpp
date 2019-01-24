#include "stdafx.h"
#include "Rectangle.h"

using namespace shape;

Rectangle::Rectangle() : Shape(), width(0), height(0) {
	vertices.reserve(1);
}

Rectangle::Rectangle(const Vector2D & topLeft, const shared_ptr<const Color>& couleur, double width, double height) : Shape(vector<Vector2D>(), couleur), width(width), height(height) {
	vertices.reserve(1);
	vertices.emplace_back(topLeft.x, topLeft.y);
}

Rectangle::~Rectangle() {}

const double Rectangle::getWidth() const { return width; }

const double Rectangle::getHeight() const { return height; }

Vector2D Rectangle::getTopLeft() const { return vertices.at(0); }

string Rectangle::getName() const { return "rectangle"; }

vector<Vector2D> Rectangle::getCurrentVertices() const {
	Vector2D topLeft = getTopLeft();

	vector<Vector2D> currentVertices = {
		topLeft,
		Vector2D(topLeft.x        , topLeft.y + height),
		Vector2D(topLeft.x + width, topLeft.y + height),
		Vector2D(topLeft.x + width, topLeft.y),
	};
	
	Shape temp = Shape(currentVertices,make_shared<const Color>(Color::retrieveDefaultColor(0,0,0)));
	temp.Rotate(topLeft, rotationAngle);

	return temp.getVertices();
}

Rectangle& Rectangle::Rotate(const Vector2D& point, const double angle) {
	Shape::Rotate(point, angle);
	rotationAngle = fmod(rotationAngle + angle, 2 * MY_PI);
	return *this;
}

double Rectangle::Area() const {
	Vector2D a = getTopLeft(),
			b = Vector2D(a.x + width, a.y),
			c = Vector2D(a.x, a.y + height),

		ab = b - a,
		ac = c - a;
	return Vector2D::Det(ab, ac);
}

Rectangle& Rectangle::Scale(const Vector2D & point, const double ratio) {
	Shape::Scale(point, ratio);
	width  *= ratio;
	height *= ratio;
	return *this;
}

string  Rectangle::accept(Visitor * v) { return v->visit(this); }

Rectangle::operator string() const {
	stringstream oss;
	oss << Shape::operator string() << " Width :" << getWidth() << " Height :" << getHeight();
	return oss.str();
}