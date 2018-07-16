#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Graphics\Texture.hpp>
#include "SFML\System\Time.hpp"


#include "actor.h"
#include "barrier.h"
#include <iostream>
#include <stack>


class Tank : public sf::RectangleShape, public Actor
{
private:
	float mVelocity;
	float mPosX;
	float mPosY;
	float prevX;
	float prevY;
	sf::Vector2f direction;
	sf::Texture* texture;
	float attackSpeed;
	sf::Time timeSinceBulletTime;
	sf::Time currentTime;
	sf::Clock clock;
public:
	Tank()
	{
		timeSinceBulletTime = sf::Time::Zero;
		currentTime = sf::Time::Zero;
		attackSpeed = 0.4f;
		direction = sf::Vector2f(1.0f, 0.0f);
		mVelocity = 100.f;
		mPosX = 200;
		mPosY = 200;
		sf::Vector2f size(80, 80);
		setSize(size);
		setOrigin(40, 40);
		setPosition(mPosX, mPosY);
		texture = new sf::Texture;
		std::string filename = "tank.png";
		texture->loadFromFile(filename);
		setTexture(texture);
	}
	~Tank()
	{
		delete texture;
	}
	float getPrevX() { return prevX; }
	float getPrevY() { return prevY; }

	void moveRight(sf::Time dt);
	void moveLeft(sf::Time dt);
	void moveUp(sf::Time dt);
	void moveDown(sf::Time dt);
	void fire(sf::Time dt);

	float getAttackSpeed() const;

	void setPrevPos(float x, float y);
};