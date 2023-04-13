#include "Level.h"

#include <iostream>

Level::Level()
{
	_blocks = nullptr;

	std::ifstream in("Level.txt");

	in >> _width >> _height;

	_grid = new char* [_height];

	for (int i = 0; i < _height; i++)
		_grid[i] = new char[_width];

	char temp;

	_block_count = 0;

	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
			in >> temp;
			if (temp == '#')
				_block_count++;
			_grid[i][j] = temp;
		}
	}

	in.close();
}

Level::~Level()
{
	/*for (int i = 0; i < _height; i++) {
		delete[] _grid[i];
	}

	delete _grid;
	delete _blocks;*/
}

void Level::initializeLevel()
{

	_blocks = new sf::RectangleShape[_block_count];

	int count = 0;

	for (int i = 0; i < _height; i++) {
		for (int j = 0; j < _width; j++) {
			
			if (_grid[i][j] == '#') {
				sf::RectangleShape block;
				block.setSize(sf::Vector2f(16, 16));
				block.setFillColor(sf::Color::Magenta);
				block.setOutlineColor(sf::Color::White);
				block.setOrigin(8, 8);
				block.setPosition(sf::Vector2f(j * 16 - 8, i * 16 - 8));

				/*
				grid[0][0] - '#'

				i = 0; j = 0;

				pos.x = 0 x 16 - 8; pos.y = 0 x 16 - 8
				pos.x = -8; pos.y = -8

				i == 1; j == 1
				pos.x = 8; pos.y = 8;
				*/

				_blocks[count] = block;
				count++;
			}
		}
	}
}

void Level::render(sf::RenderTarget &target)
{
	for (int i = 0; i < _block_count; i++) {
		target.draw(_blocks[i]);
	}
}

char** Level::getGrid() const
{
	return _grid;
}

int Level::getWidth() const
{
	return _width;
}

int Level::getHeight() const
{
	return _height;
}

int Level::getWallCount() const
{
	return _block_count;
}






