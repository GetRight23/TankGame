#include "barrier.h"

Barrier::Barrier()
{
	texture = new sf::Texture;
	std::string filename = "Aleg.jpg";
	texture->loadFromFile(filename);
	setTexture(texture);
	size = sf::Vector2f(100, 100);
	setSize(size);
	//setFillColor(sf::Color::Green);
}