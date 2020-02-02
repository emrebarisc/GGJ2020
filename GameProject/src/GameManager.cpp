#include "GameManager.h"

#include "GridManager.h"
#include "MovableObjectFactory.h"

#include <iostream>

GameManager* GameManager::instance_ = nullptr;

void GameManager::Restart()
{
	GridManager* gridManagerInstance = GridManager::GetInstance();
	gridManagerInstance->ClearGrid();

	isGameOver_ = false;

	MovableObjectFactory::GetInstance()->CreateMovableObject();
}

void GameManager::GameOver()
{
	isGameOver_ = true;

	std::cout << "Game is over!" << std::endl;
}
