#pragma once
#include "RectanglePart.h"
#include "RepairableObject.h"

class RectangleObject : public RepairableObject
{
public:
	RectangleObject();
	~RectangleObject();

private:
	RectanglePart* topLeft;
	RectanglePart* topRight;
	RectanglePart* bottomLeft;
	RectanglePart* bottomRight;

	void AddPartToRectangle(RectanglePart* part);
	bool CheckRepaired();
};

