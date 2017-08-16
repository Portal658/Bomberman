#include "game.h"

Game::Game()
{
	window = new RenderWindow(VideoMode(windowWidth, windowHeight), title, Style::Close);
	textures = new Textures();
	level = new Level(*window, *textures);
	player_white = new Player(*window, *textures, *level, white);
	player_black = new Player(*window, *textures, *level, black);
}

void Game::start()
{
	//window->setFramerateLimit(60);
	while (window->isOpen())
	{
		Sleep(15);
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window->close();
			}
			window->clear(Color(0, 98, 0));
			level->draw();
			player_white->draw();
			player_white->move();
			player_black->draw();
			window->display();
		}
	}
}
