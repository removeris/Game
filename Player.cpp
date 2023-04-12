#include "Player.h"

#include <iostream>

// Constructor / Destructor

Player::Player() {
	_position = { SCREEN_WIDTH / 2., SCREEN_HEIGHT / 2. };
	_speed = { 5.f, 5.f };
	_max_velocity = { 300.f, 500.f };


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
		_velocity.x -= friction;
	else if (_velocity.x < 0)
		_velocity.x += friction;
	else if (fabs(_velocity.x) < 5)
		_velocity.x = 0;

	// Temp ground limits for gravity test

	if (_position.y > SCREEN_HEIGHT - 58) {
		_position.y = SCREEN_HEIGHT - 58;
		_velocity.y = 0;
	}
	else {
		_velocity.y += gravity;
	}
	

	std::cout << _velocity.y << "\n";

	_position.x += _velocity.x * dt;
	_position.y += _velocity.y * dt;
}

void Player::Update(double dt) {
	_body.setPosition(_position);

	Player::Input(dt);
	Player::Logic(dt);
}

void Player::Input(double dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if (_velocity.x < _max_velocity.x)
			Move(_speed.x, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if (_velocity.x > -_max_velocity.x)
			Move(-_speed.x, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		Move(0, -_speed.y);
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


