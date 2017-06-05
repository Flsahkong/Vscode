#include "Flash.h"
#include"Canvas.h"
#include<iostream>

Flash::Flash(Canvas*canvas):Plane(canvas)
{
	this->position.x = 400;
	this->position.y = 400;

	this->setTexture(Texture::FLASH);
	
}

Flash::~Flash()
{
}

void Flash::InitPsition()
{
	this->setPosition(position.x, position.y);
}

void Flash::fire()
{
	static int i = 0;
	if (i > 200) {
		Bullet* buulletl = new Bullet(Texture::BULLETL);
		Bullet* buulletm = new Bullet(Texture::BULLETM);
		Bullet* buulletr = new Bullet(Texture::BULLETR);
		
		/*buulletl->InitPosition(this->getPosition().x + 10, this->getPosition().y);
		buulletm->InitPosition(this->getPosition().x + 63, this->getPosition().y);
		buulletr->InitPosition(this->getPosition().x + 88, this->getPosition().y);*/
		buulletm->setPosition(this->getPosition().x + 63, this->getPosition().y);
		buulletr->setPosition(this->getPosition().x + 88, this->getPosition().y);
		buulletl->setPosition(this->getPosition().x + 10, this->getPosition().y);
		buulletl->Move('u');
		buulletm->Move('u');
		buulletr->Move('u');
	
		this->canvas->addBullet(buulletl, 1);
		this->canvas->addBullet(buulletm, 1);
		this->canvas->addBullet(buulletr, 1);

		i = 0;
	}
	else {
		i++;
	}
}
