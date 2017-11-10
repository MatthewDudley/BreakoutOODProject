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
	virtual GameState* LeftPressed();
	virtual GameState* LeftReleased();
	virtual GameState* RightPressed();
	virtual GameState* RightReleased();
	virtual GameState* EscPressed();
	virtual GameState* APressed() { return nullptr; }
	virtual GameState* SPressed() { return nullptr; }
	virtual GameState* DPressed() { return nullptr; }
	virtual GameState* OnePressed() { return nullptr; }
	virtual GameState* TwoPressed() { return nullptr; }
	virtual GameState* ThreePressed() { return nullptr; }
	GameState* Transition(GameState* newState);
protected:
	std::vector<Entity*> entityList;
	std::vector<TextElement*> textList;
};

