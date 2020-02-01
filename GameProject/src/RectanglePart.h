#pragma once
#include "MovableObject.h"

class MeshComponent;

class RectanglePart : public MovableObject
{
public:
	RectanglePart();
	~RectanglePart();

private:
	MeshComponent* meshComponent_;
};

