#include "Voice.h"

sf::Music Voice::BACKROUND;
sf::Music Voice::EXPLOSION;


void Voice:: load()
{
	BACKROUND.openFromFile("OpeningTitles.ogg");
	EXPLOSION.openFromFile("baozhasheng1.wav");
}


Voice::Voice()
{
	
}
