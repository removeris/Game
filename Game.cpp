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

void Update(Player& player, sf::RenderWindow& window, const Level& level, std::vector<Enemy*> &enemies, sf::View &view);

void Render(sf::RenderWindow& window, Player &player, Level &level, std::vector<Enemy*> &enemies, sf::View view);

void initEnemies(Level& level, std::vector<Enemy*>& enemies);

void gameOver(sf::RenderWindow& window, sf::View& view, sf::Text &text);

void deleteEnemies(std::vector<Enemy*>& enemies);

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "2D Platformer", sf::Style::Default); // Create window
	sf::Clock dt_clock; // Create clock to calculate delta time
	
	// Game Over scene

	sf::Text game_over;
	sf::Font font;

	font.loadFromFile("textures/ARCADECLASSIC.TTF");

	game_over.setFont(font);
	game_over.setString("Game Over!");
	game_over.setCharacterSize(25);
	game_over.setOrigin(10, 25);
	game_over.setFillColor(sf::Color::White);
	game_over.setOutlineColor(sf::Color::White);
	game_over.setPosition(SCREEN_WIDTH / 2., SCREEN_HEIGHT / 2.);


	sf::View view;
	view.setCenter(sf::Vector2f(SCREEN_WIDTH / 2., SCREEN_HEIGHT / 2.));
	view.setSize(600, 400);
	view.zoom(0.5);

	Level level;

	Player player(level.getPlayerStartPosition());

	std::vector<Enemy*> enemies(level.getEnemyStartPositions().size());

	initEnemies(level, enemies);

	while (window.isOpen()) {

		dt = dt_clock.restart().asSeconds();

		pollEvents(window);

		Update(player, window, level, enemies, view);
		
		if (player.getHP() > 0) {
			Render(window, player, level, enemies, view);
		}
		else {
			gameOver(window, view, game_over);
		}
	}

	deleteEnemies(enemies);

	return 0;
}

void pollEvents(sf::RenderWindow &window) {
	sf::Event ev;

	while (window.pollEvent(ev)) {
		if (ev.type == sf::Event::Closed)
			window.close();
	}
}

void Update(Player& player, sf::RenderWindow& window, const Level& level, std::vector<Enemy*>& enemies, sf::View& view) {
	
	pollEvents(window);

	player.Update(dt, level);
	
	player.EnemyCollision(enemies);
	
	for (auto a : enemies) {
		if (!a->IsDead()) {
			for (auto b : player.bullets) {
				b->Logic(a);
			}
			a->Update(dt, level);
		}
	}

	view.setCenter(player.getPosition());
}

void Render(sf::RenderWindow& window, Player& player, Level& level, std::vector<Enemy*>& enemies, sf::View view) {
	window.clear(sf::Color::Black);

	window.setView(view);

	level.render(window);
	player.Render(window);

	for (auto a : enemies) {
		if (!a->IsDead())
			a->Render(window);
	}

	for (auto a : player.bullets) {
		window.draw(a->getBody());
	}

	window.display();
}

void initEnemies(Level& level, std::vector<Enemy*>& enemies) {
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i] = new Enemy(level.getEnemyStartPositions()[i]);
	}
}

void deleteEnemies(std::vector<Enemy*>& enemies) {
	for (auto a : enemies) {
		delete a;
	}
}

void gameOver(sf::RenderWindow &window, sf::View &view, sf::Text &text) {
	
	window.clear(sf::Color::Black);
	
	view.setCenter(sf::Vector2f(text.getPosition()));

	window.draw(text);

	window.display();
}