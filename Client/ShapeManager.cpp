#include "stdafx.h"
#include "ShapeManager.h"

ShapeManager* ShapeManager::instance = nullptr;

ShapeManager::ShapeManager() {}

ShapeManager::~ShapeManager() {}

ShapeManager* ShapeManager::getInstance() { return (instance == nullptr) ? new ShapeManager() : instance; }

const std::vector<Drawable*> ShapeManager::getShapes() const { return shapes; }

ShapeManager* ShapeManager::operator+(Drawable* drawable) {
	shapes.push_back(drawable);
	return instance;
}

string * ShapeManager::accept(Visitor * v) { return v->visit(this); }
