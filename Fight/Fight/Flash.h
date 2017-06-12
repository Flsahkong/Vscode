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
	
	int skillone = 3;
	int skilltwo = 3;
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

	void reset();

private:
	int life = 5;
	int score = 0;
	sf::Music &BOOM = Voice::BOOM;
	sf::Vector2f position;
};

