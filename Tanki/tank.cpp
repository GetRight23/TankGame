#include "tank.h"
#include <SFML\Graphics\RenderTarget.hpp>
#include "BulletHandler.h"


void Tank::moveRight(sf::Time dt)
{
	if (getRotation() != 90)
		setRotation(90);
	direction.x = 1.0f;
	direction.y = 0.0f;
	direction *= 0.25f * dt.asMilliseconds();
	setPrevPos(getPosition().x, getPosition().y);
	move(direction);
}

void Tank::moveLeft(sf::Time dt)
{
	if (getRotation() != 270)
		setRotation(270);
	direction.x = -1.0f;
	direction.y = 0.0f;
	direction *= 0.25f * dt.asMilliseconds();
	setPrevPos(getPosition().x, getPosition().y);
	move(direction);

}

void Tank::moveUp(sf::Time dt)
{
	if (getRotation() != 0)
		setRotation(0);
	direction.x = 0.0f;
	direction.y = -1.0f;
	direction *= 0.25f * dt.asMilliseconds();
	setPrevPos(getPosition().x, getPosition().y);
	move(direction);
}

void Tank::moveDown(sf::Time dt)
{
	if (getRotation() != 180)
		setRotation(180);
	direction.x = 0.0f;
	direction.y = 1.0f;
	direction *= 0.25f * dt.asMilliseconds();
	system("cls");
	std::cout << "move down";
	std::cout << direction.x << " " << direction.y << std::endl;
	setPrevPos(getPosition().x, getPosition().y);
	move(direction);
}

void Tank::fire(sf::Time dt)
{
	std::cout << dt.asSeconds() << std::endl;
	currentTime += clock.restart();

	if ((currentTime - timeSinceBulletTime).asSeconds() > attackSpeed)
	{
		Bullet* bullet = new Bullet(this->direction);
		bullet->setOrigin(20, 25);
		bullet->setPosition(this->getPosition());
		bullet->setRotation(this->getRotation());
		BulletHandler::addBullet(bullet);

		timeSinceBulletTime = currentTime;
	}
}

void Tank::setPrevPos(float x, float y)
{
	std::cout << "setPrevPos" << std::endl;
	prevX = x;
	prevY = y;
	std::cout << "prevX " << prevX << " prevY " << prevY << std::endl;
}

float Tank::getAttackSpeed() const
{
	return this->attackSpeed;
}