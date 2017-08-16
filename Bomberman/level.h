#pragma once
#include <SFML\Graphics.hpp>
#include <list>
#include "block.h"
#include <iostream>

using namespace std;
using namespace sf;

enum Direction { dir_up, dir_down, dir_left, dir_right };

class Level
{
private:
	struct Cell
	{
		Blocks block;
		Vector2f coord;
	};
	Cell **level;
	RenderWindow *window;
	Textures *textures;
	const float indent = 30.f;
	const float indent_top = 90.f;
	const int blocks_width = 15;
	const int blocks_length = 13;
	list<Block*> destructible_blocks;
	list<Block*> non_destructible_blocks;
	void init();
	void set_block_hardness();
	void create_level();
	
public:
	Level(RenderWindow &window, Textures &textures);
	void draw();
	Vector2f getcoord_from_levelcoord(Vector2i levelcoord);
	Vector2i getlevelcoord_from_coord(Vector2f coord);
	Blocks getblock_from_levelcoord(Vector2i levelcoord);
	Blocks getblock_before_player(Vector2i player_coord, Direction direction);
};