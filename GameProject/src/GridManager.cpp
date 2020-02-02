#include "GridManager.h"

#include "MovableObject.h"
#include "RectangleObject.h"
#include "RepairableObject.h"

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
	if (gridPosition.y == 0 || (grid_[gridPosition.y][gridPosition.x] != nullptr && grid_[gridPosition.y][gridPosition.x] != caller))
	{
		caller->StopMovement();
		CheckAndSetObjectParent(caller, gridPosition);
		SetGridPosition(caller, gridPosition + Vector2i(0, 1));
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

void GridManager::CheckAndSetObjectParent(MovableObject* caller, const Vector2i& gridPosition)
{
	if (caller->GetType() == 0)
	{
		if (grid_[gridPosition.y][gridPosition.x + 1] != nullptr && grid_[gridPosition.y][gridPosition.x + 1]->GetType() == 1)
		{
			std::cout << "0 placed" << std::endl;
			caller->SetParent(grid_[gridPosition.y][gridPosition.x + 1]->GetParent());
			caller->GetParent()->AddPartToRectangle(caller);
		}
		else {
			std::cout << "new parent" << std::endl;
			caller->SetParent(new RectangleObject());
			caller->GetParent()->AddPartToRectangle(caller);
		}
	}
	else if (caller->GetType() == 1)
	{
		if (gridPosition.x > 0 && grid_[gridPosition.y][gridPosition.x - 1] != nullptr && grid_[gridPosition.y][gridPosition.x - 1]->GetType() == 0)
		{
			std::cout << "1 placed" << std::endl;
			caller->SetParent(grid_[gridPosition.y][gridPosition.x - 1]->GetParent());
			caller->GetParent()->AddPartToRectangle(caller);
		}
		else {
			std::cout << "new parent" << std::endl;
			caller->SetParent(new RectangleObject());
			caller->GetParent()->AddPartToRectangle(caller);
		}
	}
	else if (caller->GetType() == 2)
	{
		if (gridPosition.y > 0 && grid_[gridPosition.y - 1][gridPosition.x] != nullptr && grid_[gridPosition.y - 1][gridPosition.x]->GetType() == 0)
		{
			std::cout << "2 placed" << std::endl;
			caller->SetParent(grid_[gridPosition.y - 1][gridPosition.x]->GetParent());
			caller->GetParent()->AddPartToRectangle(caller);
		}
	}
	else if (caller->GetType() == 3)
	{
		if (gridPosition.y > 0 && grid_[gridPosition.y - 1][gridPosition.x] != nullptr && grid_[gridPosition.y - 1][gridPosition.x]->GetType() == 1)
		{
			std::cout << "3 placed" << std::endl;
			caller->SetParent(grid_[gridPosition.y - 1][gridPosition.x]->GetParent());
			caller->GetParent()->AddPartToRectangle(caller);
		}
	}
}

Vector2i GridManager::ConvertWorldPositionToGridPosition(const Vector3& worldPosition)
{
	return Vector2i(mathClamp(floor(worldPosition.x) + 4, -1, gridWidth_), floor(worldPosition.y));
}

void GridManager::SetGridPosition(MovableObject* caller, const Vector2i& gridPosition)
{
	grid_[gridPosition.y][gridPosition.x] = caller;
}
