#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Voice.h"
#include"Canvas.h"

class Game
{
private:
	Canvas* canvas;

	//因为information和当前的生命都是属于游戏中的，所以在这里

	sf::Text Information;
	int nowlife;
	int score=0;
	void showInformation();
	void updateInformation();

	sf::Music  &BMG = Voice::BACKROUND;
public:
	
	Game(Canvas* canvas);
	void start();
	~Game();
};

