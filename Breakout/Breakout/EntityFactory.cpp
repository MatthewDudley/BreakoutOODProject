#include "Game.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "EntityFactory.h"

EntityFactory::EntityFactory()
{
	std::cout << "Created Factory" << std::endl; //Singleton, should only print out once
}

EntityFactory::~EntityFactory()
{
	std::cout << "Deleted Factory" << std::endl;
}

Entity* EntityFactory::CreateEntity(EntityFactory::EntityType entityType, int x, int y)
{
	//Object which asks for the object is now in charge of that objects memory
	switch (entityType)
	{
	case EntityFactory::EntityType::Ball:
	{
		//If you pass in a Ball create it here:
		std::cout << "Creatint a ball" << std::endl;
		Ball* ball = new Ball(x, y, 10, 10, 0, 0, 200, 5, 400);
		return ball; //return pointer to entity
	}

	case EntityFactory::EntityType::Brick:
		//If you pass in a Brick create it here
		std::cout << "Creating a brick" << std::endl;
		return nullptr; //return pointer to entity

	case EntityFactory::EntityType::Paddle:
		//If you pass in a Paddle create it here
		std::cout << "Creatint a paddle" << std::endl;
		return nullptr; //return pointer to entity

	default:
		//Idk how you got here, shouldn't be possible
		std::cout << "Entity factory cannot create that entity" << std::endl;
		return nullptr; //return pointer to entity
	}
}

EntityFactory& EntityFactory::GetInstance()
{
	//No need to check if the instance exists, C++ won't create another static instance
	//Also thread safe by default, C++ automatically locks on instance creation
	static EntityFactory instance;
	return instance;
}
