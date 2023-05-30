#include "Bullet.h"

Bullet::Bullet(int dir, sf::Vector2f position, sf::Texture *texture)
{
	_dir = dir;
	_start_pos = position;
	_position = position;
	_velocity = 2.f;
	_width = 8;
	_height = 8;
	_collided = false;

	_size = sf::Vector2f(_width, _height);
	
	_body.setTexture(texture);
	_body.setSize(_size);
	_body.setOrigin(_width / 2., _height / 2.);
	_body.setPosition(position);
	if (dir == 1)
		_body.setScale(1.0f, 1.0f);
	else
		_body.setScale(-1.0f, 1.0f);
}

void Bullet::Update(double dt) {
	_position.x += _velocity * _dir * dt * multiplier;

	_body.setPosition(_position);
}

void Bullet::Logic(Enemy* &enemy) {

	if (boxCollision(_position.x, _width, _position.y, _height, enemy->getPosition().x, enemy->getSize().x, enemy->getPosition().y, enemy->getSize().y)) {
		enemy->Hit();
		_collided = true;
	}
}

const sf::RectangleShape Bullet::getBody() { return _body; }
const sf::Vector2f Bullet::getPosition() { return _position; }
const sf::Vector2f Bullet::getStartPosition() { return _start_pos; }
const bool Bullet::hasCollided() { return _collided; }


