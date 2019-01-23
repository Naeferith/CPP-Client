#include "stdafx.h"
#include "Color.h"

const map<string, const Color> Color::colors = {
	make_pair("BLACK" , Color(0,0,0)),
	make_pair("BLUE"  , Color(0,0,1)),
	make_pair("CYAN"  , Color(0,1,1)),
	make_pair("GREEN" , Color(0,1,0)),
	make_pair("RED"   , Color(1,0,0)),
	make_pair("YELLOW", Color(1,1,0))
};

const Color Color::retrieveDefaultColor(const double r, const double g, const double b) {
	for (auto color : colors) {
		if (color.second.x == r && color.second.y == g && color.second.z == b) return color.second;
	}
	return colors.at("BLACK");
}

const Color Color::retrieveDefaultColor(const string& name) {
	auto it = colors.find(name);
	return (it != colors.end()) ? colors.find(name)->second : colors.at("BLACK");
}

Color::operator string() const {
	ostringstream oss;
	oss << "R:" << x << ", G:" << y << ", B:" << z;
	return oss.str();
}