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
#include"Package.h"

using namespace std;
class Canvas :
	public sf::Sprite
{
private:
	int creatRate = 1000;
	float enemySpeeed = 0.2f;
	float bigbossSpeed = 0.0f;
	int enemyScore = 3;
	int smallbossScore = 7;
	int bigbossScore = 100;

	unordered_set<Enemy * > enemyPlanes;
	unordered_set<Enemy*> bigBoss;
	unordered_set<Enemy*> smallBoss;

	unordered_set<Bullet * > flashBullets;
	unordered_set<Bullet * > enemyBullets;
	unordered_set<Bullet* >  smallbossBullets;
	unordered_set<Bullet* >  bigbossBullets;

	unordered_set<Package*> packAges;

	sf::Texture texture = Texture::CANVAS;
	
public:

	sf::RenderWindow *window;
	Flash* flash;


	Canvas(sf::RenderWindow *window);
	~Canvas();

	void cleanBullet();

	void addFlash(Flash* flash);
	void protectItself();
	void refresh();


	void addBullet(Bullet*bullet,int mark);
	void moveBullet();


	void addEnemy();
	void setRate(int rate);
	void enemyMove();
	void enemyfire();

	void checkEnemy(unordered_set<Enemy*> &enemyPlanes,int mark);
	bool checkFlash();

	void addPackage(int randpack);
	void checkPackage();

	void cleanBulletsandEnemys();
};

