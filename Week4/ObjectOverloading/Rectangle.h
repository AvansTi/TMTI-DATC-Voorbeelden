#pragma once

#include "Figure.h"

class Rectangle : public Figure {
private:
	int width, height;
public:
	Rectangle(int width, int height)
		: width(width), height(height)
	{
	};

	void draw() const;
	int surface() const;
};
