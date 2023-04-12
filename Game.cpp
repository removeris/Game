#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Defines.h"
#include "Player.h"

using std::cout;

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 400

void Update(Player &player);

double dt; // Delta time

int main()
{
	sf::Clock clock; // Create clock to calculate delta time

	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "2D Platformer", sf::Style::Default);

	Player player;
	
	sf::RectangleShape temp_ground;

	temp_ground.setSize(sf::Vector2f(600, 50));
	temp_ground.setOrigin(300, 25);
	temp_ground.setFillColor(sf::Color::Green);
	temp_ground.setPosition(SCREEN_WIDTH / 2., SCREEN_HEIGHT - 25);
	

	while (window.isOpen()) {
		
		dt = clock.getElapsedTime().asMicroseconds() * 0.000001;
		clock.restart();

		//cout << delta << "\n";
		
		sf::Event ev;

		while (window.pollEvent(ev)) {
			if (ev.type == sf::Event::Closed)
				window.close();

		}


		Update(player);

		window.clear(sf::Color::Black);
		window.draw(player.getBody());
		window.draw(temp_ground);
		window.display();
	}

	return 0;
}

void Update(Player &player) {
	player.Update(dt);
}
