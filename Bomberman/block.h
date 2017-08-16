#pragma once
#include <SFML\Graphics.hpp>
#include "object.h"

using namespace sf;

enum Blocks { block_null = -1, block_0, block_1 };

class Block : public Object
{
private:
	bool destructible;

public:
	Block(RenderWindow &window, Textures &textures, Vector2f size, Vector2f coord, Blocks block);
	void set_destructible(bool destructible);
	void set_texture(Blocks block);
	static Vector2f get_size(Blocks block);
};