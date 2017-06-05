#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Canvas.h"
#include"Game.h"
#include"Flash.h"
#include"Voice.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 1000), "Fighter");

	Voice::load();
	Texture::load();

	Canvas canvas(&window);
	Flash flash(&canvas);
	canvas.addFlash(&flash);
	Game game(&canvas);
	game.start();

	return 0;
}

