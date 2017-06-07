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

void Texture::load()
{
	FLASH.loadFromFile("flash.png");
	ENEMY.loadFromFile("image  (22).png");
	BULLETM.loadFromFile("image  (129).png");
	BULLETL.loadFromFile("bulletlr.png");
	BULLETR.loadFromFile("bulletlr.png");
	EXPLOSION1.loadFromFile("image  (82).png");
	EXPLOSION2.loadFromFile("baozha1.jfif");
	EXPLOSION3.loadFromFile("image  (161).png");
	CANVAS.loadFromFile("back.jpg");
	ENEMYBULLET.loadFromFile("image  (5).png");
}

