#pragma once
#include <iostream>
#include <vector>
class Entity;
class TextElement;
class GameState
{
public:
	virtual ~GameState();
	virtual void Enter() {}
	virtual void Exit() {}
	virtual GameState* Update();
	virtual GameState* HandleInput();
	GameState* Transition(GameState* newState);
protected:
	std::vector<Entity*> entityList;
	std::vector<TextElement*> textList;
};

