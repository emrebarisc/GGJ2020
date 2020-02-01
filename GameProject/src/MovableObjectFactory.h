#pragma once
#include "RectanglePart.h"
#include "MovableObject.h"

class MovableObjectFactory
{
public:
	static MovableObjectFactory* GetInstance();
	MovableObject* CreateMovableObject(int type);

private:
	MovableObjectFactory();
	~MovableObjectFactory();
	static MovableObjectFactory* instance_;
};

