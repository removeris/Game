#pragma once

#include <fstream>
#include "SFML/Graphics.hpp"

class Level
{
private:
	int _width, _height, _block_count;
	char** _grid;
	sf::RectangleShape* _blocks;

public:
	Level();
	~Level();

	void initializeLevel();

	void render(sf::RenderTarget &target);

	// Accessors

	char** getGrid() const;
	int getWidth() const;
	int getHeight() const;
	int getWallCount() const;

};

