#include "MediaManager.h"
#include "Texture.h"


MediaManager::MediaManager()
{
}


MediaManager::~MediaManager()
{
	for (unsigned i = 0; i < textureVector.size(); ++i)
	{
		delete textureVector[i];
		textureVector[i] = nullptr;
	}
}

MediaManager& MediaManager::GetInstance()
{
	//No need to check if the instance exists, C++ won't create another static instance
	//Also thread safe by default, C++ automatically locks on instance creation
	static MediaManager instance;
	return instance;
}

void MediaManager::CreateTexture(std::string path, SDL_Renderer* renderer)
{
	Texture* texture = new Texture();
	texture->LoadTexture(path, renderer);
	textureVector.push_back(texture);
	textureAmount++;
}

Texture* MediaManager::GetTexture(int index)
{
	if (index >= textureAmount)
	{
		std::cout << "Index out of range, not enough textures have been created" << std::endl;
		return nullptr;
	}
	else
	{
		return textureVector[index];
	}
}

/*
void MediaManager::GeneratePlayerAnimations()
{
	Animation* playerIdleAnimation = new Animation(4, 7, true);
	//playerIdleAnimation->CutSprite(0, 0, 100, 100);
	playerIdleAnimation->CutSprite(4, 0, 31, 45);
	playerIdleAnimation->CutSprite(36, 0, 31, 45);
	playerIdleAnimation->CutSprite(68, 0, 31, 45);
	playerIdleAnimation->CutSprite(36, 0, 31, 45);
	playerAnimations[Animations::PlayerAnimations::Idle] = playerIdleAnimation;
	Animation* playerRunningAnimation = new Animation(10, 12, true);
	//playerRunningAnimation->CutSprite(100, 0, 100, 100);
	//playerRunningAnimation->CutSprite(200, 0, 100, 100);
	playerRunningAnimation->CutSprite(164, 0, 31, 45);
	playerRunningAnimation->CutSprite(196, 0, 31, 45);
	playerRunningAnimation->CutSprite(228, 0, 34, 45);
	playerRunningAnimation->CutSprite(263, 0, 36, 45);
	playerRunningAnimation->CutSprite(300, 0, 31, 45);
	playerRunningAnimation->CutSprite(332, 0, 31, 45);
	playerRunningAnimation->CutSprite(364, 0, 31, 45);
	playerRunningAnimation->CutSprite(396, 0, 32, 45);
	playerRunningAnimation->CutSprite(429, 0, 36, 45);
	playerRunningAnimation->CutSprite(466, 0, 31, 45);
	playerAnimations[Animations::PlayerAnimations::Run] = playerRunningAnimation;

	Animation* playerJumpAnimation = new Animation(3, 10, false);
	playerJumpAnimation->CutSprite(4, 48, 32, 38);
	playerJumpAnimation->CutSprite(36, 45, 32, 43);
	playerJumpAnimation->CutSprite(68, 45, 32, 47);
	playerAnimations[Animations::PlayerAnimations::Jump] = playerJumpAnimation;

	Animation* playerFallAnimation = new Animation(2, 8, false);
	playerFallAnimation->CutSprite(100, 46, 32, 42);
	playerFallAnimation->CutSprite(132, 46, 32, 43);
	playerAnimations[Animations::PlayerAnimations::Fall] = playerFallAnimation;

	Animation* playerWallSlideAnimation = new Animation(3, 20, false);
	playerWallSlideAnimation->CutSprite(165, 46, 32, 43);
	playerWallSlideAnimation->CutSprite(196, 46, 32, 44);
	playerWallSlideAnimation->CutSprite(228, 46, 32, 43);
	playerAnimations[Animations::PlayerAnimations::WallSlide] = playerWallSlideAnimation;
}
std::map<Animations::AnimationType, Animation*> MediaManager::GetPlayerAnimations()
{
	return playerAnimations;
}
*/