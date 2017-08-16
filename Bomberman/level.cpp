#include "level.h"

Level::Level(RenderWindow &window, Textures &textures)
{
	this->window = &window;
	this->textures = &textures;
	init();
}

void Level::init()
{
	level = new Cell*[blocks_length];
	for (int i = 0; i < blocks_length; ++i)
	{
		level[i] = new Cell[blocks_width];
	}
	create_level();
	set_block_hardness();
}

void Level::set_block_hardness()
{
	for (list<Block*>::iterator it = destructible_blocks.begin(); it != destructible_blocks.end(); ++it)
	{
		(*it)->set_destructible(true);
	}
	for (list<Block*>::iterator it = non_destructible_blocks.begin(); it != non_destructible_blocks.end(); ++it)
	{
		(*it)->set_destructible(false);
	}
}

void Level::create_level()
{
	for (int i = 1; i < 14; ++i)
	{
		for (int j = 1; j < 12; ++j)
		{
			if ((j == 1 || j == 11) && (i < 4 || i > 10))
			{
				level[j][i].block = block_null;
				level[j][i].coord = Vector2f(indent + 60 * i, indent_top + 48 * j);
				continue;
			}
			if ((i == 1 || i == 13) && (j < 4 || j > 8))
			{
				level[j][i].block = block_null;
				level[j][i].coord = Vector2f(indent + 60 * i, indent_top + 48 * j);
				continue;
			}
			if ((i % 2 == 0) && (j % 2 == 0))
			{
				level[j][i].block = block_0;
				level[j][i].coord = Vector2f(indent + 60 * i, indent_top + 48 * j);
				non_destructible_blocks.push_back(new Block(*window, *textures, Vector2f(60, 48), Vector2f(indent + 60 * i, indent_top + 48 * j), block_0));
			}
			else
			{
				level[j][i].block = block_1;
				level[j][i].coord = Vector2f(indent + 60 * i, indent_top + 48 * j);
				destructible_blocks.push_back(new Block(*window, *textures, Vector2f(60, 48), Vector2f(indent + 60 * i, indent_top + 48 * j), block_1));
			}
		}
	}
	for (int i = 0; i < 15; ++i)
	{
		level[0][i].block = block_0;
		level[0][i].coord = Vector2f(indent + 60 * i, indent_top);
		level[12][i].block = block_0;
		level[12][i].coord = Vector2f(indent + 60 * i, 576 + indent_top);
		non_destructible_blocks.push_back(new Block(*window, *textures, Vector2f(60, 48), Vector2f(indent + 60 * i, indent_top), block_0));
		non_destructible_blocks.push_back(new Block(*window, *textures, Vector2f(60, 48), Vector2f(indent + 60 * i, 576 + indent_top), block_0));
	}
	for (int i = 1; i < 12; ++i)
	{
		level[i][0].block = block_0;
		level[i][0].coord = Vector2f(indent, indent_top + 48 * i);
		level[i][14].block = block_0;
		level[i][14].coord = Vector2f(840 + indent, indent_top + 48 * i);
		non_destructible_blocks.push_back(new Block(*window, *textures, Vector2f(60, 48), Vector2f(indent, indent_top + 48 * i), block_0));
		non_destructible_blocks.push_back(new Block(*window, *textures, Vector2f(60, 48), Vector2f(840 + indent, indent_top + 48 * i), block_0));
	}
}

void Level::draw()
{
	for (list<Block*>::iterator it = destructible_blocks.begin(); it != destructible_blocks.end(); ++it)
	{
		(*it)->draw();
	}
	for (list<Block*>::iterator it = non_destructible_blocks.begin(); it != non_destructible_blocks.end(); ++it)
	{
		(*it)->draw();
	}
}

Vector2f Level::getcoord_from_levelcoord(Vector2i levelcoord)
{
	return level[levelcoord.x][levelcoord.y].coord;
}

Vector2i Level::getlevelcoord_from_coord(Vector2f coord)
{
	Vector2f block_size = Block::get_size(block_0);
	int new_coord_x = (int)((coord.x - indent) / block_size.x);
	int new_coord_y = (int)((coord.y - indent_top) / block_size.y);
	return Vector2i(new_coord_x, new_coord_y);
}

Blocks Level::getblock_from_levelcoord(Vector2i levelcoord)
{
	return level[levelcoord.x][levelcoord.y].block;
}

Blocks Level::getblock_before_player(Vector2i player_coord, Direction direction)
{
	switch (direction)
	{
	case dir_up:
		return level[player_coord.x][player_coord.y - 1].block;
	case dir_down:
		return level[player_coord.x][player_coord.y + 1].block;
	case dir_left:
		return level[player_coord.x - 1][player_coord.y].block;
	case dir_right:
		return level[player_coord.x + 1][player_coord.y].block;
	}
}
