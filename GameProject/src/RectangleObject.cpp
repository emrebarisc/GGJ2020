#include "RectangleObject.h"



RectangleObject::RectangleObject()
{
	topLeft = topRight = bottomLeft = bottomRight = nullptr;
}


RectangleObject::~RectangleObject()
{
}

bool RectangleObject::CheckRepaired()
{
	return topLeft != nullptr && topRight != nullptr && bottomLeft != nullptr && bottomRight != nullptr;
}

void RectangleObject::AddPartToRectangle(MovableObject* part)
{
	switch (part->GetType()) {
	case 0:
		if (bottomLeft == nullptr) {
			bottomLeft = dynamic_cast<RectanglePart*>(part);
		}
		break;
	case 1:
		if (bottomRight == nullptr) {
			bottomRight = dynamic_cast<RectanglePart*>(part);
		}
		break;
	case 2:
		if (topLeft == nullptr) {
			topLeft = dynamic_cast<RectanglePart*>(part);
		}
		break;
	case 3:
		if (topRight == nullptr) {
			topRight = dynamic_cast<RectanglePart*>(part);
		}
		break;
	}
	if (CheckRepaired())
		std::cout << "YEYYYYY" << std::endl;
}
