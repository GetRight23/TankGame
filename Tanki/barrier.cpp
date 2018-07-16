#include "barrier.h"

Barrier::Barrier()
{
	size = sf::Vector2f(100, 100);
	setSize(size);
	setFillColor(sf::Color::Green);
}