#pragma once

#include "Figure.h"

class Triangle : public Figure {
private:
	int size;
public:
	Triangle(int size)
		: size(size) {
	};
	void draw() const;
};
