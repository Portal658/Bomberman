#pragma once
#include <SFML\Graphics.hpp>
#include "textures.h"

using namespace sf;

class Object
{
private:
	RenderWindow *window;
	
public:
	Object(RenderWindow &window, Textures &textures, Vector2f size, Vector2f coord);
	void draw();

protected:
	Textures *textures;
	Sprite sprite;
	Vector2f size;
	Vector2f coord;
};