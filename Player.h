#pragma once

#include "Entity.h"
#include "Bullet.h"
#include "Enemy.h"

class Player : public Entity
{
private:
	int _HP;

	bool _on_ground;

	sf::Clock _bullet_timer;
	sf::Texture _bullet_texture;

	sf::Clock _i_frame_timer;

public:
	std::vector<Bullet*> bullets;

public:
	Player(sf::Vector2f position);
	~Player();

	virtual void Update(double dt, const Level &level) override;
	
	virtual void Logic(double dt, const Level &level) override;


	void Input(double dt);
	
	void EnemyCollision(std::vector<Enemy*> enemies);

	void Collision(const Level &level);

	int getHP() const;
};

