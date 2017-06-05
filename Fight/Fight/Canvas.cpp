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

	for (auto &sprite : this->flashBullets)
	{
		this->window->draw(*sprite);
	}


}

void Canvas::addBullet(Bullet * bullet14, int mark)
{
	Bullet* temp = new Bullet(Texture::BULLETM);
	temp = bullet14;
	bullet14;
	switch (mark) {
	case 1:
		std::cout << "11"<<endl;
		std::cout << bullet14;
		this->flashBullets.insert(bullet14);
		std::cout << "456";
		break;
	case 0:

		enemyBullets.insert(bullet14);
		//this->enemyBullets.insert(bullet14);
		break;
	}
}

void Canvas::moveBullet()
{
	for (auto &bullet : this->flashBullets) {
		bullet->Move('u');
	}
	
}

void Canvas::addEnemy()
{
	
}

Canvas::~Canvas()
{
}
void Canvas::cleanBullet() {

	for (auto bullet = this->flashBullets.begin(); bullet != (this->flashBullets.end());)
	{
		if ((*bullet)->getPosition().y<0) {

			delete *bullet;

			bullet = (this->flashBullets).erase(bullet);

		}
		else {
			bullet++;
		}
	}

}