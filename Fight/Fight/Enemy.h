#pragma once
#include "Plane.h"

class Canvas;
class Enemy :
	public Plane
{

public:
	Enemy(Canvas *canvas);
	~Enemy();

private:

	sf::Vector2f position;
};