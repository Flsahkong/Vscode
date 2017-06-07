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
	bool  shield = false;
	int state = 0;
	Flash(Canvas*canvas);
	~Flash();

	void InitPsition();
	void fire();
	void setshield(bool shield);

	int getNowlife();
	void increaseLife();
	void dead();

	void status();
private:
	int life = 3;
	sf::Music &BOOM = Voice::BOOM;
	sf::Vector2f position;
};

