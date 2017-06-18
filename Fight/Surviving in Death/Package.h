#pragma once
#include "Movation.h"
#include "Texture.h"
#include<random>
#include<iostream>

class Canvas;
class Package :
	public Movation
{
public:
	Package(Canvas* canvas,int mark);
	~Package();

	int mark;
private:
	Canvas* canvas;
	float randposition;
	void getRandPosition();
};

