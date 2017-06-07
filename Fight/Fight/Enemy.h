#pragma once
#include "Plane.h"
#include"Voice.h"
#include<SFML\Audio.hpp>
#include<SFML/Graphics.hpp>
#include<random>
#include<time.h>
#include<iostream>

class Canvas;
class Enemy :
	public Plane
{

public:
	Canvas* canvas;
	 int statu=0;

	Enemy(Canvas *canvas);
	~Enemy();
	
	void getRandPosition();
	void fire();
	void state();
	
private: 
	
	float  randPosition;
	sf::Vector2f position;
	sf::Music	 &BOOM = Voice::BOOM;
};