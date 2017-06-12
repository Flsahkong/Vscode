#include "Flash.h"
#include"Canvas.h"
#include"Texture.h"
#include<iostream>

Flash::Flash(Canvas*canvas):Plane(canvas)
{
	this->setSpeed(0.9f);
	this->position.x = 343;
	this->position.y = 890;

	this->setTexture(Texture::FLASH);
	this->setScale(0.8f, 0.8f);
	this->canvas = canvas;
	
	this->BOOM.setVolume(50);
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

int Flash::getSkillOne()
{
	return this->skillone;
}

int Flash::getSkillTwo()
{
	return this->skilltwo;
}

int Flash::getSkillThree()
{
	return this->skillthree;
}

void Flash::reset()
{
	this->life = 5;
	this->skillone = 3;
	this->skilltwo = 3;
	this->skillthree = 3;
}

void Flash::increaseLife()
{
	this->life++;
}

void Flash::dead()
{
	this->life--;
}

void Flash::status()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
		this->BOOM.setVolume(0);
	}
	switch (this->state) {
	case 0:
		break;
	case 1:
		BOOM.play();
		touming.setTexture(Texture::TOUMING);
		Explosion->setPosition(this->getPosition().x, this->getPosition().y);
		Explosion->setTexture(Texture::EXPLOSION1);
		this->canvas->window->draw(*Explosion);
		this->canvas->window->draw(touming);
		this->InitPsition();
		state = 0;
		break;
	}
}

void Flash::increaseScore(int score)
{
	this->score += score;
}

void Flash::cleanScore()
{
	this->score = 0;
}

int Flash::getScore()
{
	return this->score;
}


