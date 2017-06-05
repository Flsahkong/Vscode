#include "Texture.h"

//为什么要这样？
sf::Texture Texture::BULLETM;
sf::Texture Texture::BULLETL;
sf::Texture Texture::BULLETR;
sf::Texture Texture::ENEMY;
sf::Texture Texture::FLASH;
sf::Texture Texture::EXPLOSION;
sf::Texture Texture::CANVAS;

void Texture::load()
{
	FLASH.loadFromFile("image  (137).png");
	ENEMY.loadFromFile("diji9.jfif");
	BULLETM.loadFromFile("image  (127).png");
	BULLETL.loadFromFile("image  (125).png");
	BULLETL.loadFromFile("image  (125).png");
	EXPLOSION.loadFromFile("baozha1.jfif");
	CANVAS.loadFromFile("back.jpg");
}

