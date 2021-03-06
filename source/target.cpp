#include "target.h"

void Target::update()
{
    getSprite()->move(direction * speed);

    if (this->getSprite()->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition())))
        this->aimed = true;
    else
        this->aimed = false;
        
}

Target::Target(sf::Vector2f direction, sf::Vector2f pos, std::string spritePath, double nSize, int oSize) : Entity(pos, spritePath, nSize, oSize)
{
    this->getSprite()->setOrigin(oSize/2, oSize/2);

    this->direction = direction;
    this->speed = rand()%3 + 1;
    this->getSprite()->scale(1.0/speed, 1.0/speed);
    this->points = 10 * speed;
    this->speed *= 0.01;
}

Target::~Target() {}