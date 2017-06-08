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
	case '4':
		direction.x = -0.94f;    direction.y = 0.34f;   break;
	case '1':
		direction.x = -0.7f;    direction.y = 0.7f;   break;
	case '2':
		direction.x = -0.34f;    direction.y = 0.94f;   break;
	case '6':
		direction.x = 0.94f;    direction.y = 0.34f;   break;
	case '3':
		direction.x = 0.7f;    direction.y = 0.7f;   break;
	case '5':
		direction.x = 0.34f;    direction.y = 0.94f;   break;
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
