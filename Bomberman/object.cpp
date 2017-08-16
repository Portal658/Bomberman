#include "object.h"

Object::Object(RenderWindow &window, Textures &textures, Vector2f size, Vector2f coord)
{
	this->window = &window;
	this->textures = &textures;
	this->coord = coord;
	this->size = size;
}

void Object::draw()
{
	sprite.setPosition(coord);
	window->draw(sprite);
}