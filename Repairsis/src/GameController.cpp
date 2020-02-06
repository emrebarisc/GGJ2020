#include "GameController.h"

// Engine includes
#include "Goknar/Engine.h"
#include "Goknar/Managers/InputManager.h"

// Game includes
#include "GameManager.h"

GameController* GameController::instance_ = nullptr;

GameController::GameController()
{
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::SPACE, INPUT_ACTION::G_RELEASE, std::bind(&GameController::HandleRestartInput, this));
}

void GameController::HandleRestartInput()
{
	GameManager* gameManager = GameManager::GetInstance();
	if (gameManager->GetIsGameOver())
	{
		gameManager->Restart();
	}
}
