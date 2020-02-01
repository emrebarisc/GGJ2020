#pragma once
#include "RectanglePart.h"

class Rectangle
{
public:
	Rectangle();
	~Rectangle();

private:
	RectanglePart* topLeft;
	RectanglePart* topRight;
	RectanglePart* bottomLeft;
	RectanglePart* bottomRight;

	void AddPartToRectangle(RectanglePart* part);
};

