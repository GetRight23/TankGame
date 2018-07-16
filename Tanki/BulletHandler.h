#pragma once

#include <vector>
#include "Bullet.h"
#include <SFML\System\Time.hpp>


class BulletHandler
{
private:
	static std::vector<Bullet*> bulletList;
public:
	static void addBullet(Bullet* bullet)
	{
		bulletList.push_back(bullet);
	}
	static void processBullets(sf::Time dt)
	{
		for (size_t i = 0; i < bulletList.size(); i++)
		{
			if (bulletList[i] != NULL)
			{
				sf::Vector2f dir = bulletList[i]->getDir();

				bulletList[i]->move(bulletList[i]->getTrans(dt));
			}		
		}
	}
	static std::vector<Bullet*> getBullets() { return bulletList; }
};
