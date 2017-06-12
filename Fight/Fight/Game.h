#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Voice.h"
#include"Canvas.h"
#include <stdlib.h> 
#include<time.h>

class Game
{
private:
	Canvas* canvas;

	sf::Music  &BMG = Voice::BACKROUND;
	sf::Text Information;
	sf::Text StartInfoOne;
	sf::Text StartInfoTwo;
	sf::Text StartInfoThree;
	sf::Text WinInfo;
	sf::Text WinInfoTwo;
	int packrand;
	bool IsWin = false;
	 
	int nowlife;
	int score=0;
	int skillone = 0;
	int skilltwo = 0;
	int skillthree = 0;

	void showInformation();
	void showStartInfo();
	void showStartNextInfo();
	void showFinalInfo();
	void updateInformation();
	void gengeraterand();
	
public:

	Game(Canvas* canvas);
	void start();
	void FlashMoveAutomatically();
	~Game();
};

