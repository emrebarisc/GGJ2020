#include "GameController.h"

// Engine includes
#include "Goknar/Engine.h"
#include "Goknar/Managers/InputManager.h"

// Game includes
#include "GameManager.h"
#include "GridManager.h"
#include "MovableObject.h"

GameController* GameController::instance_ = nullptr;

GameController::GameController() : Controller()
{
}

void GameController::SetupInputs()
{
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::SPACE, INPUT_ACTION::G_RELEASE, std::bind(&GameController::HandleRestartInput, this));


	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::Q, INPUT_ACTION::G_PRESS, std::bind(&GameController::RollCurrentObjectLeft, this));
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::E, INPUT_ACTION::G_PRESS, std::bind(&GameController::RollCurrentObjectRight, this));
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::A, INPUT_ACTION::G_PRESS, std::bind(&GameController::MoveCurrentObjectLeft, this));
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::D, INPUT_ACTION::G_PRESS, std::bind(&GameController::MoveCurrentObjectRight, this));
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::S, INPUT_ACTION::G_PRESS, std::bind(&GameController::IncreaseCurrentObjectFallSpeed, this));
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::S, INPUT_ACTION::G_RELEASE, std::bind(&GameController::DecreaseCurrentObjectFallSpeed, this));
}

void GameController::HandleRestartInput()
{
	GameManager* gameManager = GameManager::GetInstance();
	if (gameManager->GetIsGameOver())
	{
		gameManager->Restart();
	}
}

void GameController::RollCurrentObjectLeft()
{
	GridManager::GetInstance()->GetCurrentObject()->RollLeft();
}

void GameController::RollCurrentObjectRight()
{
	GridManager::GetInstance()->GetCurrentObject()->RollRight();
}

void GameController::MoveCurrentObjectLeft()
{
	GridManager::GetInstance()->GetCurrentObject()->MoveLeft();
}

void GameController::MoveCurrentObjectRight()
{
	GridManager::GetInstance()->GetCurrentObject()->MoveRight();
}

void GameController::IncreaseCurrentObjectFallSpeed()
{
	GridManager::GetInstance()->GetCurrentObject()->IncreaseFallSpeed();
}

void GameController::DecreaseCurrentObjectFallSpeed()
{
	GridManager::GetInstance()->GetCurrentObject()->DecreaseFallSpeed();
}