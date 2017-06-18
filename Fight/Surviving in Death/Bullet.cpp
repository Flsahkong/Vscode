#include "Bullet.h"


Bullet::Bullet(sf::Texture texture, Canvas*canvas)
{
	this->setTexture(texture);
	this->setScale(scale_x, scale_y);
}

void Bullet::InitPosition(float x,float y)
{
	this->setPosition(x,y);
}

Bullet::~Bullet()
{
}
