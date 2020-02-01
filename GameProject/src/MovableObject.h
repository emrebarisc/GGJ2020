#pragma once
#include "C:\Users\Cem\Desktop\GGJ2020\Goknar\src\Goknar\ObjectBase.h"
class MovableObject :
	public ObjectBase
{
public:
	MovableObject();
	~MovableObject();

	void BeginGame() override;
	void Tick(float deltaTime) override;

	int GetType();

private:
	void MoveLeft();
	void MoveRight();
	void RollLeft();
	void RollRight();
	void IncreaseFallSpeed();
	void DecreaseFallSpeed();

	float fallSpeed_;

protected:
	int type_;
};

