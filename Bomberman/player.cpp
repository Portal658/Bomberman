#include "player.h"

Player::Player(RenderWindow &window, Textures &textures, Level &level, PlayerColor color)
{
	this->window = &window;
	this->textures = &textures;
	this->level = &level;
	this->color = color;
	this->direction = dir_down;
	this->bomb_count = 1;
	this->bomb_strength = 3;
	this->speed = 10.f;
	set_texture();
	set_coord();
}

Vector2f Player::get_size()
{
	return Vector2f(57, 67);
}

void Player::set_texture()
{
	switch (color)
	{
	case white:
		switch (direction)
		{
		case dir_up:
			sprite.setTexture(textures->player_white_up);
			break;
		case dir_down:
			sprite.setTexture(textures->player_white_down);
			break;
		case dir_left:
			sprite.setTexture(textures->player_white_left);
			break;
		case dir_right:
			sprite.setTexture(textures->player_white_right);
			break;
		}
		break;
	case black:
		switch (direction)
		{
		case dir_up:
			sprite.setTexture(textures->player_black_up);
			break;
		case dir_down:
			sprite.setTexture(textures->player_black_down);
			break;
		case dir_left:
			sprite.setTexture(textures->player_black_left);
			break;
		case dir_right:
			sprite.setTexture(textures->player_black_right);
			break;
		}
		break;
	case red:
		switch (direction)
		{
		case dir_up:
			sprite.setTexture(textures->player_red_up);
			break;
		case dir_down:
			sprite.setTexture(textures->player_red_down);
			break;
		case dir_left:
			sprite.setTexture(textures->player_red_left);
			break;
		case dir_right:
			sprite.setTexture(textures->player_red_right);
			break;
		}
		break;
	case green:
		switch (direction)
		{
		case dir_up:
			sprite.setTexture(textures->player_green_up);
			break;
		case dir_down:
			sprite.setTexture(textures->player_green_down);
			break;
		case dir_left:
			sprite.setTexture(textures->player_green_left);
			break;
		case dir_right:
			sprite.setTexture(textures->player_green_right);
			break;
		}
		break;
	}
}

void Player::set_coord()
{
	switch (color)
	{
	case white:
		levelcoord = Vector2i(1, 1);
		break;
	case black:
		levelcoord = Vector2i(11, 13);
		break;
	case red:
		levelcoord = Vector2i(1, 13);
		break;
	case green:
		levelcoord = Vector2i(11, 1);
		break;
	}
	coord = level->getcoord_from_levelcoord(levelcoord);
	coord.y -= 17;
}

void Player::set_direction(Direction direction)
{
	this->direction = direction;
}

void Player::move()
{
	switch (color)
	{
	case white:
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			if (direction != dir_down)
			{
				set_direction(dir_down);
			}
			move_down();
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (direction != dir_up)
			{
				set_direction(dir_up);
			}
			move_up();
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			if (direction != dir_right)
			{
				set_direction(dir_right);
			}
			move_right();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			if (direction != dir_left)
			{
				set_direction(dir_left);
			}
			move_left();
		}
		break;
	case black:
		break;
	case red:
		break;
	case green:
		break;
	}
}

void Player::move_up()
{
	if (level->getblock_from_levelcoord(level->getlevelcoord_from_coord(Vector2f(coord.x, coord.y + 0x11 - speed))) == block_null)
	{
		if (level->getblock_from_levelcoord(level->getlevelcoord_from_coord(Vector2f(coord.x + get_size().x, coord.y + 0x11 - speed))) == block_null)
		{
			coord.y -= speed;
			levelcoord = level->getlevelcoord_from_coord(coord);
		}
	}
}

void Player::move_down()
{
	if (level->getblock_from_levelcoord(level->getlevelcoord_from_coord(Vector2f(coord.x, coord.y + speed + 0x11 + Block::get_size(block_0).y))) == block_null)
	{
		if (level->getblock_from_levelcoord(level->getlevelcoord_from_coord(Vector2f(coord.x + get_size().x, coord.y + speed + 0x11 + Block::get_size(block_0).y))) == block_null)
		{
			coord.y += speed;
			levelcoord = level->getlevelcoord_from_coord(coord);
		}
	}
}

void Player::move_left()
{
	if (level->getblock_from_levelcoord(level->getlevelcoord_from_coord(Vector2f(coord.x - speed, coord.y + 0x11))) == block_null)
	{
		if (level->getblock_from_levelcoord(level->getlevelcoord_from_coord(Vector2f(coord.x - speed, coord.y + 0x11 + get_size().y - 20))) == block_null)
		{
			coord.x -= speed;
			levelcoord = level->getlevelcoord_from_coord(coord);
		}
	}
}

void Player::move_right()
{
	if (level->getblock_from_levelcoord(level->getlevelcoord_from_coord(Vector2f(coord.x + Block::get_size(block_0).x, coord.y + 0x11))) == block_null)
	{
		if (level->getblock_from_levelcoord(level->getlevelcoord_from_coord(Vector2f(coord.x + Block::get_size(block_0).x, coord.y + 0x11 + get_size().y - 20))) == block_null)
		{
			coord.x += speed;
			levelcoord = level->getlevelcoord_from_coord(coord);
		}
	}
}

void Player::draw()
{
	sprite.setPosition(coord);
	window->draw(sprite);
}
