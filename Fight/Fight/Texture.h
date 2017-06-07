#pragma once
#include "E:\SFML-2.4.2\include\SFML\Graphics\Texture.hpp"
class Texture :
	public sf::Texture
{
public:
	static sf::Texture ENEMYBULLET;
	static sf::Texture FLASH;
	static sf::Texture ENEMY;
	static sf::Texture BULLETM;
	static sf::Texture BULLETL;
	static sf::Texture BULLETR;
	static sf::Texture EXPLOSION1;
	static sf::Texture EXPLOSION2;
	static sf::Texture EXPLOSION3;
	static sf::Texture CANVAS;
	
	
	static void load();


};

