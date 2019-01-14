#pragma once

class FileHandler {
private:
	static string path;

public:
	static void save(const string& name);
	static void load(const string& name);
};

class XMLInterpreter {

};