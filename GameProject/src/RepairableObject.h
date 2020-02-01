#pragma once
class RepairableObject
{
public:
	RepairableObject();
	~RepairableObject();

	virtual bool CheckRepaired() = 0;
};

