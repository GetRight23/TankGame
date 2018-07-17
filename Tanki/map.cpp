#include "map.h"
#include <fstream>
#include <iostream>
#include <string>
#include <SFML\Graphics\Transformable.hpp>
#include <iterator>
#include <SFML\Graphics.hpp>
#include <exception>

Map::Map(Tank* Tank)
{
	tank = Tank;
	texture = new sf::Texture;
	std::string filename = "desert.png";
	texture->loadFromFile(filename);
	setTexture(texture);
	outlinethickness = 10;
	setOutlineThickness(outlinethickness);
	setOutlineColor(sf::Color::Black);
	size = sf::Vector2f(1280 - 2 * outlinethickness, 720 - 2 * outlinethickness);
	setPosition(outlinethickness, outlinethickness);
	setSize(size);
}

void Map::loadMap()
{
	std::string buff;
	std::fstream file;
	int i = 0;
	std::vector<std::string> buffer;
	file.open("Field.txt");
	if (!file.is_open())
		std::cout << "Error";
	int j = 0;
	while (std::getline(file, buff))
	{
		buffer.push_back(buff);
		std::cout << buff << '\n';
		for (int i = 0; i < buffer[j].size(); i++)
		{
			if (buffer[j][i] == '1')
			{
				vecBar.push_back(new Barrier);
				vecBar.back()->setPosition(i * 100 + outlinethickness, j * 100 + outlinethickness);
			}
		}
		j++;
	}
	file.close();
}

bool Map::checkCollision()
{
	for (int i = 0; i < vecBar.size(); i++)
	{
		if (tank->getGlobalBounds().intersects((vecBar[i])->getGlobalBounds())
			|| tank->getGlobalBounds().intersects(sf::FloatRect(-1, -1, 1280, 1))
			|| tank->getGlobalBounds().intersects(sf::FloatRect(-1, -1, 1, 720))
			|| tank->getGlobalBounds().intersects(sf::FloatRect(1281, -1, 1, 720))
			|| tank->getGlobalBounds().intersects(sf::FloatRect(-1, 720, 1280, 1)))
		{
			std::cout << "checkCollision" << std::endl;
			tank->setPosition(tank->getPrevX(), tank->getPrevY());
		}
	}
	return true;
}

bool Map::checkCollision(std::list<Bullet*>& bullets)
{
	for (auto &el : bullets)
	{
		for (int j = 0; j < vecBar.size(); j++)
		{
			if (el->getGlobalBounds().intersects((vecBar[j])->getGlobalBounds()) 
				|| el->getPosition().x > getSize().x 
				|| el->getPosition().y > getSize().y
				|| el->getPosition().x < 1
				|| el->getPosition().y < 1
				)
			{
				std::cout << "UDALENO NAH\n";
				bullets.remove(el);
				std::cout << "darova\n";
				return true;
			}
		}
	}
	return true;
}