#include "Canvas.h"

Canvas::Canvas(sf::RenderWindow * window)
{
	this->window = window;
	this->setTexture(this->texture);
}

void Canvas::addFlash(Flash * flash)
{
	this->flash = flash;
}

void Canvas::protectItself()
{
	static int i = 2000;
	static bool IfPressF2 = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F2)&&i==2000) {
		IfPressF2 = true;
		i = 0;
	}
	if (this->flash->skilltwo > 0 &&IfPressF2==true ) {
		IfPressF2 = false;
		this->flash->setshield(true);
		this->flash->skilltwo--;
	}
	if (i < 2000) {
		i++;
	}
}

void Canvas::refresh()
{
	this->window->clear();
	this->window->draw(*this);
	this->window->draw(*(this->flash));

	this->checkPackage();
	this->cleanBulletsandEnemys();

	this->checkEnemy(enemyPlanes,1);
	this->checkEnemy(smallBoss,2);
	this->checkEnemy(bigBoss,3);

	this->enemyMove();

	this->protectItself();

	if (this->checkFlash()) {
		this->flash->state = 1;
		this->flash->dead();
		this->flash->status();
		
		this->flash->setshield(true);
	}
	else {
		this->flash->state = 0;
		this->flash->status();
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
		this->IfPressF11 = true;
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
	static int  j = 1;
	bool ifplusplus = true;
	static bool IfpressF1 = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F1)) {
		IfpressF1 = true;
	}
	for (auto &bullet : this->flashBullets) {
		if (IfpressF1==true&&this->flash->skillone > 0&&j<50000&&j>0 ) {
			bullet->setSpeed(1.5f);
			if (ifplusplus) {
				j++;
			}
			if (j == 10000) {
				this->flash->skillone--;
				IfpressF1 = false;
			}
		}
		else {
			bullet->setSpeed(1.0f);
			j = 1;
		}
		ifplusplus = false;
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
	
	if (this->flash->getScore() >= 100-6&&this->flash->getScore()<=100+6) {
		if (this->ifcreatebigboss) {
			j = 1;
			this->ifcreateenemy = false;
			this->ifcreateenemy = false;
			this->ifcreatebigboss = false;
			Enemy* boss = new Enemy(this, 3,this->IfPressF11);
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
			Enemy* smallboss = new Enemy(this, 2,this->IfPressF11);
			smallboss->setSpeed(enemySpeeed);
			this->smallBoss.insert(smallboss);
			if (i == creatRate) {
				i = 0;
			}
			
		}
	}	
	if (i == creatRate&&ifcreateenemy==true)
	{
		Enemy* enemy = new Enemy(this,1,this->IfPressF11);
		enemy->setSpeed(enemySpeeed);
		this->enemyPlanes.insert(enemy);
		i = 0;
	}
	else {
		i++;
	}
	if (i > 1000) {
		i = 0;
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

					this->flashBullets.erase(bullet);
					if (smallbosshitnum == 9) {
						smallbosshitnum = 0;
						this->flash->increaseScore(this->smallbossScore);
						(*enemy)->statu = 2;
						break;
					}
					//由于只有一个smallBoss，所以直接跳出去，其实这是个bug...
					break;
				}
				bullet++;
			}
			break;
		}

		case 3:
		{
			for (auto bullet = flashBullets.begin(); bullet != (flashBullets.end());) {
				if ((*enemy)->getGlobalBounds().intersects((*bullet)->getGlobalBounds())) {
					bigbosshitnum++;
					this->flashBullets.erase(bullet);
					if (bigbosshitnum == 120) {
						bigbosshitnum = 0;
						this->flash->increaseScore(this->bigbossScore);
						(*enemy)->statu = 3;
						break;
					}
					//由于只有一个bigBoss，所以直接跳出去，其实这是个bug...
					break;
				}
				
				bullet++;
			}
			break;
		}
		}

		if ((*enemy)->statu >= 1 && (*enemy)->statu <= 3) {
			(*enemy)->state();

			enemy = (enemyPlanes).erase(enemy);
			
			smallbosshitnum = 0;
			bigbosshitnum = 0;
			if (mark == 3) {
				this->IfBigbossDead = true;
			}
			continue;
		}
		if ((*enemy)->statu ==0) {
			(*enemy)->state();
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

bool Canvas::checkFlash()
{
	if (this->flash->shield) {
		static int a = 0;
		if (a == 3000) {
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
			this->enemyBullets.erase(bullet);
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
			this->smallbossBullets.erase(bullet);
			return true;
		}
	}
	for (auto &bullet : this->bigbossBullets) {
		if ((bullet)->getGlobalBounds().intersects((this->flash)->getGlobalBounds())) {
			this->bigbossBullets.erase(bullet);
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

void Canvas::addPackage(int randpack)
{
	int static i = 0;
	if (i == 6000&&this->IfBigbossDead == false) {
		Package* package = new Package(this, randpack);
		package->setSpeed(enemySpeeed);
		this->packAges.insert(package);
		i = 0;
	}
	else {
		i++;
	}
}

void Canvas::checkPackage()
{
	auto package = packAges.begin();
	while (package != packAges.end()) {

		if ((*package)->getPosition().y > 1000) {
			delete *package;
			package = (packAges).erase(package);
			continue;
		}
		else {
			(*package)->Move('d');
		}

		this->window->draw(**package);

		if ((*package)->getGlobalBounds().intersects((this->flash)->getGlobalBounds())) {
			switch ((*package)->mark) {
			case 0:
				this->flash->increaseLife();
				break;
			case 1:
				this->flash->skillone++;
				break;
			case 2:
				this->flash->skilltwo++;
				break;
			case 3:
				this->flash->skillthree++;
				break;
			}
			package = packAges.erase(package);
		}

		if (packAges.size()>1) {
			package++;
		}
		else {
			break;
		}
	}
}

void Canvas::cleanBulletsandEnemys()
{
	static int i = 2000;
	static bool IfPressF3 = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F3)&&i==2000) {
		IfPressF3 = true;
		i = 0;
	}
	if (this->flash->skillthree > 0) {
		if (IfPressF3==true) {
	
			for (auto &bullet :this->enemyBullets ) {
				delete  bullet;
			}
			for (auto &bullet : this->smallbossBullets) {
				delete bullet;
			}
			for (auto bullet : this->bigbossBullets) {
				delete  bullet;
			}
			for (auto enemy  : this->enemyPlanes) {
				delete  enemy;
			}
			
			IfPressF3 = false;
			this->flash->skillthree--;
			enemyBullets.clear();
			bigbossBullets.clear();
			smallbossBullets.clear();
			enemyPlanes.clear();
		}
	}
	if (i < 2000) {
		i++;
	}
}

void Canvas::cleanBigBoss()
{
	for (auto &boss : this->bigBoss) {
		delete boss;
		bigBoss.clear();
	}
}

void Canvas::cleanforreset()
{
	for (auto &bullet : this->enemyBullets) {
		delete  bullet;
	}
	for (auto &bullet : this->smallbossBullets) {
		delete bullet;
	}
	for (auto bullet : this->bigbossBullets) {
		delete  bullet;
	}
	for (auto enemy : this->enemyPlanes) {
		delete  enemy;
	}

	enemyBullets.clear();
	bigbossBullets.clear();
	smallbossBullets.clear();
	enemyPlanes.clear();
}


Canvas::~Canvas()
{
}

void Canvas::cleanBullet() {
		
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