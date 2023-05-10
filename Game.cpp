#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Defines.h"
#include "Player.h"
#include "Enemy.h"
#include "Level.h"

using std::cout;

double dt; // Delta time



void pollEvents(sf::RenderWindow &window);

void Update(Player &player, sf::RenderWindow &window, const Level &level, Enemy enemy);

void Render(sf::RenderWindow& window, Player &player, Level &level, Enemy &enemy, Enemy* &enemy1);


int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "2D Platformer", sf::Style::Default); // Create window
	sf::Clock dt_clock; // Create clock to calculate delta time
	

	Level level;

	Player player;

	
	Enemy enemy(sf::Vector2f(300, 300));

	Enemy* enemy1 = new Enemy(sf::Vector2f(300, 200));

	while (window.isOpen()) {

		dt = dt_clock.restart().asSeconds();

		pollEvents(window);

		for (auto a : player.bullets) {
			a->Logic(enemy1);
		}

		Update(player, window, level, enemy);
		
		Render(window, player, level, enemy, enemy1);
	}

	return 0;
}

void pollEvents(sf::RenderWindow &window) {
	sf::Event ev;

	while (window.pollEvent(ev)) {
		if (ev.type == sf::Event::Closed)
			window.close();
	}
}

void Update(Player &player, sf::RenderWindow &window, const Level &level, Enemy enemy) {
	
	pollEvents(window);

	player.Update(dt, level);

	
}

void Render(sf::RenderWindow &window, Player &player, Level &level, Enemy &enemy, Enemy* &enemy1) {
	window.clear(sf::Color::Black);

	level.render(window);
	player.Render(window);
	enemy.Render(window);

	if(!enemy1->IsDead())
		enemy1->Render(window);

	for (auto a : player.bullets) {
		window.draw(a->getBody());
	}

	window.display();
}
