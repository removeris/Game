#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Defines.h"

class Player
{
private:
	sf::Vector2f _position;
	sf::Vector2f _speed;
	sf::Vector2f _velocity;
	sf::Vector2f _max_velocity;

	sf::RectangleShape _body;
	sf::Color _body_color;
	sf::Vector2f _body_size;
	//sf::Texture _body_texture;

	int _HP;

public:
	Player();
	~Player();

	void Input(double dt);

	void Update(double dt);
	
	void Logic(double dt);

	void Move(float x, float y);

	sf::Vector2f getSpeed();

	sf::RectangleShape getBody();

	sf::Vector2f getVelocity();

	sf::Vector2f getPosition();

};

