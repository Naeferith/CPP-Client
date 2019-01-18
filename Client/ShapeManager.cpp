#include "stdafx.h"
#include "ShapeManager.h"

ShapeManager* ShapeManager::instance = nullptr;

ShapeManager::ShapeManager() {}

ShapeManager::~ShapeManager() {}

ShapeManager* ShapeManager::getInstance() {
	if (instance == nullptr) instance = new ShapeManager();
	return instance; 
}

string  ShapeManager::accept(Visitor * v) { return v->visit(shared_ptr<ShapeManager>(this)); }
