#pragma once
class Figure {
protected:
	char symbol;
public:
	Figure(char symbol = '*')
		: symbol(symbol)
	{
	}


	void setSymbol(char sym) {
		symbol = sym;
	}

	virtual void draw() const = 0;      // Pure virual function
};