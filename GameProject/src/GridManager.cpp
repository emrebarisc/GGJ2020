#include "GridManager.h"

#include "MovableObject.h"

GridManager* GridManager::instance_ = nullptr;

void GridManager::NotifyGridManager(MovableObject* caller, const Vector3& worldPosition)
{
	Vector2i gridPosition = ConvertWorldPositionToGridPosition(worldPosition);
	
	if (gridPosition.y == 0 || grid_[gridPosition.y][gridPosition.x] != nullptr)
	{
		caller->StopMovement();
	}

	//SetGridPosition(caller, gridPosition);
}

bool GridManager::IsGridEmpty(const Vector3& worldPosition)
{
	Vector2i gridPosition = ConvertWorldPositionToGridPosition(worldPosition);

	return 0 <= gridPosition.x && gridPosition.x < gridWidth_ && grid_[gridPosition.y][gridPosition.x] == nullptr;
}

GridManager::GridManager() : gridWidth_(8), gridHeight_(16)
{
	grid_ = new MovableObject**[gridHeight_];

	for (int y = 0; y < gridHeight_; y++)
	{
		grid_[y] = new MovableObject*[gridWidth_];

		for (int x = 0; x < gridWidth_; x++)
		{
			grid_[y][x] = nullptr;
		}
	}
}

GridManager::~GridManager()
{

}

Vector2i GridManager::ConvertWorldPositionToGridPosition(const Vector3& worldPosition)
{
	return Vector2i(mathClamp(floor(worldPosition.x) + 4, -1, gridWidth_), mathClamp(floor(worldPosition.y), -1, gridHeight_));
}

void GridManager::SetGridPosition(MovableObject* caller, const Vector2i& gridPosition)
{
	if (grid_[gridPosition.y - 1][gridPosition.x] == caller)
	{
		grid_[gridPosition.y - 1][gridPosition.x] = nullptr;
	}
	else if (grid_[gridPosition.y][gridPosition.x - 1] == caller)
	{
		grid_[gridPosition.y][gridPosition.x - 1] = nullptr;
	}
	else if (grid_[gridPosition.y][gridPosition.x + 1] == caller)
	{
		grid_[gridPosition.y][gridPosition.x + 1] = nullptr;
	}

	grid_[gridPosition.y][gridPosition.x] = caller;
}
