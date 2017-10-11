#include "VisualComponent.h"


VisualComponent::VisualComponent()
{
}


VisualComponent::~VisualComponent()
{
}

void VisualComponent::SetTexture(Texture* texture)
{
	this->texture = texture;
}
