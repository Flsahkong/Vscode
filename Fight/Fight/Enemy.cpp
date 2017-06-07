#include "Enemy.h"
#include"Game.h"
#include"Texture.h"

Enemy::Enemy(Canvas *canvas):Plane(canvas)
{
	
	this->setTexture(Texture::ENEMY);
	this->canvas = canvas;
	this->getRandPosition();
	this->setPosition(randPosition, 0);

}

Enemy::~Enemy()
{
}

void Enemy::getRandPosition()
{
	
	this->randPosition = (rand() % 713) + 1.0f;
}

void Enemy::fire()
{
	static int i = 0;
	if (i > 1000) {
		Bullet* bullet = new Bullet(Texture::ENEMYBULLET, canvas);
		bullet->setPosition(this->getPosition().x + 30, this->getPosition().y + 35);
		bullet->setTexture(Texture::ENEMYBULLET);
		bullet->setSpeed(0.3f);

		this->canvas->addBullet(bullet, 0);

		i = 0;
	}
	else {
		i++;
	}
}



