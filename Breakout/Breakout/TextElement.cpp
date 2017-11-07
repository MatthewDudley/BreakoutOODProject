#include "TextElement.h"
#include "Renderer.h"
#include "MediaManager.h"
#include "Texture.h"
TextElement::TextElement(std::string message, int x, int y)
{
	this->message = message;
	this->x = x;
	this->y = y;
	texture = new Texture();
	texture->LoadText(message, { 0, 0, 0, 0 }, MediaManager::GetInstance().GetFont(), Renderer::GetInstance().GetRenderer());
	width = texture->GetWidth();
	height = texture->GetHeight();
	//rect = new SDL_Rect{ 0, 0, texture->GetWidth(), texture->GetHeight() };
}


TextElement::~TextElement()
{
	delete texture;
	//delete rect;
}

int TextElement::GetHeight()
{
	return  height;
}

int TextElement::GetWidth()
{
	return width;
}

void TextElement::SetX(int x)
{
	this->x = x;
}
void TextElement::SetY(int y)
{
	this->y = y;
}
void TextElement::Render()
{
	SDL_Rect rect{ 0, 0, texture->GetWidth(), texture->GetHeight() };
	texture->Render(x, y, &rect, Renderer::GetInstance().GetRenderer());
}


