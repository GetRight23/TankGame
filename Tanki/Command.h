#pragma once
#include "actor.h"
#include "SFML\System\Clock.hpp"
#include "SFML\System\Time.hpp"
#include <SFML\System.hpp>
#include <iostream>

class Command
{
public:
	virtual ~Command() {}
	virtual void execute(Actor& actor, sf::Time dt) = 0;
};

class MoveUpCommand : public Command
{
public:
	void execute(Actor& actor, sf::Time dt)
	{
		actor.moveUp(dt);
	}
};

class MoveDownCommand : public Command
{
public:
	void execute(Actor& actor, sf::Time dt)
	{
		actor.moveDown(dt);
	}
};

class MoveLeftCommand : public Command
{
public:
	void execute(Actor& actor, sf::Time dt)
	{
		actor.moveLeft(dt);
	}
};

class MoveRightCommand : public Command
{
public:
	void execute(Actor& actor, sf::Time dt)
	{
		actor.moveRight(dt);
	}
};

class FireCommmand : public Command
{
public:
	void execute(Actor& actor, sf::Time dt)
	{
		actor.fire(dt);
		std::cout << "xui";
	}
};


