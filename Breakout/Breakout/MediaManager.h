#pragma once
#include <SDL.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
class Texture;
/*
#include "Animation.h"
#include "AnimationNames.h"
*/
class MediaManager
{
public:
	static MediaManager& GetInstance();
	~MediaManager();
	void CreateTexture(std::string path, SDL_Renderer* renderer);
	Texture* GetTexture(int index);
	//void GeneratePlayerAnimations();
	//std::map<Animations::AnimationType, Animation*> GetPlayerAnimations();
private:
	MediaManager();
	static MediaManager instance;
	std::vector<Texture*> textureVector;
	//std::map<Animations::AnimationType, Animation*> playerAnimations;
	int textureAmount;
};

