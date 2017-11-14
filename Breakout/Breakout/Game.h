#pragma once
#include <SDL.h>
#include <iostream>

class GameState;
class InputManager;
class ScoreKeeper;

class Game
{
public:
	enum class GameType{RUN, SELECT};
	~Game();
	void Start();
	ScoreKeeper* GetScoreKeeper();
	GameType GetGameType();
	void SetGameType(GameType type);
	static Game& GetInstance();
	int GetLevelCount();
	void QuitGame();
private:
	int levelCount;
	Game();
	GameType currentGameType;
	static Game instance;
	bool Initialize();
	int screenWidth;
	int screenHeight;
	bool quit = false;
	InputManager* inputManager;
	ScoreKeeper* scoreKeeper;

	GameState* currentState;

};

