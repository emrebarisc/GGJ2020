#ifndef __UI_H__
#define __UI_H__

#include "Goknar/ObjectBase.h"

class MeshComponent;

class UI : public ObjectBase
{
public:
	UI();
	~UI();

	void ShowGameOverUI();
	void HideGameOverUI();

private:
	MeshComponent* gameOverSprite_;
	MeshComponent* restartSprite_;
};

#endif