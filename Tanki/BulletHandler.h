#pragma once
#include <list>
#include <vector>
#include "Bullet.h"
#include <SFML\System\Time.hpp>


class BulletHandler
{
private:
	static std::list<Bullet*> bulletList;
public:
	static void addBullet(Bullet* bullet)
	{
		bulletList.push_back(bullet);
	}
	static void processBullets(sf::Time dt)
	{
		for (auto &el : bulletList)
		{
			if (el != NULL)
			{
				sf::Vector2f dir = el->getDir();

				el->move(el->getTrans(dt));
			}		
		}
	}
	static std::list<Bullet*>& getBullets() { return bulletList; }
};
