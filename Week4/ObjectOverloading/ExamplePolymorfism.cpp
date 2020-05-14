// Voorbeeld: Polymorfisme via een referentie
#include <iostream>
#include <string>

#include "Rectangle.h"
#include "Triangle.h"


// Functie met een referentie als argument
void drawFigure(Figure &f) {
	f.draw();

	const Rectangle *pRechthoek = dynamic_cast<Rectangle *>(&f);
	if (pRechthoek != nullptr) {
		std::cout << pRechthoek->surface() << '\n';
	}
	else {
		std::cout << "figure at address: " << &f << " is not a rectangle \n";
	}
}

int main() {
	Rectangle rh{ 6, 2 };
	Triangle dh{ 5 };
	dh.setSymbol('b');

	drawFigure(rh);
	drawFigure(dh);
}


