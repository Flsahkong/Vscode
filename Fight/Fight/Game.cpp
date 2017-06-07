#include "Game.h"

Game::Game(Canvas * canvas)
{
	this->canvas = canvas;

}

void Game::start()
{
	canvas->flash->InitPsition();
	this->BMG.play();
	while (canvas->window->isOpen()) {

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
		}//¿ª»ð
		canvas->addEnemy();
		canvas->enemyfire();
		canvas->moveBullet();
		canvas->cleanBullet();
		canvas->refresh();
		canvas->window->display();
	}
}

Game::~Game()
{
}
