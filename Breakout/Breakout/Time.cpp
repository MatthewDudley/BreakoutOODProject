#include "Time.h"
float Time::deltaTime = 0.0f;
Uint32 Time::lastFrameTime = 0;
Uint32 Time::currentFrameTime = SDL_GetTicks();