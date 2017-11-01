#include "Brick.h"
#include "SingleImageController.h"

Brick::Brick(float x, float y, int collWidth, int collHeight) : Entity(x, y, collWidth, collHeight, 0, 0, "brick")
{
	visualComponent = new SingleImageController();
}


Brick::~Brick()
{

}

void Brick::Destroy()
{
	//Destroy brick, increase score?
	if (!destroyed)
	{
		destroyed = true;
	}
}
bool Brick::IsDestroyed()
{
	return destroyed;
}

SingleImageController* Brick::GetSingleImageController()
{
	return (SingleImageController*)visualComponent;
}