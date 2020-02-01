#include "time.h"
#include "RectanglePart.h"

#include "Goknar/Application.h"
#include "Goknar/Engine.h"
#include "Goknar/Math.h"
#include "Goknar/Components/MeshComponent.h"
#include "Goknar/Scene.h"

RectanglePart::RectanglePart()
{
	srand(time(0));
	int type = rand() % 4;

	type_ = type;

	SetWorldPosition(Vector3(0.f, 15.f, 0.f));
	//SetWorldRotation(Vector3(0.f, 0.f, PI * (rand() % 4)));

	meshComponent_ = new MeshComponent(this);
	meshComponent_->SetMesh(engine->GetApplication()->GetMainScene()->GetMesh(type));
}


RectanglePart::~RectanglePart()
{
}

void RectanglePart::SetParent(RepairableObject* parent)
{
	parentObject_ = parent;
}

RepairableObject* RectanglePart::GetParent( )
{
	return parentObject_;
}