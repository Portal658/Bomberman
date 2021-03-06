#pragma once
#include <SFML\Graphics.hpp>
#include "textures.h"
#include "level.h"
#include <iostream>

using namespace sf;
using namespace std;

enum PlayerColor { white, black, red, green };


class Player
{
private:
	RenderWindow *window;
	Textures *textures;
	Level *level;
	PlayerColor color;
	Direction direction;
	Sprite sprite;
	Vector2f size;
	Vector2f coord;
	Vector2i levelcoord;
	float speed;
	int bomb_count;
	int bomb_strength;
public:
	Player(RenderWindow &window, Textures &textures, Level &level, PlayerColor color);
	static Vector2f get_size();
	void set_texture();
	void set_coord();
	void set_direction(Direction direction);
	void move(float time);
	void move_up(float time);
	void move_down(float time);
	void move_left(float time);
	void move_right(float time);
	void draw();
};