#include "stdafx.h"
#include "Rectangles.h"
#include "Visitor.h"

Rectangles::Rectangles() : Shape(), width(10), height(10) { vertices.push_back(Vector2D()); }

Rectangles::Rectangles(const Vector2D& v) : Rectangles() { vertices.push_back(v); }

Rectangles::Rectangles(const Vector2D& v, const short unsigned int width, const short unsigned int height, const shared_ptr<const Color>& c) :
	Shape(v, c), width(width), height(height) {};

Rectangles::Rectangles(const Rectangles& obj) : Shape(obj), width(obj.width), height(obj.height) {}

Rectangles::~Rectangles() {}

const short unsigned int Rectangles::getWidth() const { return width; }

const short unsigned int Rectangles::getHeight() const { return height; }

string* Rectangles::accept(Visitor* v) { v->visit(this); }

string Rectangles::getName() const { return "Rectangle"; }

void Rectangles::setWidth(const unsigned short int w) { width = w; }

void Rectangles::setHeight(const unsigned short int h) { height = h; }

void Rectangles::setVertices(const vector<Vector2D>& sommets) {
	if (sommets.size() != 1) throw Erreur(-1, "Rectangle only need 1 Origin.");
	Shape::setVertices(sommets);
}

void Rectangles::setOrigin(const Vector2D& v) { vertices[0] = v; }

Rectangles::operator string() const {
	ostringstream oss;
	oss << Shape::operator std::string() << " Width :" << width << " Height :" << height;
	return oss.str();
}