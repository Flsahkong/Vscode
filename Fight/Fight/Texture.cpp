#include "Texture.h"

//为什么要这样？
sf::Texture Texture::BULLETM;
sf::Texture Texture::BULLETL;
sf::Texture Texture::BULLETR;
sf::Texture Texture::ENEMY;
sf::Texture Texture::FLASH;
sf::Texture Texture::EXPLOSION1;
sf::Texture Texture::EXPLOSION2;
sf::Texture Texture::EXPLOSION3;
sf::Texture Texture::CANVAS;
sf::Texture Texture::ENEMYBULLET;
sf::Texture Texture::BOSS;
sf::Texture Texture::SMALLBOSS;
sf::Font Texture::FRONT;
sf::Font Texture::FRONTMESS;

sf::Texture Texture::ADDLIFE;
sf::Texture Texture::SKILLONE;
sf::Texture Texture::SKILLTWO;
sf::Texture Texture::SKILLTHREE;

sf::Texture Texture::TOUMING;

sf::Texture Texture::STARTSCTION;
void Texture::load()
{
	FLASH.loadFromFile("flash.png");
	ENEMY.loadFromFile("image  (22).png");
	BOSS.loadFromFile("BOSSS.png");
	SMALLBOSS.loadFromFile("smallboss.png");

	BULLETM.loadFromFile("image  (129).png");
	BULLETL.loadFromFile("bulletlr.png");
	BULLETR.loadFromFile("bulletlr.png");
	ENEMYBULLET.loadFromFile("image  (5).png");

	EXPLOSION1.loadFromFile("image  (82).png");
	EXPLOSION2.loadFromFile("baozha1.png");
	EXPLOSION3.loadFromFile("image  (161).png");

	CANVAS.loadFromFile("timgnew.jpg");
	
	FRONT.loadFromFile("BertramLP.TTF");
	FRONTMESS.loadFromFile("CaflischScriptPro-Regular.otf");

	ADDLIFE.loadFromFile("image  (111).png");
	SKILLONE.loadFromFile("image  (113).png");
	SKILLTWO.loadFromFile("image  (109).png");
	SKILLTHREE.loadFromFile("image  (114).png");

	TOUMING.loadFromFile("touming.png");

	STARTSCTION.loadFromFile("startpic.jpg");
}

