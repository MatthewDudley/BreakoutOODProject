#pragma once
#include <iostream>
class Entity;
class EntityFactory
{
public:
<<<<<<< HEAD
	~EntityFactory(); //destructor
=======
	~EntityFactory();
>>>>>>> dae20b09afe1b40174ce7572b2588a9e7483487b
	enum class EntityType { Paddle, Ball, Brick };
	Entity* CreateEntity(EntityType entityType);
	static EntityFactory& GetInstance();

private:
<<<<<<< HEAD
	EntityFactory(); //Constructor
=======
	EntityFactory();
>>>>>>> dae20b09afe1b40174ce7572b2588a9e7483487b
	static EntityFactory instance;
};