#pragma once
#include"Movation.h"


class Canvas;
class Plane :
	public Movation
{
private:
	Canvas* canvas;
public:
	Plane(Canvas *canvas);
	~Plane();
};

