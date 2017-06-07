#pragma once
#include"SFML\Audio.hpp"

class Voice 
{
public:
	static sf::Music BACKROUND;
	static sf::Music EXPLOSION;
	static sf::Music BOOM;
	static void load();
	Voice();
};

