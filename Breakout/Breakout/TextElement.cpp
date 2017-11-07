#include "TextElement.h"
#include "Renderer.h"
#include "MediaManager.h"
#include "Texture.h"
TextElement::TextElement(int x, int y, std::string message)
{
	this->message = message;
	this->x = x;
	this->y = y;
	texture = new Texture();
	texture->LoadText(message, { 0, 0, 0, 0 }, MediaManager::GetInstance().GetFont(), Renderer::GetInstance().GetRenderer());
	//rect = new SDL_Rect{ 0, 0, texture->GetWidth(), texture->GetHeight() };
}


TextElement::~TextElement()
{
	delete texture;
	//delete rect;
}

void TextElement::Render()
{
	SDL_Rect rect{ 0, 0, texture->GetWidth(), texture->GetHeight() };
	texture->Render(x, y, &rect, Renderer::GetInstance().GetRenderer());
}


