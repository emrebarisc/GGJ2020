#pragma once
#include "MovableObject.h"

class MeshComponent;

class RectanglePart : public MovableObject
{
public:
	RectanglePart();
	~RectanglePart();

private:

	void SetParent(RepairableObject* parent);
	RepairableObject* GetParent();
	MeshComponent* meshComponent_;
};

