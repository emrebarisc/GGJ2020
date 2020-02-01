#pragma once
#include "Goknar\ObjectBase.h"

class MovableObject : public ObjectBase
{
public:
	MovableObject();
	~MovableObject();

	void BeginGame() override;
	void Tick(float deltaTime) override;

	void StopMovement();
	int GetType();

protected:

	int type_;
private:
	void MoveLeft();
	void MoveRight();
	void RollLeft();
	void RollRight();
	void IncreaseFallSpeed();
	void DecreaseFallSpeed();

	float fallSpeed_;

	float width_;
	float height_;

	bool isMovementEnded_;
};
