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

	bool _collided;

	sf::RectangleShape _body;
	sf::Color _color;
	sf::Vector2f _size;
	sf::Texture _texture;
public:
	Bullet(int dir, sf::Vector2f position, sf::Texture* texture);

	void Update(double dt);
	void Logic(Enemy*& enemy);

	sf::RectangleShape getBody() const;
	sf::Vector2f getPosition() const;
	sf::Vector2f getStartPosition() const;
	bool hasCollided() const;
};

