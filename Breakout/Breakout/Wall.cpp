#include "Wall.h"
#include "SingleImageController.h"

Wall::Wall(float x, float y, int collWidth, int collHeight) : Entity(x, y, collWidth, collHeight, 0, 0)
{
	visualComponent = new SingleImageController();
}


Wall::~Wall()
{

}

SingleImageController* Wall::GetSingleImageController()
{
	return (SingleImageController*)visualComponent;
}
