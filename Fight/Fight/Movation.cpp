#include "Movation.h"



void Movation::Move(char c)
{
	sf::Vector2f direction;
	switch (c) {
	case 'l':
		direction.x = -1;	direction.y = 0;	break;
	case 'r':
		direction.x = 1;	direction.y = 0;	break;
	case 'u':
		direction.x = 0;	direction.y = -1;	break;
	case 'd':
		direction.x = 0;	direction.y = 1;	break;
	}
		

	sf::Vector2f temp;
	temp.x = direction.x*speed;
	temp.y = direction.y*speed;
	this->setPosition(this->getPosition() + temp);

}

void Movation::setSpeed(float speed)
{
	this->speed = speed;
}


Movation::Movation()
{
}


Movation::~Movation()
{
}
