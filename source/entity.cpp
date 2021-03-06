#include "entity.h"

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}

Entity::Entity(std::string spritePath, double nSize, int oSize)
{
	sf::Texture *t = this->getTexture();
	sf::Sprite *s = this->getSprite();
	t->loadFromFile(spritePath);
	s->setTexture(*t);
	s->setScale(nSize/oSize, nSize/oSize);
}

Entity::Entity(sf::Vector2f pos, std::string spritePath, double nSize, int oSize)
{
	sf::Texture *t = this->getTexture();
	sf::Sprite *s = this->getSprite();
	t->loadFromFile(spritePath);
	s->setTexture(*t);
	s->setScale(nSize/oSize, nSize/oSize);
	s->setPosition(pos);
}

Entity::Entity(sf::Vector2f pos, std::string spritePath)
{
	sf::Texture *t = this->getTexture();
	sf::Sprite *s = this->getSprite();
	t->loadFromFile(spritePath);
	s->setTexture(*t);
	s->setPosition(pos);
}

Entity::~Entity() {}