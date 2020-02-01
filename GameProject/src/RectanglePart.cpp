#include "RectanglePart.h"
#include "Goknar/Engine.h"
#include "Goknar/Scene.h"
#include "Goknar/Application.h"

#include "Goknar/Components/MeshComponent.h"


RectanglePart::RectanglePart()
{
	meshComponent_ = new MeshComponent(this);
	meshComponent_->SetMesh(engine->GetApplication()->GetMainScene()->GetMesh(1));
}


RectanglePart::~RectanglePart()
{
}
