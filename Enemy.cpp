#include "Enemy.h"
#include "Level.h"

Enemy::Enemy(sf::Vector2f position)
{
	_texture.loadFromFile("textures/Skeleton.png");
	_position = position;
	_speed = { 0.3f, 1400.f };
	_max_velocity = { 100.f, 500.f };

	_width = 16;
	_height = 16;

	_dir = 1;
	_body.setTexture(&_texture);
	_body_size = sf::Vector2f(_width, _height);
	_body.setSize(_body_size);
	_body.setOrigin(8, 8);
	_body.setPosition(_position);

	_is_hit = false;
}

void Enemy::Update(double dt, const Level& level){

	Logic(dt, level);

	if (_dir == 1)
		_body.setScale(1.f, 1.f);
	else
		_body.setScale(-1.f, 1.f);

	_position.x += _speed.x * dt * multiplier * _dir;

	_body.setPosition(_position);
}

void Enemy::Logic(double dt, const Level& level) {
	for (size_t i = 0; i < level.getWallCount(); i++) {

		if (boxCollision(_position.x, _width, _position.y, _height, level.getBlocks()[i].getPosition().x, level.getBlockWidth(), level.getBlocks()[i].getPosition().y, level.getBlockHeight())) {
			_dir *= -1;
		}
	}
}

void Enemy::Hit() {
	_is_hit = true;
}

const bool Enemy::IsDead() { return _is_hit; }




