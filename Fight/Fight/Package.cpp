#include "Package.h"



Package::Package(Canvas* canvas,int mark)
{
	this->canvas = canvas;
	this->getRandPosition();
	this->setPosition(randposition, 0.0f);

	this->mark = mark;

	switch (mark) {
	case 0:
		this->setTexture(Texture::ADDLIFE);
		break;
	case 1:
		this->setTexture(Texture::SKILLONE);
		break;
	case 2:
		this->setTexture(Texture::SKILLTWO);
		break;
	case 3:
		this->setTexture(Texture::SKILLTHREE);
		break;
	}
	
}


Package::~Package()
{
}

void Package::getRandPosition()
{
	this->randposition = (rand() % 759) + 1.0f;
}
