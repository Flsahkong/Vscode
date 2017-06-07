#pragma once
#include "Movation.h"
#include"Texture.h"

class Canvas;
class Bullet :
	public Movation
{
public:
	
	Bullet(sf::Texture texture, Canvas* canvas);
	void InitPosition(float x, float y);
	~Bullet();
private:
	float scale_x = 1.0;
	float scale_y = 1.0;
};

