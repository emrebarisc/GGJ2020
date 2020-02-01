#include "MovableObjectFactory.h"
MovableObjectFactory* MovableObjectFactory::instance_ = nullptr;
MovableObjectFactory* MovableObjectFactory::GetInstance()
{
	if (!instance_)
		instance_ =  new MovableObjectFactory();
	
	return instance_;
}

MovableObject* MovableObjectFactory::CreateMovableObject(int type)
{
	switch (type)
	{
	case 1: 
		return new RectanglePart();
		break;
	default:
		return nullptr;
	}
	
}

MovableObjectFactory::MovableObjectFactory()
{
	instance_ = this;
}


MovableObjectFactory::~MovableObjectFactory()
{
}
