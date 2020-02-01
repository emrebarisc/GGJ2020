#include "RectangleObject.h"



RectangleObject::RectangleObject()
{		
}


RectangleObject::~RectangleObject()
{
}

bool RectangleObject::CheckRepaired()
{
	return topLeft != nullptr && topRight != nullptr && bottomLeft != nullptr && bottomRight != nullptr;
}

void RectangleObject::AddPartToRectangle(RectanglePart* part)
{
	switch (part->GetType()) {
	case 0:
		if(topLeft == nullptr)
			topLeft = part;
		break;
	case 1:
		if (topRight == nullptr)
			topRight = part;
		break;
	case 2:
		if (bottomLeft == nullptr)
			bottomLeft = part;
		break;
	case 3:
		if (bottomRight == nullptr)
			bottomRight = part;
		break;
	}
}
