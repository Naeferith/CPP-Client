#include "stdafx.h"
#include "Rectangles.h"
#include "Visitor.h"

Rectangles::Rectangles() : Shape(), width(10), height(10) { vertices.push_back(Vector2D()); }

Rectangles::Rectangles(const Vector2D& v) : Rectangles() { vertices.push_back(v); }

Rectangles::Rectangles(const Vector2D& v, const shared_ptr<const Color>& couleur) : Shape(v,couleur) {}

Rectangles::Rectangles(const Vector2D& v, const short int width, const short int height, const shared_ptr<const Color>& c) :
	Shape(v, c), width(width), height(height) {};

Rectangles::Rectangles(const Rectangles& obj) : Shape(obj), width(obj.width), height(obj.height) {}

Rectangles::~Rectangles() {}

const short int Rectangles::getWidth() const { return width; }

const short int Rectangles::getHeight() const { return height; }

string* Rectangles::accept(Visitor* v) { return v->visit(this); }

string Rectangles::getName() const { return "Rectangle"; }

void Rectangles::setWidth(const short int w) { width = w; }

void Rectangles::setHeight(const short int h) { height = h; }

void Rectangles::setOrigin(const Vector2D& v) { vertices[0] = v; }

Rectangles::operator string() const {
	ostringstream oss;
	oss << Shape::operator std::string() << " Width :" << width << " Height :" << height;
	return oss.str();
}