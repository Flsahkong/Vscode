#pragma once
#include "E:\SFML-2.4.2\include\SFML\Graphics\Sprite.hpp"
class Movation :
	public sf::Sprite
{
public:

	void Move(char c);
	void setSpeed(float speed);
	Movation();
	~Movation();
private:
	float speed = 0.5f;
};

