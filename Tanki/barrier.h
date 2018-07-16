#pragma once
#include "SFML\Graphics\RectangleShape.hpp"
#include <SFML\System\Vector2.hpp>

class Barrier : public sf::RectangleShape
{
private:
	sf::Vector2f size;
	sf::Texture* texture;
public:
	Barrier();
	~Barrier() {}
};