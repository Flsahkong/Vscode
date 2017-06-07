#include "Canvas.h"


Canvas::Canvas(sf::RenderWindow * window)
{
	this->window = window;
	this->setTexture(this->texture);
	this->setScale(1.0f*window->getSize().x / this->texture.getSize().x,
		1.0f*window->getSize().y / this->texture.getSize().y);
}

void Canvas::addFlash(Flash * flash)
{
	this->flash = flash;
}

void Canvas::refresh()
{
	this->window->clear();
	this->window->draw(*this);
	this->window->draw(*(this->flash));

	this->checkEnemy();
	this->enemyMove();

	if (this->checkFlash()) {
		this->flash->state = 1;
		this->flash->dead();
		this->flash->status();
		this->flash->setshield(true);
	}

	for (auto &sprite : this->enemyBullets) {
		this->window->draw(*sprite);
	}
	
	for (auto &sprite : this->flashBullets)
	{
		this->window->draw(*sprite);
	}


}

void Canvas::addBullet(Bullet * bullet, int mark)
{
	
  	switch (mark) {
	case 1:
 		this->flashBullets.insert(bullet);
		break;
	case 0:
		this->enemyBullets.insert(bullet);
		break;
	}
}

void Canvas::moveBullet()
{
	for (auto &bullet : this->flashBullets) {
		bullet->setSpeed(0.6f);
		bullet->Move('u');
	}
	for (auto &bullet : this->enemyBullets) {
		bullet->setSpeed(0.3f);
		bullet->Move('d');
	}
	
}

void Canvas::addEnemy()
{
	static int i = 0;
	
	if (i == creatRate)
	{
		Enemy* enemy = new Enemy(this);
		enemy->setSpeed(enemySpeeed);
		this->enemyPlanes.insert(enemy);
		i = 0;
	}
	else {
		i++;
	}
	

}

void Canvas::setRate(int rate)
{
	this->creatRate = rate;
}

void Canvas::enemyMove()
{
	for (auto enemy = enemyPlanes.begin(); enemy != (this->enemyPlanes.end()); enemy++) {
		(*enemy)->Move('d');
	}
}

void Canvas::enemyfire()
{
	for (auto enemy = this->enemyPlanes.begin(); enemy != this->enemyPlanes.end();) {
		(*enemy)->fire();
		enemy++;
	}
}

void Canvas::checkEnemy()
{
	auto enemy = this->enemyPlanes.begin();
	while (enemy != this->enemyPlanes.end()) {
		auto temp = enemy;
		(*enemy)->statu = 0;
		for (auto bullet = flashBullets.begin(); bullet !=( flashBullets.end());) {
			if ((*enemy)->getGlobalBounds().intersects((*bullet)->getGlobalBounds())) {
				
				(*enemy)->statu = 1;
				this->flashBullets.erase(bullet);
				break;
			}
			bullet++;
		}

		if ((*enemy)->statu >= 1 && (*enemy)->statu <= 3) {
			(*enemy)->state();
			
			enemy = (this->enemyPlanes).erase(enemy);
			continue;
		}

		if ((*enemy)->getPosition().y > 1000) {
			delete *enemy;
			enemy = (this->enemyPlanes).erase(enemy);
			//ºÃÆæ¹ÖÑ½£¿£¿
			continue;
		}

		this->window->draw(**enemy);
		if (temp == enemy) {
			enemy++;
		}

	}
}

bool Canvas::checkFlash()
{
	if (this->flash->shield) {
		static int a = 0;
		if (a == 2000) {
			a = 0;
			this->flash->shield = false;
			this->flash->setTexture(Texture::FLASH);
		}
		else {
			a++;
		}
		return false;
	}
	for (auto &bullet : this->enemyBullets) {
		if ((bullet)->getGlobalBounds().intersects((this->flash)->getGlobalBounds())) {
			return true;
		}
	}
	for (auto &enemy : this->enemyPlanes) {
		if ((enemy)->getGlobalBounds().intersects((this->flash)->getGlobalBounds())) {
			return true;
		}
	}
	return false;
}

Canvas::~Canvas()
{
}

void Canvas::cleanBullet() {

		for (auto flashBullet = this->flashBullets.begin(); flashBullet != (this->flashBullets.end());)
		{
		
			if ((*flashBullet)->getPosition().y<0) {

				delete *flashBullet;

				flashBullet = (this->flashBullets).erase(flashBullet);

			}
			else {
				flashBullet++;
			}
		}

		for (auto enemyBullet = this->enemyBullets.begin(); enemyBullet != (this->enemyBullets.end());){
			if ((*enemyBullet)->getPosition().y > 1000) {
				delete *enemyBullet;

				enemyBullet = (this->enemyBullets).erase(enemyBullet);
			}
			else {
				enemyBullet++;
			}
		}

}