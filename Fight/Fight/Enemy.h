#pragma once
#include "Plane.h"
#include<random>
#include<time.h>
#include<iostream>
class Canvas;
class Enemy :
	public Plane
{

public:
	Canvas* canvas;

	Enemy(Canvas *canvas);
	~Enemy();
	
	void getRandPosition();
	void fire();
private:
	float  randPosition;
	sf::Vector2f position;
};