#include "stdafx.h"
#include "ShapeManager.h"

ShapeManager* ShapeManager::instance = nullptr;

ShapeManager::ShapeManager() {
	shapes = {};
}

ShapeManager::~ShapeManager() {}

ShapeManager* ShapeManager::getInstance() {
	if (instance == nullptr) instance = new ShapeManager();
	return instance; 
}

const std::vector<Drawable*> ShapeManager::getShapes() { return getInstance()->shapes; }

ShapeManager* ShapeManager::operator+(Drawable* drawable) {
	shapes.push_back(drawable);
	return instance;
}

string * ShapeManager::accept(Visitor * v) { return v->visit(this); }
