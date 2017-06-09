#pragma once
#include<SFML\Audio.hpp>
#include"Voice.h"
#include "Plane.h"
#include"Bullet.h"
#include"Texture.h"

class Canvas;
class Flash :
	public Plane
{

public:

	Canvas * canvas;
	sf::Sprite touming;
	sf::Sprite *Explosion = new sf::Sprite;
	bool shield = false;
	int state = 0;
	
	int skillone = 0;
	int skilltwo = 5;
	int skillthree = 3;


	Flash(Canvas*canvas);
	~Flash();

	void InitPsition();
	void fire();
	
	void increaseLife();
	void dead();

	void setshield(bool shield);
	void status();

	void increaseScore(int score);
	void cleanScore();
	int getScore();
	int getNowlife();
	int getSkillOne();
	int getSkillTwo();
	int getSkillThree();

private:
	int life = 3;
	int score = 0;
	sf::Music &BOOM = Voice::BOOM;
	sf::Vector2f position;
};

