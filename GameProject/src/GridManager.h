#ifndef __GRIDMANAGER_H__
#define __GRIDMANAGER_H__

#include "Goknar/Math.h"

#include <functional>

class MovableObject;

class GridManager
{
public:
	static GridManager* GetInstance()
	{
		if (instance_ == nullptr)
		{
			instance_ = new GridManager();
		}

		return instance_;
	}

	void PrintGridManager() const;

	void NotifyGridManager(MovableObject* caller, const Vector3& worldPosition);
	bool IsGridEmpty(const Vector3& worldPosition);

private:
	GridManager();
	~GridManager();

	Vector2i ConvertWorldPositionToGridPosition(const Vector3& worldPosition);

	void SetGridPosition(MovableObject* caller, const Vector2i& gridPosition);

	static GridManager* instance_;

	MovableObject*** grid_;

	int gridWidth_;
	int gridHeight_;
};

#endif