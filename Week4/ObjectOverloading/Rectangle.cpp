#include "Rectangle.h"
#include <string>
#include <iostream>



// Implementatie
void Rectangle::draw() const {
	// Maak een regel met symbolen, gescheiden door een spatie
	// Bijvoorbeeld:
	// * * * * * * * * *
	std::string line;
	for (int k = 0; k < width; ++k) {
		line += symbol;
		line += ' ';
	}
	// Zet de zojuist gemaakte regels onder elkaar
	for (int r = 0; r < height; ++r) {
		std::cout << line << '\n';
	}
}

int Rectangle::surface() const {
	return width * height;
}