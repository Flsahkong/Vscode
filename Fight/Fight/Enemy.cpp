#include "Enemy.h"
#include"Game.h"
#include"Texture.h"


Enemy::Enemy(Canvas *canvas,int a):Plane(canvas)
{
	this->statu = 0;
	switch(a) {
	case 1:
		this->setTexture(Texture::ENEMY);
		this->getRandPosition();
		break;
	case 2:
		this->setTexture(Texture::SMALLBOSS);
		this->randPosition = (rand() % 660) + 1.0f;
		break;
	case 3:
		this->setTexture(Texture::BOSS);
		break;
	}
	this->canvas = canvas;
	
	this->setPosition(randPosition, 0);

}

Enemy::~Enemy()
{
}

void Enemy::getRandPosition()
{
	float rand1 = (rand() % 400) + 1.0f;
	float rand2 = (rand() % 313) + 1.0f;
	this->randPosition = rand1 + rand2;
}

void Enemy::fire(int mark)
{
	static int i = 0;
	static int j = 0;
	static int k = 0;
	switch (mark) {
	case 1: 
	{
		if (i > 1500) {
			Bullet* bullet = new Bullet(Texture::ENEMYBULLET, canvas);
			bullet->setPosition(this->getPosition().x + 30, this->getPosition().y + 35);
			bullet->setTexture(Texture::ENEMYBULLET);

			this->canvas->addBullet(bullet, 0);
			i = 0;
		}
		else {
			i++;
		}
		break;
	}
		
	case 2: 
	{
		if (j > 800) {


			Bullet* smallbossbullet1 = new Bullet(Texture::ENEMYBULLET, canvas);
			Bullet* smallbossbullet2 = new Bullet(Texture::ENEMYBULLET, canvas);
			Bullet* smallbossbullet3 = new Bullet(Texture::ENEMYBULLET, canvas);

			smallbossbullet1->setPosition(this->getPosition().x+20, this->getPosition().y + 120);
			smallbossbullet2->setPosition(this->getPosition().x +45 , this->getPosition().y + 120);
			smallbossbullet3->setPosition(this->getPosition().x + 70, this->getPosition().y + 120);

			smallbossbullet1->setTexture(Texture::ENEMYBULLET);
			smallbossbullet2->setTexture(Texture::ENEMYBULLET);
			smallbossbullet3->setTexture(Texture::ENEMYBULLET);

			this->canvas->addBullet(smallbossbullet1, 2);
			this->canvas->addBullet(smallbossbullet2, 2);
			this->canvas->addBullet(smallbossbullet3, 2);

			j = 0;
		}
		else {
			j++;
		}
		break;
	}
		
	case 3:
	{
		if (k > 800) {
			Bullet* bullet1 = new Bullet(Texture::ENEMYBULLET, canvas);
			Bullet* bullet2 = new Bullet(Texture::ENEMYBULLET, canvas);
			Bullet* bullet3 = new Bullet(Texture::ENEMYBULLET, canvas);
			Bullet* bullet4 = new Bullet(Texture::ENEMYBULLET, canvas);
			Bullet* bullet5 = new Bullet(Texture::ENEMYBULLET, canvas);

			
			bullet1->setPosition(this->getPosition().x + 50, this->getPosition().y + 350);
			bullet2->setPosition(this->getPosition().x + 110, this->getPosition().y + 350);
			bullet3->setPosition(this->getPosition().x + 168, this->getPosition().y + 350);
			bullet4->setPosition(this->getPosition().x + 226, this->getPosition().y + 350);
			bullet5->setPosition(this->getPosition().x + 286, this->getPosition().y + 350);

			bullet1->setTexture(Texture::ENEMYBULLET);
			bullet2->setTexture(Texture::ENEMYBULLET);
			bullet3->setTexture(Texture::ENEMYBULLET);
			bullet4->setTexture(Texture::ENEMYBULLET);
			bullet5->setTexture(Texture::ENEMYBULLET);

			this->canvas->addBullet(bullet1, 3);
			this->canvas->addBullet(bullet2, 3);
			this->canvas->addBullet(bullet3, 3);
			this->canvas->addBullet(bullet4, 3);
			this->canvas->addBullet(bullet5, 3);

			k = 0;
		}
		else {
			k++;
		}
		break;
	}
		
		
	}
	
}

void Enemy::state()
{
	sf::Sprite *Explosion = new sf::Sprite;
	switch (this->statu) {
	case 0:
		break;
	case 1:
		BOOM.play();
		Explosion->setPosition(this->getPosition().x, this->getPosition().y);
		Explosion->setTexture(Texture::EXPLOSION1);
		this->canvas->window->draw(*Explosion);
		this->canvas->window->display();
		statu = 0;
		break;
	case 2:
		BOOM.play();
		Explosion->setPosition(this->getPosition().x, this->getPosition().y);
		Explosion->setTexture(Texture::EXPLOSION2);
		this->canvas->window->draw(*Explosion);
		this->canvas->window->display();
		statu = 0;
		break;
	case 3:
		BOOM.play();
		Explosion->setPosition(this->getPosition().x, this->getPosition().y);
		Explosion->setTexture(Texture::EXPLOSION3);
		this->canvas->window->draw(*Explosion);
		this->canvas->window->display();
		statu = 0;
		break;
	default:
		break;
	}
	
}




