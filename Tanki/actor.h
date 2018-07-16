#pragma once
#include "SFML\System\Time.hpp"

class Actor
{
public:
	virtual ~Actor() {}
	virtual void moveRight(sf::Time dt) = 0;
	virtual void moveLeft(sf::Time dt) = 0;
	virtual void moveUp(sf::Time dt) = 0;
	virtual void moveDown(sf::Time dt) = 0;
	virtual void fire(sf::Time dt) = 0;
};
