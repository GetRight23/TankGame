#pragma once
#include "barrier.h"
#include "SFML\Graphics\RectangleShape.hpp"
#include <vector>
#include "tank.h"
#include "Bullet.h"
#include <list>


class Map : public sf::RectangleShape
{
private:
	Tank* tank;
	std::vector<Barrier*> vecBar;
	sf::Vector2f size;
	sf::Texture* texture;
	int outlinethickness;
public:
	Map(Tank* Tank);
	~Map() { delete texture; }
	const sf::Vector2f& getSize() { return size; }
	void loadMap();
	const std::vector<Barrier*>& getBarriers() { return vecBar; }
	bool checkCollision();
	bool checkCollision(std::list<Bullet*>& bullets);
};