#include "Triangle.h"
#include <string>
#include <iostream>


void Triangle::draw() const {
	// Maak een regel bestaande uit een aantal spaties,
	// gevolgd door een symbool en een spatie, bijvoorbeeld:
	// _______*    (spaties zijn hier weergegeven met _)
	std::string regel;
	for (int k = 0; k < size; ++k)
		regel += ' ';
	regel += symbol;
	regel += ' ';

	// Zet een aantal regels onder elkaar
	for (int r = 0; r < size; ++r) {
		std::cout << regel << '\n';
		// Verwijder het eerste karakter uit de regel
		regel.erase(0, 1);
		// Voeg aan het eind een symbool en een spatie toe
		regel += symbol;
		regel += ' ';
	}


}