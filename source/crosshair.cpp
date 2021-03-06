#include "crosshair.h"

void Crosshair::reload()
{
	this->reloadingThread = std::thread([this]{
		reloading = true;
		while(bulletsLeft < magazineSize)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(reloadTime / magazineSize));
			bulletsLeft++;
		}
		reloading = false;
		}
		);
}

bool Crosshair::shootable()
{
	if (time(NULL) - shootedTime >= shootDelay && bulletsLeft > 0 && !reloading)
		{
		if (this->reloadingThread.joinable())
			this->reloadingThread.join();
		return true;
		}
	return false;
}

void Crosshair::update()
{
	getSprite()->setPosition(sf::Vector2f(sf::Mouse::getPosition()));
}

Crosshair::Crosshair(std::string spritePath, double nSize, int oSize) : Entity(spritePath, nSize, oSize)
{
	sf::Sprite *s = this->getSprite();
	s->setPosition(sf::Vector2f(sf::Mouse::getPosition()));
	s->setOrigin(oSize/2,oSize/2);

	magazineSize = 6;
	bulletsLeft = 6;
	reloadTime = 4000;	//in millis
	reloading = false;
	time(&shootedTime);
	shootDelay = 1;		//in secs
}

Crosshair::~Crosshair() {}