#pragma once
#include "Entity.h"

class Enemy : public Entity{
private:
	bool _is_hit;
	int dir;

public:
	Enemy(sf::Vector2f position);

	virtual void Update(double dt, const Level& level) override;

	virtual void Logic(double dt, const Level& level) override;

	void Hit();
	const bool IsDead();
};

