#include "EntityFactory.h"

Entity* EntityFactory::CreateEntity(EntityFactory::EntityType entityType)
{
	//Object which asks for the object is now in charge of that objects memory
	switch (entityType)
	{
	case EntityFactory::EntityType::Ball:
		//Create a ball
		std::cout << "Created a ball" << std::endl;
		return nullptr;
	case EntityFactory::EntityType::Brick:
		//Create a brick
		std::cout << "Created a brick" << std::endl;
		return nullptr;
	case EntityFactory::EntityType::Paddle:
		//Create a paddle
		std::cout << "Created a paddle" << std::endl;
		return nullptr;
	default:
		//Idk how you got here, shouldn't be possible
		std::cout << "Entity factory cannot create that entity" << std::endl;
		return nullptr;
	}
}

EntityFactory& EntityFactory::GetInstance()
{
	//No need to check if the instance exists, C++ won't create another static instance
	//Also thread safe by default, C++ automatically locks on instance creation
	static EntityFactory instance;
	return instance;
}
