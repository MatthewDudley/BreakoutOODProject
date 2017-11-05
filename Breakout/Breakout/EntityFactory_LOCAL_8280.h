#pragma once
#include <iostream>
class Entity;
class EntityFactory
{
public:
	~EntityFactory(); //destructor
	enum class EntityType { Paddle, Ball, Brick };
	Entity* CreateEntity(EntityType entityType);
	static EntityFactory& GetInstance();

private:
	EntityFactory(); //Constructor
	static EntityFactory instance;
};