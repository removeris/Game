#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Defines.h"
#include "Player.h"
#include "Level.h"

using std::cout;

double dt; // Delta time



void pollEvents(sf::RenderWindow &window);

void Update(Player &player, sf::RenderWindow &window);

void Render(sf::RenderWindow& window, Player player, Level level);


int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "2D Platformer", sf::Style::Default); // Create window
	window.setFramerateLimit(60);

	sf::Clock dt_clock; // Create clock to calculate delta time

	Player player;

	Level level;
	
	level.initializeLevel();

	while (window.isOpen()) {

		dt = dt_clock.restart().asSeconds();

		pollEvents(window);

		Update(player, window);

		Render(window, player, level);
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

void Update(Player &player, sf::RenderWindow &window) {
	
	pollEvents(window);

	player.Update(dt);
}

void Render(sf::RenderWindow &window, Player player, Level level) {
	window.clear(sf::Color::Black);
	level.render(window);
	window.draw(player.getBody());
	window.display();
}
