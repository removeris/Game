#include "Entity.h"

void Entity::Render(sf::RenderTarget& target)
{
	target.draw(_body);
}

sf::Vector2f Entity::getSpeed() { return _speed; }
sf::RectangleShape Entity::getBody() { return _body; }
sf::Vector2f Entity::getVelocity() { return _velocity; }
sf::Vector2f Entity::getPosition() { return _position; }
sf::Vector2f Entity::getSize() { return _body_size; }
