#include "inputhandler.h"
#include <SFML\Window\Keyboard.hpp>
#include "SFML\System\Time.hpp"

InputHandler::InputHandler(Actor* Actor)
{
	actor = Actor;
	buttonUp = new MoveUpCommand;
	buttonDown = new MoveDownCommand;
	buttonLeft = new MoveLeftCommand;
	buttonRight = new MoveRightCommand;
	buttonSpace = new FireCommmand;
}

void InputHandler::handleInput(sf::Time dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		buttonUp->execute(*actor, dt);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		buttonDown->execute(*actor, dt);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		buttonLeft->execute(*actor, dt);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		buttonRight->execute(*actor, dt);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		buttonSpace->execute(*actor, dt);
		
}

InputHandler::~InputHandler()
{
	delete buttonDown;
	delete buttonLeft;
	delete buttonRight;
	delete buttonUp;
	delete buttonSpace;
}

