#pragma once

#include "SFML/Graphics.hpp"
#include <cmath>
#include "Defines.h"
#include "Level.h"
#include "Utils.h"


class Entity
{
protected:
	sf::Vector2f _position;
	sf::Vector2f _speed;
	sf::Vector2f _velocity;
	sf::Vector2f _max_velocity;
	
	sf::RectangleShape _body;
	sf::Color _body_color;
	sf::Vector2f _body_size;

	int _width, _height;
	int _dir;

public:
	virtual ~Entity() {}

	void Render(sf::RenderTarget &target);

	virtual void Update(double dt, const Level &level) = 0;
	virtual void Logic(double dt, const Level& level) = 0;

	// Accessors

	sf::Vector2f getSpeed();
	sf::RectangleShape getBody();
	sf::Vector2f getVelocity();
	sf::Vector2f getPosition();
	sf::Vector2f getSize();
};

