#pragma once
#include"SFML\Audio.hpp"

class Voice 
{
public:
	static sf::Music BACKROUND;
	static sf::Music EXPLOSION;
	
	static void load();
	Voice();
};

