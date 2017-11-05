#pragma once
#include <SDL.h>
class Time
{
public:
	static void CalculateDeltaTime(int lastFrameTime, int currentFrameTime)
	{
		Time::deltaTime = (float)(currentFrameTime - lastFrameTime) / 1000;
	}
	static void CalculateDeltaTime()
	{
		Time::lastFrameTime = Time::currentFrameTime;
		Time::currentFrameTime = SDL_GetTicks();
		Time::deltaTime = (float)(Time::currentFrameTime - Time::lastFrameTime) / 1000;
	}

	static float GetDeltaTime()
	{
		return Time::deltaTime;
	}
private:
	Time() {}
	static float deltaTime;
	static Uint32 lastFrameTime;
	static Uint32 currentFrameTime;
};