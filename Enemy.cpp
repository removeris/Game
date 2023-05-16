#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position)
{
	_position = position;
	_speed = { 0.3f, 1400.f };
	_max_velocity = { 100.f, 500.f };

	_width = 16;
	_height = 16;

	_dir = 1;

	_body_size = sf::Vector2f(_width, _height);
	_body_color = sf::Color::Red;
	_body.setSize(_body_size);
	_body.setOrigin(8, 8);
	_body.setFillColor(_body_color);
	_body.setPosition(_position);

	_is_hit = false;
}

void Enemy::Update(double dt, const Level& level){

	_position.x += _speed.x * dt * multiplier * _dir;

	_body.setPosition(_position);
}

void Enemy::Logic(double dt, const Level& level) {
}

void Enemy::Hit() {
	_is_hit = true;
}

const bool Enemy::IsDead() { return _is_hit; }




