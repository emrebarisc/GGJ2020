#include "Rectangle.h"



Rectangle::Rectangle()
{		
}


Rectangle::~Rectangle()
{
}

void Rectangle::AddPartToRectangle(RectanglePart* part)
{
	switch (part->GetType()) {
	case 0:
		if(topLeft == NULL)
			topLeft = part;
		break;
	case 1:
		if (topRight == NULL)
			topRight = part;
		break;
	case 2:
		if (bottomLeft == NULL)
			bottomLeft = part;
		break;
	case 3:
		if (bottomRight == NULL)
			bottomRight = part;
		break;
	}
}
