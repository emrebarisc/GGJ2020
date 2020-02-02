#include "GridManager.h"

#include "MovableObject.h"

GridManager* GridManager::instance_ = nullptr;

void GridManager::PrintGridManager() const
{
	std::cout << " -------------------------------------------------------------- " << std::endl;
	for (int y = gridHeight_ - 1; 0 <= y ; y--)
	{
		for (int x = 0; x < gridWidth_; x++)
		{
			std::cout << (grid_[y][x] != nullptr) << " ";
		}
		std::cout << std::endl;
	}
}

void GridManager::NotifyGridManager(MovableObject* caller, const Vector3& worldPosition)
{
	Vector2i gridPosition = ConvertWorldPositionToGridPosition(worldPosition);

	if (gridHeight_ <= gridPosition.y)
	{
		return;
	}
	
	if (gridPosition.y == 0 || grid_[gridPosition.y - 1][gridPosition.x] != nullptr)
	{
		caller->StopMovement();
		SetGridPosition(caller, gridPosition);
		PrintGridManager();
	}
}

bool GridManager::IsGridEmpty(const Vector3& worldPosition)
{
	Vector2i gridPosition = ConvertWorldPositionToGridPosition(worldPosition);

	if (gridHeight_ <= gridPosition.y)
	{
		return false;
	}

	return 0 <= gridPosition.x && gridPosition.x < gridWidth_ && grid_[gridPosition.y][gridPosition.x] == nullptr;
}

GridManager::GridManager() : gridWidth_(9), gridHeight_(16)
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
	return Vector2i(mathClamp(floor(worldPosition.x) + 4, -1, gridWidth_), floor(worldPosition.y));
}

void GridManager::SetGridPosition(MovableObject* caller, const Vector2i& gridPosition)
{
	grid_[gridPosition.y][gridPosition.x] = caller;
}
