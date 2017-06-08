#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include"Voice.h"
#include"Canvas.h"

class Game
{
private:
	Canvas* canvas;

	//��Ϊinformation�͵�ǰ����������������Ϸ�еģ�����������

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

