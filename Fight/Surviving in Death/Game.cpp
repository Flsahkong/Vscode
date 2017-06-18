#include "Game.h"

void Game::showInformation()
{
	this->updateInformation();
	char s[100];
	sprintf(s, "Life:%d\nScore:%d\nSkill One:%d\nSkill Two:%d\nSkill Three:%d", this->nowlife, this->score,this->skillone,this->skilltwo,this->skillthree);
	Information.setFont(Texture::FRONT);
	Information.setString(s);
	Information.setCharacterSize(24);
	Information.setFillColor(sf::Color::White);
	Information.setPosition(0.0f, 0.0f);
	this->canvas->window->draw(Information);
}
void Game::showStartInfo()
{
	char strname[20];
	sprintf(strname, "Surviving In Death\n");
	StartInfoOne.setFont(Texture::FRONT);
	StartInfoOne.setString(strname);
	StartInfoOne.setCharacterSize(45);
	StartInfoOne.setFillColor(sf::Color::White);
	StartInfoOne.setPosition(180.0f, 300.0f);
	this->canvas->window->draw(StartInfoOne);

	char strguide[60];
	sprintf(strguide, "Press Enter to start\nPress Space to view assistance");
	StartInfoTwo.setFont(Texture::FRONTMESS);
	StartInfoTwo.setString(strguide);
	StartInfoTwo.setCharacterSize(30);
	StartInfoTwo.setFillColor(sf::Color::White);
	StartInfoTwo.setPosition(230.0f, 450.0f);
	this->canvas->window->draw(StartInfoTwo);
}

void Game::showStartNextInfo()
{
	char strmessone[500];
	sprintf(strmessone, "Your Plane has three skills:\n\nThe first is to accelerate your bullets\nThe second is to have a shield\nThe third is to clean all the enemys and its bullets(except bosses)\nPress F1 F2 and F3 to achieve.\n\nPress F11 to shut the music down.\nPress the Arrows to move your plane.\nPress Space to fire\nPress Enter to start.\n\nThis game maybe a little difficult\nEnjoy it!");
	StartInfoThree.setFont(Texture::FRONTMESS);
	StartInfoThree.setString(strmessone);
	StartInfoThree.setCharacterSize(30);
	StartInfoThree.setFillColor(sf::Color::White);
	StartInfoThree.setPosition(20.0f, 250.0f);
	this->canvas->window->draw(StartInfoThree);
}

void Game::showFinalInfo()
{
	char strr[40];
	char str[30];
	switch (this->IsWin) {
	case true:
		sprintf(str, "Congratulations!\n    You win!");
		sprintf(strr, "Press Esc to exit\nPress Home to restart");

		break;
	case false:
		sprintf(str, "Defeat");
		sprintf(strr, "Press Esc to exit\nPress Home to restart");
	}
	WinInfoTwo.setFont(Texture::FRONT);
	WinInfoTwo.setString(str);
	WinInfoTwo.setCharacterSize(45);
	WinInfoTwo.setFillColor(sf::Color::White);
	WinInfoTwo.setPosition(180.0f, 300.0f);
	this->canvas->window->draw(WinInfoTwo);

	WinInfo.setFont(Texture::FRONTMESS);
	WinInfo.setString(strr);
	WinInfo.setCharacterSize(30);
	WinInfo.setFillColor(sf::Color::White);
	WinInfo.setPosition(180.0f, 450.0f);
	this->canvas->window->draw(WinInfo);
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
restart:
	//the begin action
	canvas->setTexture(Texture::STARTSCTION);
	while (canvas->window->isOpen()) {
		sf::Event event;
		while (canvas->window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				canvas->window->close();
				return;
			}
		}
		this->canvas->window->draw(*canvas);
		this->showStartInfo();
		this->canvas->window->display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			goto mainloop;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			break;
		}
	}

	//the begin action two
	while (canvas->window->isOpen()) {
		sf::Event event;
		while (canvas->window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				canvas->window->close();
				return;
			}
		}
		this->canvas->window->draw(*canvas);
		this->showStartNextInfo();
		this->canvas->window->display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
			break;
		}
	}

mainloop:

	// the main loop
	canvas->flash->InitPsition();
	this->BMG.play();
	canvas->setTexture(Texture::CANVAS);
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
			this->BMG.setVolume(0);
		}
		canvas->addEnemy();
		canvas->addPackage(this->packrand);
		canvas->enemyfire();
		canvas->moveBullet();
		canvas->refresh();
		this->showInformation();

		
		if (this->canvas->flash->getNowlife()< 0) {
			this->IsWin = false;
			break;
		}
		if (this->canvas->IfBigbossDead) {
			this->FlashMoveAutomatically();

			if (this->canvas->flash->getPosition().y < 0) {
				this->IsWin = true;
				break;
			}
		}

 		canvas->window->display();
		canvas->cleanBullet();
	}

	//the end action
	canvas->setTexture(Texture::STARTSCTION);
	while (canvas->window->isOpen()) {
		sf::Event event;
		while (canvas->window->pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				canvas->window->close();
				return;
			}
		}
		this->canvas->window->draw(*canvas);
		this->showFinalInfo();
		this->canvas->window->display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			break;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Home)) {

			this->canvas->flash->reset();
			this->canvas->cleanBigBoss();
			this->canvas->cleanforreset();

			this->canvas->IfBigbossDead = false;
			this->canvas->ifcreatebigboss = true;
			this->canvas->ifcreateenemy = true;
			this->canvas->ifcreatesmallboss = true;
 			goto restart;
		}
	}

}

void Game::FlashMoveAutomatically()
{
	this->canvas->flash->Move('u');
	
}

Game::~Game()
{
}
