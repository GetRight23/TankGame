#pragma once
#include <SFML/Graphics.hpp>
#include "tank.h"
#include "map.h"
#include "inputhandler.h"

class Game
{
public:
	Game();
	virtual ~Game();
	void run();
private:
	void processEvents();
	void update(sf::Time tpf);
	void render();
private:
	sf::Time	TimePerFrame;
	InputHandler* inputHandler;
	sf::RenderWindow mWindow;
	Map* map;
	Tank* mTank;
};