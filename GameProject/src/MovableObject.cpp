#include "MovableObject.h"

#include "Goknar/Scene.h"

#include "Goknar/Application.h"
#include "Goknar/Camera.h"
#include "Goknar/Managers/CameraManager.h"
#include "Goknar/Engine.h"
#include "Goknar/Material.h"
#include "Goknar/Model/Mesh.h"
#include "Goknar/Components/MeshComponent.h"
#include "Goknar/Managers/InputManager.h"

MovableObject::MovableObject()
{
	SetTickable(true);

	fallSpeed_ = 1.f;

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
	SetWorldPosition(Vector3(0.f, 0.f, 0.f));
}

void MovableObject::Tick(float deltaTime)
{
	/*float elapsedTime = 0.f;
	elapsedTime += deltaTime;*/

	SetWorldPosition(GetWorldPosition() + Vector3(0.f, -1.f, 0.f) * fallSpeed_ * deltaTime);
}

void MovableObject::RollLeft()
{
	SetWorldRotation(GetWorldRotation() + Vector3(0.f, 0.f, -90.f));
}

void MovableObject::RollRight()
{
	SetWorldRotation(GetWorldRotation() + Vector3(0.f, 0.f, 90.f));
}

void MovableObject::MoveLeft()
{
	SetWorldPosition(GetWorldPosition() + Vector3(1.f, 0.f, 0.f));
}

void MovableObject::MoveRight()
{
	SetWorldPosition(GetWorldPosition() + Vector3(-1.f, 0.f, 0.f));
}

void MovableObject::IncreaseFallSpeed()
{
	fallSpeed_ *= 2.f;
}

void MovableObject::DecreaseFallSpeed()
{
	fallSpeed_ /= 2.f;
}
