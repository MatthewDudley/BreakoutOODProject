#pragma once
#include <iostream>
class Entity;
class EntityFactory
{
public:
	~EntityFactory();
	enum class EntityType { Paddle, Ball, Brick };
	Entity* CreateEntity(EntityType entityType, int x, int y);
	static EntityFactory& GetInstance();

private:
	EntityFactory();
	static EntityFactory instance;
};