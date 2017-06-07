#include "Enemy.h"
#include"Game.h"
#include"Texture.h"

Enemy::Enemy(Canvas *canvas):Plane(canvas)
{
	this->statu = 0;
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
	if (i > 1500) {
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

void Enemy::state()
{
	sf::Sprite *Explosion=new sf::Sprite;
	switch (this->statu) {
	case 0:
		this->Move('d');
		break;
	case 1:
		BOOM.play();
		Explosion->setPosition(this->getPosition().x, this->getPosition().y);
		Explosion->setTexture(Texture::EXPLOSION1);
		this->canvas->window->draw(*Explosion);
		this->canvas->window->display();
		std::cout << this->getPosition().x << std::endl;
		std::cout << this->getPosition().y << std::endl;
		statu = 0;
		break;
	case 2:
		BOOM.play();
		Explosion->setPosition(this->getPosition().x, this->getPosition().y);
		Explosion->setTexture(Texture::EXPLOSION2);
		this->canvas->window->draw(*Explosion);
		
		break;
	case 3:
		BOOM.play();
		Explosion->setPosition(this->getPosition().x, this->getPosition().y);
		Explosion->setTexture(Texture::EXPLOSION3);
		this->canvas->window->draw(*Explosion);
		
		break;
	default:
		break;
	}
	
}




