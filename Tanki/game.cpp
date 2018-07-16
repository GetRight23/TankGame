#include "game.h"
#include "BulletHandler.h"

Game::Game()
	: mWindow(sf::VideoMode(1280, 720), "SFML Application")
{
	
	mTank = new Tank;
	map = new Map(mTank);
	map->loadMap();
	TimePerFrame = sf::seconds(1.f / 60.f);
	inputHandler = new InputHandler(mTank);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		processEvents();
		map->checkCollision();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

Game::~Game()
{
	delete mTank;
	delete inputHandler;
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}
void Game::update(sf::Time tpf)
{
	inputHandler->handleInput(tpf);
	BulletHandler::processBullets(tpf);
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(*map);
	for (int i = 0; i < map->getBarriers().size(); i++)
	{
		mWindow.draw(*(map->getBarriers()[i]));
	}

	std::vector<Bullet*> bullets = BulletHandler::getBullets();
	for (size_t i = 0; i < bullets.size(); i++)
	{
		mWindow.draw(*bullets[i]);
	}

	mWindow.draw(*mTank);
	mWindow.display();
}