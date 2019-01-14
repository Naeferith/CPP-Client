#include "stdafx.h"
#include "ShapeManager.h"

ShapeManager* ShapeManager::instance = nullptr;

ShapeManager::ShapeManager() {
	//shapes = {};
}

ShapeManager::~ShapeManager() {}

ShapeManager* ShapeManager::getInstance() { return (instance == nullptr) ? new ShapeManager() : instance; }

const std::map<int, Drawable*> ShapeManager::getShapes() const { return shapes; }

ShapeManager* ShapeManager::operator+(Drawable* drawable) {
	shapes.insert(std::make_pair(keyIndex, drawable));
	keyIndex++;
	return instance;
}

string * ShapeManager::accept(Visitor * v) { return v->visit(this); }
