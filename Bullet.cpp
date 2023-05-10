#include "Bullet.h"

Bullet::Bullet(int dir, sf::Vector2f position)
{
	_dir = dir;
	_position = position;
	_velocity = 0.3f;
	_width = 8;
	_height = 8;

	_color = sf::Color::White;
	_size = sf::Vector2f(_width, _height);
	
	_body.setSize(_size);
	_body.setOrigin(_width / 2., _height / 2.);
	_body.setPosition(position);
	_body.setFillColor(_color);
}

void Bullet::Update(double dt) {
	_position.x += _velocity * _dir * dt * multiplier;

	_body.setPosition(_position);
}

void Bullet::Logic(Enemy* &enemy) {

	if (boxCollision(_position.x, _width, _position.y, _height, enemy->getPosition().x, enemy->getSize().x, enemy->getPosition().y, enemy->getSize().y)) {
		printf("Enemy hit");
		enemy->Hit();
	}
}

const sf::RectangleShape Bullet::getBody() { return _body; }



