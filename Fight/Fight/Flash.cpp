#include "Flash.h"
#include"Canvas.h"
#include"Texture.h"
#include<iostream>

Flash::Flash(Canvas*canvas):Plane(canvas)
{
	this->setSpeed(0.6f);
	this->position.x = 343;
	this->position.y = 890;

	this->setTexture(Texture::FLASH);
	this->setScale(0.8f, 0.8f);
	this->canvas = canvas;
	
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
		 
        Bullet* buulletl = new Bullet(Texture::BULLETL,canvas);
		Bullet* buulletm = new Bullet(Texture::BULLETM,canvas);
		Bullet* buulletr = new Bullet(Texture::BULLETR,canvas);
		
		buulletm->setPosition(this->getPosition().x + 40, this->getPosition().y-10);
		buulletr->setPosition(this->getPosition().x + 70, this->getPosition().y);
		buulletl->setPosition(this->getPosition().x + 10, this->getPosition().y);
		buulletl->setTexture(Texture::BULLETL);
		buulletl->setScale(0.8f, 0.8f);
		buulletm->setScale(0.8f, 0.8f);
		buulletr->setScale(0.8f, 0.8f);
		buulletm->setTexture(Texture::BULLETM);
		buulletr->setTexture(Texture::BULLETR);

  		this->canvas->addBullet(buulletl, 1);
		this->canvas->addBullet(buulletm, 1);
		this->canvas->addBullet(buulletr, 1);
		
		i = 0;
	}
	else {
		i++;
	}
}

void Flash::setshield(bool shield)
{
	this->shield = shield;
}

int Flash::getNowlife()
{
	return this->life;
}

void Flash::increaseLife()
{
	this->life++;
}

void Flash::dead()
{
	if (this->getNowlife()) {
		//
		//
		//
		//这里还有gameover的东西！！！！！！
		//
		//
		//
	}
	else {
		
		this->life--;
	}
}

void Flash::status()
{
	sf::Sprite *Explosion = new sf::Sprite;
	switch (this->state) {
	case 0:
		break;
	case 1:
		BOOM.play();
		Explosion->setPosition(this->getPosition().x, this->getPosition().y);
		Explosion->setTexture(Texture::EXPLOSION1);
		this->canvas->window->draw(*Explosion);
		this->InitPsition();
		state = 0;
		break;
	}
}
