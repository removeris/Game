#pragma once

#include <fstream>
#include "SFML/Graphics.hpp"

class Level
{
private:
	int _width, _height, _block_count, _block_width, _block_height;
	char** _grid;
	sf::RectangleShape* _blocks;
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

};

