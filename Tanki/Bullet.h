#pragma once
#include "SFML\Graphics\RectangleShape.hpp"
#include "SFML\Graphics\Texture.hpp"
#include "SFML\System\Time.hpp"

class Bullet : public sf::RectangleShape
{
private:
	sf::Vector2f direction;
	static sf::Texture* bulletTexture;
	static const float bulletSpeed;
public:
	Bullet(sf::Vector2f a_direction)
	{
		setSize(sf::Vector2f(40.f, 50.f));
		if (bulletTexture == NULL)
		{
			bulletTexture = new sf::Texture;
			bulletTexture->loadFromFile("Missile.png");
		}
		setTexture(bulletTexture);
		direction = a_direction;
	}
	~Bullet() {}
	sf::Vector2f getDir() { return this->direction; }
	float getSpeed() { return this->bulletSpeed; }
	sf::Vector2f getTrans(sf::Time dt) 
	{
		sf::Vector2f transVec = direction;
		transVec *= bulletSpeed * dt.asMilliseconds();
		return transVec;
	}
};



