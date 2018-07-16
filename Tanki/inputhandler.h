#pragma once

#include "Command.h"
#include "actor.h"


class InputHandler
{
private:
	Actor* actor;
	Command* buttonUp;
	Command* buttonDown;
	Command* buttonRight;
	Command* buttonLeft;
	Command* buttonSpace;
public:
	InputHandler(Actor* Actor);
	~InputHandler();
	void handleInput(sf::Time dt);
};
