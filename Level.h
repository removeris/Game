#pragma once

#include <fstream>
#include "SFML/Graphics.hpp"

class Level
{
private:
	int _width, _height, _block_count, _block_width, _block_height;
	sf::Vector2f _player_start_pos;
	int _enemy_count;
	std::vector<sf::Vector2f> _enemy_start_pos;
	char** _grid;
	sf::RectangleShape* _blocks;
	sf::Texture _texture;
private:
	void initializeLevel();
public:
	Level();
	~Level();

	void render(sf::RenderTarget &target);

	// Accessors

	char** getGrid() const;
	int getWidth() const;
	int getHeight() const;
	int getWallCount() const;
	int getBlockWidth() const;
	int getBlockHeight() const;
	sf::RectangleShape* getBlocks() const;
	sf::Vector2f getPlayerStartPosition() const;
	std::vector<sf::Vector2f> getEnemyStartPositions() const;
};

