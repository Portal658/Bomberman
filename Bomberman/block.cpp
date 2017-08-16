#include "block.h"

Block::Block(RenderWindow &window, Textures &textures, Vector2f size, Vector2f coord, Blocks block) : Object(window, textures, size, coord)
{
	set_texture(block);
}

void Block::set_destructible(bool destructible)
{
	this->destructible = destructible;
}

void Block::set_texture(Blocks block)
{
	switch (block)
	{
	case block_0:
		sprite.setTexture(textures->block_0);
		break;
	case block_1:
		sprite.setTexture(textures->block_1);
		break;
	}
}

Vector2f Block::get_size(Blocks block)
{
	return block != block_null ? Vector2f(60, 48) : Vector2f(0, 0);
}