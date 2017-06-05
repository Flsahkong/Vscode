#pragma once
#include "E:\SFML-2.4.2\include\SFML\Graphics\Sprite.hpp"
#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include<unordered_set>
#include"Enemy.h"
#include"Flash.h"
#include"Bullet.h"
#include"Texture.h"

using namespace std;
class Canvas :
	public sf::Sprite
{
private:
	
	unordered_set<Enemy * > enemyPlanes;
	unordered_set<Bullet * > flashBullets;
	unordered_set<Bullet * > enemyBullets;
	
	
	sf::Texture texture = Texture::CANVAS;
	
public:

	sf::RenderWindow *window;
	Flash* flash;


	Canvas(sf::RenderWindow *window);
	~Canvas();

	void cleanBullet();

	void addFlash(Flash* flash);
	void refresh();


	void addBullet(Bullet*bullet14,int mark);
	void moveBullet();


	void addEnemy();

};

