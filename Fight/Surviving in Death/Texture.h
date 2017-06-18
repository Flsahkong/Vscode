#pragma once
#include "E:\SFML-2.4.2\include\SFML\Graphics\Texture.hpp"
#include<SFML\Graphics.hpp>
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
	static sf::Texture BOSS;
	static sf::Texture SMALLBOSS;
	static sf::Font FRONT;
	static sf::Font FRONTMESS;
	
	static sf::Texture ADDLIFE;
	static sf::Texture SKILLONE;
	static sf::Texture SKILLTWO;
	static sf::Texture SKILLTHREE;

	static sf::Texture TOUMING;
	

	static sf::Texture STARTSCTION;

	static void load();
};

