#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Voice.h"
#include"Canvas.h"

class Game
{
private:
	Canvas* canvas;

	sf::Music  &BMG = Voice::BACKROUND;
public:
	
	Game(Canvas* canvas);
	void start();
	~Game();
};

