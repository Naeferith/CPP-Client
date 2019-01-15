#pragma once

class FileHandler {
public:
	static string filePath(const string& name);
	static void save(const string& name);
	static void load(const string& name);
};

class XMLInterpreter {};