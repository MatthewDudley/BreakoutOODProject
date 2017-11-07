#pragma once
#include <string>
class Texture;
class TextElement
{
public:
	TextElement(int x, int y, std::string message);
	void Render();
	~TextElement();
private:
	std::string message;
	Texture* texture;
	int x;
	int y;
	//SDL_Rect* rect = nullptr;
};

