#include "MovableObject.h"

#include "Goknar/Application.h"
#include "Goknar/Camera.h"
#include "Goknar/Managers/CameraManager.h"
#include "Goknar/Engine.h"
#include "Goknar/Material.h"
#include "Goknar/Model/Mesh.h"
#include "Goknar/Components/MeshComponent.h"
#include "Goknar/Managers/InputManager.h"
#include "Goknar/Scene.h"

#include "GridManager.h"

MovableObject::MovableObject()
{
	SetTickable(true);

	fallSpeed_ = 2.f;

	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::Q, INPUT_ACTION::G_PRESS, std::bind(&MovableObject::RollLeft, this));
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::E, INPUT_ACTION::G_PRESS, std::bind(&MovableObject::RollRight, this));
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::A, INPUT_ACTION::G_PRESS, std::bind(&MovableObject::MoveLeft, this));
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::D, INPUT_ACTION::G_PRESS, std::bind(&MovableObject::MoveRight, this));
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::S, INPUT_ACTION::G_PRESS, std::bind(&MovableObject::IncreaseFallSpeed, this));
	engine->GetInputManager()->AddKeyboardInputDelegate(KEY_MAP::S, INPUT_ACTION::G_RELEASE, std::bind(&MovableObject::DecreaseFallSpeed, this));
}

MovableObject::~MovableObject()
{
}

void MovableObject::BeginGame()
{
	SetWorldPosition(Vector3(0.f, 15.f, 0.f));
}

void MovableObject::Tick(float deltaTime)
{
	SetWorldPosition(GetWorldPosition() + Vector3(0.f, -1.f, 0.f) * fallSpeed_ * deltaTime);
	GridManager::GetInstance()->NotifyGridManager(this, GetWorldPosition());
}

void MovableObject::StopMovement()
{
	fallSpeed_ = 0.f;
}

void MovableObject::RollLeft()
{
	SetWorldRotation(GetWorldRotation() + Vector3(0.f, 0.f, DEGREE_TO_RADIAN(-90.f)));
}

void MovableObject::RollRight()
{
	SetWorldRotation(GetWorldRotation() + Vector3(0.f, 0.f, DEGREE_TO_RADIAN(90.f)));
}

void MovableObject::MoveLeft()
{
	Vector3 newPosition = GetWorldPosition() + Vector3(-1.f, 0.f, 0.f);

	if (GridManager::GetInstance()->IsGridEmpty(newPosition))
	{
		SetWorldPosition(newPosition);
	}
}

void MovableObject::MoveRight()
{
	Vector3 newPosition = GetWorldPosition() + Vector3(1.f, 0.f, 0.f);

	if (GridManager::GetInstance()->IsGridEmpty(newPosition))
	{
		SetWorldPosition(newPosition);
	}
}

void MovableObject::IncreaseFallSpeed()
{
	fallSpeed_ *= 4.f;
}

void MovableObject::DecreaseFallSpeed()
{
	fallSpeed_ /= 4.f;
}

int MovableObject::GetType()
{
	return type_;
}
