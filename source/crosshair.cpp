#include "crosshair.h"

void crosshair::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}

void crosshair::update()
{

	this->getSprite()->setPosition(sf::Mouse::getPosition().x, 0);
}

crosshair::crosshair()
{
	sf::Texture *t = this->getTexture();
	sf::Sprite *s = this->getSprite();
	t->loadFromFile("sprites/crosshair.png");
	s->setTexture(*t);
	s->setPosition(200,200);
}

crosshair::~crosshair()
{

}