#include "Player.h"
#include <iostream>

// Constructor / Destructor

Player::Player(sf::Vector2f position) {
	_position = position;
	_speed = { 4.8f, 1400.f };
	_max_velocity = { 400.f, 500.f };
	
	_width = 16;
	_height = 16;

	_body_size = sf::Vector2f(_width, _height);
	_body_color = sf::Color::Blue;
	_body.setSize(_body_size);
	_body.setFillColor(_body_color);
	_body.setOrigin(8, 8);
	_body.setPosition(_position);

	_dir = 1;
	_HP = 3;
	_on_ground = false;
}

Player::~Player() {}

void Player::Logic(double dt, const Level &level)
{
	// Decreases player's velocity over time

	if (_velocity.x > 0)
		_velocity.x -= friction * dt * multiplier;
	else if (_velocity.x < 0)
		_velocity.x += friction * dt * multiplier;
	if (fabs(_velocity.x) < 0.0001) {
		_velocity.x = 0;
	}

	// Limit velocity

	if (_velocity.y > _max_velocity.y)
		_velocity.y = _max_velocity.y;
	if (_velocity.y < -_max_velocity.y)
		_velocity.y = -_max_velocity.y;

	// check collision
	Collision(level);

	// Apply gravity

	_velocity.y += gravity * dt * multiplier;

	if (_on_ground && _velocity.y > 0) {
		_velocity.y = 0;
	}

	// Update position

	_position.x += _velocity.x * dt;
	_position.y += _velocity.y * dt;
}

void Player::Update(double dt, const Level &level) {

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i]->Update(dt);
		if (fabs(bullets[i]->getPosition().x - bullets[i]->getStartPosition().x) > 1000.f) {
			std::cout << bullets[i]->getPosition().x << " " << bullets[i]->getStartPosition().x << " " << fabs(bullets[i]->getPosition().x) - fabs(bullets[i]->getStartPosition().x) << "\n";
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
		}
	}

	Player::Input(dt);
	Player::Logic(dt, level);

	_body.setPosition(_position);
}


void Player::Input(double dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && _bullet_timer.getElapsedTime().asMilliseconds() > 200) {
		_bullet_timer.restart();
		bullets.push_back(new Bullet(_dir, _position));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (_velocity.x < _max_velocity.x) {
			_velocity.x += _speed.x * dt * multiplier;
			_dir = 1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (_velocity.x > -_max_velocity.x) {
			_velocity.x += -_speed.x * dt * multiplier;
			_dir = -1;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _on_ground) {
		if (fabs(_velocity.y) < _max_velocity.y)
			_velocity.y += -_speed.y * dt * multiplier;
	}
}

void Player::Collision(const Level &level)
{
	// Check for block collision

	for (size_t i = 0; i < level.getWallCount(); i++) {

		if (boxCollision(_position.x, _width, _position.y, _height, level.getBlocks()[i].getPosition().x, level.getBlockWidth(), level.getBlocks()[i].getPosition().y, level.getBlockHeight())) {
						
			if (_position.y + _height / 2. - (level.getBlocks()[i].getPosition().y - level.getBlockHeight() / 2.) <= 0.6) {
				_on_ground = true;
				_velocity.y = 0;
				_position.y -= 0.5f;
				return;
			}
			if (_velocity.y < 0) {
				_velocity.y = 0;
			}
			if (_velocity.x > 0) {
				_velocity.x = 0;
				_position.x -= 0.4;
				return;
			}
			else if (_velocity.x < 0) {
				_velocity.x = 0;
				_position.x += 0.4;
				return;
			}
		}
	}
	_on_ground = false;
}


