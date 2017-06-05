#pragma once
#include "Plane.h"
#include"Bullet.h"
#include"Texture.h"

class Canvas;
class Flash :
	public Plane
{

public:

	Canvas * canvas;

	Flash(Canvas*canvas);
	~Flash();

	void InitPsition();
	void fire();

private:
	
	sf::Vector2f position;
};

