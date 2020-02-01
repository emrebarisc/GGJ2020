#include "GridManager.h"

#include "MovableObject.h"
#include "RectangleObject.h"
#include "RepairableObject.h"

GridManager* GridManager::instance_ = nullptr;

void GridManager::PrintGridManager() const
{
	std::cout << " -------------------------------------------------------------- " << std::endl;
	for (int y = gridHeight_ - 1; 0 < y ; y--)
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
		PrintGridManager();
	}
	else
	{
		SetGridPosition(caller, gridPosition);
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
		if (grid_[gridPosition.x + 1][gridPosition.y] != nullptr && grid_[gridPosition.x + 1][gridPosition.y]->GetType() == 1)
		{
			caller->SetParent(grid_[gridPosition.x + 1][gridPosition.y]->GetParent());
			caller->GetParent()->AddPartToRectangle(caller);
		}
		else
			caller->SetParent(new RectangleObject());
	}
	else if (caller->GetType() == 1)
	{
		if (gridPosition.x > 0 && grid_[gridPosition.x - 1][gridPosition.y] != nullptr && grid_[gridPosition.x - 1][gridPosition.y]->GetType() == 1)
		{
			caller->SetParent(grid_[gridPosition.x - 1][gridPosition.y]->GetParent());
			caller->GetParent()->AddPartToRectangle(caller);
		}
		else
			caller->SetParent(new RectangleObject());
	}
	else if (caller->GetType() == 2)
	{
		if (gridPosition.y > 0 && grid_[gridPosition.x][gridPosition.y - 1] != nullptr && grid_[gridPosition.x][gridPosition.y - 1]->GetType() == 0)
		{
			caller->SetParent(grid_[gridPosition.x][gridPosition.y - 1]->GetParent());
			caller->GetParent()->AddPartToRectangle(caller);
		}
	}
	else if (caller->GetType() == 3)
	{
		if (gridPosition.y > 0 && grid_[gridPosition.x][gridPosition.y - 1] != nullptr && grid_[gridPosition.x][gridPosition.y - 1]->GetType() == 1)
		{
			caller->SetParent(grid_[gridPosition.x][gridPosition.y - 1]->GetParent());
			caller->GetParent()->AddPartToRectangle(caller);
		}
	}

	std::cout << caller->GetParent() << std::endl;
}

Vector2i GridManager::ConvertWorldPositionToGridPosition(const Vector3& worldPosition)
{
	return Vector2i(mathClamp(floor(worldPosition.x) + 4, -1, gridWidth_), floor(worldPosition.y));
}

void GridManager::SetGridPosition(MovableObject* caller, const Vector2i& gridPosition)
{
	if (gridPosition.y < (gridHeight_ - 1) && grid_[gridPosition.y + 1][gridPosition.x] == caller)
	{
		grid_[gridPosition.y + 1][gridPosition.x] = nullptr;
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
