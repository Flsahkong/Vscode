#pragma once
#include "Movation.h"
#include"Texture.h"

class Bullet :
	public Movation
{
public:
	
	Bullet(sf::Texture texture);
	void InitPosition(float x, float y);
	~Bullet();
private:
	float scale_x = 1.0;
	float scale_y = 1.0;
};

