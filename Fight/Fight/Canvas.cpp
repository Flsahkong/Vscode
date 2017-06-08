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

	this->checkEnemy(enemyPlanes,1);
	this->checkEnemy(smallBoss,2);
	this->checkEnemy(bigBoss,3);

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
	for (auto &sprite : this->smallbossBullets) {
		this->window->draw(*sprite);
	}
	for (auto &sprite : this->bigbossBullets) {
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
	case 2:
		this->smallbossBullets.insert(bullet);
		break;
	case 3:
		this->bigbossBullets.insert(bullet);
		break;
	}
}

void Canvas::moveBullet()
{
	int i=1;
	for (auto &bullet : this->flashBullets) {
		bullet->setSpeed(1.0f);
		bullet->Move('u');
	}
	for (auto &bullet : this->enemyBullets) {
		bullet->setSpeed(0.3f);
		bullet->Move('d');
	}
	for (auto &bullet : this->smallbossBullets) {
		bullet->setSpeed(0.4f);
		if (i % 3 == 1) {
			bullet->Move('1');
			i++;
		}else if(i % 3 == 2) {
			bullet->Move('d');
			i++;
		}
		else {
			bullet->Move('3');
			i++;
		}
		
	}
	for (auto &bullet : this->bigbossBullets) {
		bullet->setSpeed(0.5f);
		if (i % 5 == 1) {
			bullet->Move('4');
			i++;
		}
		else if (i % 5 == 2) {
			bullet->Move('2');
			i++;
		}
		else if (i % 5 == 3) {
			bullet->Move('d');
			i++;
		}
		else if (i % 5 == 4) {
			bullet->Move('5');
			i++;
		}
		else {
			bullet->Move('6');
			i++;
		}
	}
	
}

void Canvas::addEnemy()
{
	static int j = 1;
	static int i = 0;
	static bool ifcreatesmallboss = true;
	static bool ifcreateenemy = true;
	static bool ifcreatebigboss = true;
	if (this->flash->getScore() >= 100-6&&this->flash->getScore()<=100+6) {
		if (ifcreatebigboss) {
			ifcreateenemy = false;
			ifcreateenemy = false;
			ifcreatebigboss = false;
			Enemy* boss = new Enemy(this, 3);
			boss->setScale(1.0f,1.0f);
			boss->setPosition(225.0f, 0.0f);
			boss->setSpeed(bigbossSpeed);
			this->bigBoss.insert(boss);
		}
	}
	if (this->flash->getScore()>=(30*j-2)&&this->flash->getScore()<=30*j+2) {
		if (this->flash->getScore() != 0&&ifcreatesmallboss==true) {
			j++;
			ifcreatesmallboss = true;
			Enemy* smallboss = new Enemy(this, 2);
			smallboss->setSpeed(enemySpeeed);
			this->smallBoss.insert(smallboss);
			if (i == creatRate) {
				i = 0;
			}
			
		}
	}	
	if (i == creatRate&&ifcreateenemy==true)
	{
		Enemy* enemy = new Enemy(this,1);
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
	for (auto enemy = this->smallBoss.begin(); enemy != (this->smallBoss.end()); enemy++) {
		(*enemy)->Move('d');
	}
}

void Canvas::enemyfire()
{
	for (auto enemy = this->enemyPlanes.begin(); enemy != this->enemyPlanes.end();) {
		(*enemy)->fire(1);
		enemy++;
	}
	for (auto boss = this->bigBoss.begin(); boss != this->bigBoss.end();) {
		(*boss)->fire(3);
		boss++;
	}
	for (auto smallboss = this->smallBoss.begin(); smallboss != this->smallBoss.end();) {
 
		(*smallboss)->fire(2);
		smallboss++;
	}
}

void Canvas::checkEnemy(unordered_set<Enemy*> &enemyPlanes,int mark)
{
	static int smallbosshitnum = 0;
	static int bigbosshitnum = 0;
	auto enemy = enemyPlanes.begin();
	while (enemy != enemyPlanes.end()) {
		auto temp = enemy;
		(*enemy)->statu = 0;
		switch (mark) {
		case 1:
		{
			for (auto bullet = flashBullets.begin(); bullet != (flashBullets.end());) {
				if ((*enemy)->getGlobalBounds().intersects((*bullet)->getGlobalBounds())) {
					this->flash->increaseScore(this->enemyScore);
					(*enemy)->statu = 1;
					this->flashBullets.erase(bullet);
					break;
				}
				bullet++;
			}
			break;
		}

		case 2:
		{
			for (auto bullet = flashBullets.begin(); bullet != (flashBullets.end());) {
				if ((*enemy)->getGlobalBounds().intersects((*bullet)->getGlobalBounds())) {
					smallbosshitnum++;
					bullet = this->flashBullets.erase(bullet);
					if (smallbosshitnum == 9) {
						smallbosshitnum = 0;
						this->flash->increaseScore(this->smallbossScore);
						(*enemy)->statu = 2;
						break;
					}
				}
				if (flashBullets.size()) {
					bullet++;
				}
				else {
					break;
				}

			}
			break;
		}

		/*case 3:
		{
			for (auto bullet = flashBullets.begin(); bullet != (flashBullets.end());) {
				if ((*enemy)->getGlobalBounds().intersects((*bullet)->getGlobalBounds())) {
					bigbosshitnum++;
					bullet = this->flashBullets.erase(bullet);
					if (bigbosshitnum == 120) {
						bigbosshitnum = 0;
						this->flash->increaseScore(this->bigbossScore);
						(*enemy)->statu = 3;
						break;
					}
				}
				if (flashBullets.size()) {
					bullet++;
				}
				else {
					break;
				}

			}
			break;
		}*/


		if ((*enemy)->statu >= 1 && (*enemy)->statu <= 3) {
			(*enemy)->state();

			enemy = (enemyPlanes).erase(enemy);
			smallbosshitnum = 0;
			bigbosshitnum = 0;
			continue;
		}

		if ((*enemy)->getPosition().y > 1000) {
			delete *enemy;
			enemy = (enemyPlanes).erase(enemy);
			continue;
		}

		this->window->draw(**enemy);
		if (temp == enemy) {
			enemy++;
		}
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
	for (auto &bullet : this->smallbossBullets) {
		if ((bullet)->getGlobalBounds().intersects((this->flash)->getGlobalBounds())) {
			return true;
		}
	}
	for (auto &bullet : this->bigbossBullets) {
		if ((bullet)->getGlobalBounds().intersects((this->flash)->getGlobalBounds())) {
			return true;
		}
	}
	for (auto &enemy : this->smallBoss) {
		if ((enemy)->getGlobalBounds().intersects((this->flash)->getGlobalBounds())) {
			return true;
		}
	}
	for (auto &enemy : this->bigBoss) {
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
		//
		//
		//
			//这里是不是有一个bug？？
		//
		//
		//
		//
		for (auto flashBullet = this->flashBullets.begin(); flashBullet != (this->flashBullets.end());)
		{

			if ((*flashBullet)->getPosition().y < 0) {
				delete *flashBullet;
				flashBullet = (this->flashBullets).erase(flashBullet);

			}
			else {
				flashBullet++;
			}
		}
		for (auto smallbu = this->smallbossBullets.begin(); smallbu != (this->smallbossBullets.end());) {
			if ((*smallbu)->getPosition().y > 1000 || (*smallbu)->getPosition().x < -29 || (*smallbu)->getPosition().x>800) {
				delete *smallbu;
				smallbu = (this->smallbossBullets).erase(smallbu);
			}
			else {
				smallbu++;
			}
		}
		for (auto bossbu = this->bigbossBullets.begin(); bossbu != (this->bigbossBullets.end());){
			if ((*bossbu)->getPosition().y > 1000 || (*bossbu)->getPosition().x < -29 || (*bossbu)->getPosition().x>800) {
				delete *bossbu;
				bossbu = (this->bigbossBullets).erase(bossbu);
			}
			else {
				bossbu++;
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