#include "Game.h"
#include "Entity.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include "EntityFactory.h"
#include "SingleImageController.h"
#include "Texture.h"
#include "MediaManager.h"
#include "PhysicsComponent.h"
#include "Renderer.h"
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
		//Ball creation:
		Ball* ball = new Ball(x, y, 10, 10, 0, 0, 200, 5, 400);
		ball->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
		ball->GetSingleImageController()->SetCurrentSpriteRect(0, 0, 10, 10);
		ball->SetStartingVelocity(0, 180);
		ball->SetResetTimer(2);//in seconds
		ball->GetPhysicsComponent()->SetMaxSpeed(100.0f);
		ball->GetPhysicsComponent()->SetVelocity(0, 180);
		return ball; //return pointer to entity
	}
	case EntityFactory::EntityType::Brick:
	{
		//Brick creation:
		return nullptr; //return pointer to entity
	}
	case EntityFactory::EntityType::Paddle:
	{
		//Paddle creation:
		Paddle* paddle = new Paddle(x - 50, y, 100, 15, 0, 0);
		paddle->GetSingleImageController()->SetTexture(MediaManager::GetInstance().GetTexture(0));
		paddle->GetSingleImageController()->SetCurrentSpriteRect(0, 0, 100, 15);
		paddle->GetPhysicsComponent()->SetMaxSpeed(400.0f);
		paddle->SetBounds(25, Renderer::GetInstance().GetScreenWidth() - 25);
		return paddle; //return pointer to entity
	}
	default:
	{
		//Idk how you got here, shouldn't be possible
		std::cout << "Entity factory cannot create that entity" << std::endl;
		return nullptr; //return pointer to entity
	}
	}
}

EntityFactory& EntityFactory::GetInstance()
{
	//No need to check if the instance exists, C++ won't create another static instance
	//Also thread safe by default, C++ automatically locks on instance creation
	static EntityFactory instance;
	return instance;
}
