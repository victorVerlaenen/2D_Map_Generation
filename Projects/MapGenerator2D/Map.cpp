#include "pch.h"
#include "Map.h"
#include "utils.h"
#include <iostream>
#include <chrono>
#include "Tile.h"
#include <random>
#include "ControlNode.h"

Map::Map(const unsigned int rows, const unsigned int cols, const float windowWidth, const float windowHeight)
	:m_Data{ rows, std::vector<bool>(cols, true) }
	, m_CellSize{ windowWidth >= windowHeight ? windowHeight / rows : windowWidth / cols }
	, m_NoiseDensityPercentage{ 48 }
	, m_Rows{ rows }
	, m_Columns{ cols }
{
	float mapWidth = m_CellSize * m_Columns;
	float mapHeight = m_CellSize * m_Rows;
	m_FirstNodePosition = Point2f{ (windowWidth / 2.f) - (mapWidth / 2.f), ((windowHeight / 2.f) + (mapHeight / 2.f)) };

	Initialize();
}

Map::~Map()
{

}

void Map::Initialize()
{
	GenerateMap();
}

void Map::GenerateMap()
{
	m_Data.assign(m_Rows, std::vector<bool>(m_Columns, true));
	GenerateNoiseMap();
	GenerateTiles();

	for (int i{ 0 }; i < m_CellularAutomataIterations; ++i)
	{
		//IterateCellularAutomata();
	}
}

const std::vector<std::vector<bool>>& Map::GetData() const
{
	return m_Data;
}

unsigned int Map::GetRows() const
{
	return m_Rows;
}

unsigned int Map::GetColumns() const
{
	return m_Columns;
}

const Tile* Map::GetTile(int row, int column) const
{
	return m_upTiles[row][column].get();
}

void Map::PrintMap() const
{
	for (int row{ 0 }; row < m_Rows; ++row)
	{
		for (int col{ 0 }; col < m_Columns; ++col)
		{
			std::cout << "[" << m_Data[row][col] << "] ";
		}
		std::cout << std::endl;
	}
}

void Map::GenerateNoiseMap()
{
	if (m_UseRandomSeed == true)
	{
		// Random seed based on the current time
		auto now{ std::chrono::system_clock::now().time_since_epoch() };
		m_Seed = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();
	}

	// Seed the random number generator
	std::hash<std::string> hashGenerator;
	srand(hashGenerator(m_Seed));

	// Let the number range between 1 and 100
	int pseudoRandomNumber{ 0 };

	// Loop over all cells in the map and fill random
	// I start from 1 and end at -1 so that the sides of the map are always walls since the map is initialezed with all walls
	for (int row{ 1 }; row < m_Rows - 1; ++row)
	{
		for (int col{ 1 }; col < m_Columns - 1; ++col)
		{
			pseudoRandomNumber = (rand() % 100) + 1;
			// If random number is smaller then the noise density percentage, the cell should be a wall
			m_Data[row][col] = (pseudoRandomNumber < m_NoiseDensityPercentage) ? true : false;
		}
	}
}

void Map::GenerateTiles()
{
	// Empty the Tiles List
	m_upTiles.clear();

	// Declare a list of ControlNodes
	std::vector<std::vector<std::shared_ptr<ControlNode>>> spControlNodes;

	// Fill the list with newly created controlNodes
	Point2f position{ 0,0 };
	for (int row{ 0 }; row < m_Rows; ++row)
	{
		spControlNodes.push_back(std::vector<std::shared_ptr<ControlNode>>{});
		for (int col{ 0 }; col < m_Columns; ++col)
		{
			// Position is the middle of the cells
			position = Point2f{ (m_FirstNodePosition.x + (m_CellSize / 2.f)) + (col * m_CellSize), (m_FirstNodePosition.y - m_CellSize / 2.f) - (row * m_CellSize) };
			spControlNodes[row].push_back(std::make_shared<ControlNode>(position, m_Data[row][col] == true, m_CellSize));
		}
	}

	// Because the nodes are in the middle of the cell, there will be 1 less tile (every control node is at the corner of a tile)
	for (int row{ 0 }; row < m_Rows - 1; ++row)
	{
		m_upTiles.push_back(std::vector<std::unique_ptr<Tile>>{});
		for (int col{ 0 }; col < m_Columns - 1; ++col)
		{
			// Construct the tiles with the right controlNodes
			auto newTile = std::make_unique<Tile>(spControlNodes[row + 1][col], spControlNodes[row + 1][col + 1], spControlNodes[row][col], spControlNodes[row][col + 1]);
			m_upTiles[row].push_back(std::move(newTile));
		}
	}
}

void Map::IterateCellularAutomata()
{
	// A copy is made so that the data that is tested for neigbors stays the same for all cells
	auto mapCopy = m_Data;

	// Again making sure that the sides of the map stay walls and that there wont be an out of bounds in the GetNeigborCount function
	for (int row{ 1 }; row < m_Rows - 1; ++row)
	{
		for (int col{ 1 }; col < m_Columns - 1; ++col)
		{
			int neigbourWalls = GetNeigbourCount(row, col);

			// If there are more than 4 neigboring walls, this cell becomes a wall
			if (neigbourWalls > 4)
			{
				mapCopy[row][col] = true;
			}// If there are less than 4 neigboring walls, this cell becomes empty
			else if (neigbourWalls < 4)
			{
				mapCopy[row][col] = false;
			}
			// Otherwise it stays the same
		}
	}
	m_Data = mapCopy;

	// Regenerate the tiles based on the map
	GenerateTiles();
}

int Map::GetNeigbourCount(const int row, const int column)
{
	// Starts at -1 to make sure that, if the cell itself is a wall, it is not included
	int neigbourCount{ m_Data[row][column] == true ? -1 : 0 };

	// Loops over all the 8 surrounding cells and also the cell itself
	for (int neighbourRow{ row - 1 }; neighbourRow <= (row + 1); ++neighbourRow)
	{
		for (int neighbourCol{ column - 1 }; neighbourCol <= (column + 1); ++neighbourCol)
		{
			// Add the value of the cell to the count because the value will be converted to either 0 or 1
			neigbourCount += m_Data[neighbourRow][neighbourCol];
		}
	}
	return neigbourCount;
}
