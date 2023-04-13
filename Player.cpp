#include "Player.h"

#include <iostream>

// Constructor / Destructor

Player::Player() {
	_position = { SCREEN_WIDTH / 2., SCREEN_HEIGHT / 2. };
	_speed = { 4.8f, 80.f };
	_max_velocity = { 400.f, 500.f };


	_body_size = sf::Vector2f(16, 16);
	_body_color = sf::Color::Blue;
	_body.setSize(_body_size);
	_body.setFillColor(_body_color);
	_body.setOrigin(8, 8);
	_body.setPosition(_position);

	_HP = 3;
}

Player::~Player() {}


void Player::Logic(double dt)
{
	// Decreases player's velocity over time

	if (_velocity.x > 0)
		_velocity.x -= friction * dt * multiplier;
	else if (_velocity.x < 0)
		_velocity.x += friction * dt * multiplier;
	if (fabs(_velocity.x) < 15) {
		_velocity.x = 0;
	}


	// Temp ground limits for gravity test

	if (_position.y > SCREEN_HEIGHT - 58) {
		_velocity.y = 0;
		_position.y = SCREEN_HEIGHT - 58;
	}
	else {
		_velocity.y += gravity * dt * multiplier;
	}
	
	_position.x += _velocity.x * dt;
	_position.y += _velocity.y * dt;
}

void Player::Update(double dt) {

	Player::Input(dt);
	Player::Logic(dt);

	_body.setPosition(_position);
}

void Player::Input(double dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (_velocity.x < _max_velocity.x)
			Move(_speed.x * dt * multiplier, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (_velocity.x > -_max_velocity.x)
			Move(-_speed.x * dt * multiplier, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (_velocity.y == 3 || _velocity.y == 0)) {
		Move(0, -_speed.y * dt * multiplier);
	}
}

void Player::Move(float x, float y) {
	_velocity.x += x;
	_velocity.y += y;
}

// Accessors

sf::Vector2f Player::getSpeed() { return _speed; }
sf::RectangleShape Player::getBody() { return _body; }
sf::Vector2f Player::getVelocity() { return _velocity; }
sf::Vector2f Player::getPosition() { return _position; }


