#include "Entity.h"

void Entity::Render(sf::RenderTarget& target)
{
	target.draw(_body);
}

sf::Vector2f Entity::getSpeed() const { return _speed; }
sf::RectangleShape Entity::getBody() const{ return _body; }
sf::Vector2f Entity::getVelocity() const { return _velocity; }
sf::Vector2f Entity::getPosition() const { return _position; }
sf::Vector2f Entity::getSize() const { return _body_size; }
