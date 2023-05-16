#pragma once

#include "Enemy.h"

class Bullet
{
private:
	sf::Vector2f _start_pos;
	sf::Vector2f _position;
	int _dir;
	float _velocity;

	int _width, _height;

	sf::RectangleShape _body;
	sf::Color _color;
	sf::Vector2f _size;
public:
	Bullet(int dir, sf::Vector2f position);

	void Update(double dt);
	void Logic(Enemy*& enemy);

	const sf::RectangleShape getBody();
	const sf::Vector2f getPosition();
	const sf::Vector2f getStartPosition();
};

