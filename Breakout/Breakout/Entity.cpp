#include "Entity.h"
#include "Texture.h"
#include "Vector2.h"

Entity::Entity(float x, float y)//, int collWidth, int collHeight, float collXOffset, float collYOffset, bool isTrigger)
{
	//col = new Collider(x + collXOffset, y + collYOffset, collWidth, collHeight, isTrigger);
	position = new Vector2(x, y);
	//this->collXOffset = collXOffset;
	//this->collYOffset = collYOffset;
}


Entity::~Entity()
{
	//delete col;
	//col = nullptr;
	delete visualComponent;
	visualComponent = nullptr;
	//delete position;
	//position = nullptr;
}


void Entity::SetPosX(float x)
{
	position->SetX(x);
	//col->SetPosX(x + collXOffset);
}
void Entity::SetPosY(float y)
{
	position->SetY(y);
	//col->SetPosY(y + collYOffset);
}
/*
void Entity::SetColliderWidth(int width)
{
	col->SetWidth(width);
}
void Entity::SetColliderHeight(int height)
{
	col->SetHeight(height);
}
*/

float Entity::GetPosX()
{
	return position->GetX();
}
float Entity::GetPosY()
{
	return position->GetY();
}
/*
float Entity::GetCollXOffset()
{
	return collXOffset;
}
float Entity::GetCollYOffset()
{
	return collYOffset;
}
Collider* Entity::GetCollider()
{
	return col;
}
*/
VisualComponent* Entity::GetVisualComponent()
{
	return visualComponent;
}
