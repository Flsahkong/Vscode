#include "Game.h"

void Game::showInformation()
{
	updateInformation();
	char s[100];
	sprintf(s, "Life:%d\nScore:%d\nSkill One:%d\nSkill Two:%d\nSkill Three:%d", this->nowlife, this->score,this->skillone,this->skilltwo,this->skillthree);
	Information.setFont(Texture::FRONT);
	Information.setString(s);
	Information.setCharacterSize(24);
	Information.setFillColor(sf::Color::White);
	Information.setPosition(0.0f, 0.0f);
	this->canvas->window->draw(Information);
}

void Game::updateInformation()
{
	this->score = this->canvas->flash->getScore();
	this->nowlife = this->canvas->flash->getNowlife();
	this->skillone = this->canvas->flash->getSkillOne();
	this->skilltwo = this->canvas->flash->getSkillTwo();
	this->skillthree = this->canvas->flash->getSkillThree();
}

void Game::gengeraterand()
{
	srand((unsigned)time(0));
	this->packrand = rand() % 4;
}

Game::Game(Canvas * canvas)
{
	this->canvas = canvas;
	this->BMG.setVolume(20);
}

void Game::start()
{
	canvas->flash->InitPsition();
	this->BMG.play();
	while (canvas->window->isOpen()) {
		gengeraterand();
		sf::Event event;
		while (canvas->window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				canvas->window->close();
				return;
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			if (canvas->flash->getPosition().x > 0) {
				canvas->flash->Move('l');
			}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			if (canvas->flash->getPosition().x <656) {
				canvas->flash->Move('r');
			}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			if (canvas->flash->getPosition().y > 0) {
				canvas->flash->Move('u');
			}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			if (canvas->flash->getPosition().y <890) {
				canvas->flash->Move('d');
			}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			this->canvas->flash->fire();
		}

		
		canvas->addEnemy();
		canvas->addPackage(this->packrand);
		canvas->enemyfire();
		canvas->moveBullet();
		canvas->refresh();
		showInformation();
 		canvas->window->display();
		canvas->cleanBullet();
	}
}

Game::~Game()
{
}
