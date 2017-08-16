#pragma once
#include <string>
#include <Windows.h>
#include <SFML\Graphics.hpp>
#include "level.h"
#include "player.h"

using namespace std;
using namespace sf;

class Game
{
private:
	const int windowWidth = 1024;
	const int windowHeight = 768;
	const string title = "Bomberman";
	RenderWindow *window;
	Textures *textures;
	Level *level;
	Player *player_white;
	Player *player_black;

public:
	Game();
	void start();

};