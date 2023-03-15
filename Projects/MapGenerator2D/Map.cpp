#include "pch.h"
#include "Map.h"
#include "utils.h"
#include <iostream>
#include <chrono>
#include <random>

Map::Map(const unsigned int rows, const unsigned int cols, const float windowWidth, const float windowHeight)
	:m_Map{ rows, std::vector<bool>(cols, true) }
	, m_NoiseDensityPercentage{ 48 }
	, m_Rows{ rows }
	, m_Columns{ cols }
	, m_WallColor{ 0, 0, 0, 1 }
	, m_EmptyColor{ 1, 1, 1, 1 }
	, m_CellSize{ windowWidth >= windowHeight ? windowHeight / rows : windowWidth / cols }
	//, m_MapHeight{ m_CellSize * rows }
	//, m_MapWidth{ m_CellSize * cols }
	//, m_DrawingStartPoint{ (windowWidth / 2.f) - (m_MapWidth / 2.f), ((windowHeight / 2.f) + (m_MapHeight / 2.f)) - m_CellSize }
{
	m_MapHeight = { m_CellSize * rows };
	m_MapWidth = { m_CellSize * cols };
	m_DrawingStartPoint = Point2f{ (windowWidth / 2.f) - (m_MapWidth / 2.f), ((windowHeight / 2.f) + (m_MapHeight / 2.f)) - m_CellSize };

	Initialize();
}

void Map::Initialize()
{
	GenerateMap();
}

void Map::Draw() const
{
	// If there is a generated map
	if (m_Map.empty() == false)
	{
		// bottom left point of the first cell
		Point2f drawingPoint{ m_DrawingStartPoint };
		for (int row{ 0 }; row < m_Rows; ++row)
		{
			for (int col{ 0 }; col < m_Columns; ++col)
			{
				// Set right color according to this cell
				utils::SetColor((m_Map[row][col] == true) ? m_WallColor : m_EmptyColor);

				// Determine the size op the map so it fits the window
				utils::FillRect(drawingPoint, m_CellSize, m_CellSize);
				// Move 1 cell to the right
				drawingPoint.x += m_CellSize;
			}
			// Move 1 cell down
			drawingPoint.y -= m_CellSize;
			// Jump back left to first column cell
			drawingPoint.x = m_DrawingStartPoint.x;
		}
	}
}

void Map::GenerateMap()
{
	m_Map.assign(m_Rows, std::vector<bool>(m_Columns, true));
	GenerateNoiseMap();

	for (int i{ 0 }; i < m_CellularAutomataIterations; ++i)
	{
		//IterateCellularAutomata();
	}
}

void Map::PrintMap() const
{
	for (int row{ 0 }; row < m_Rows; ++row)
	{
		for (int col{ 0 }; col < m_Columns; ++col)
		{
			std::cout << "[" << m_Map[row][col] << "] ";
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
			m_Map[row][col] = (pseudoRandomNumber < m_NoiseDensityPercentage) ? true : false;
		}
	}
}

void Map::IterateCellularAutomata()
{
	auto mapCopy = m_Map;

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

	m_Map = mapCopy;
}

int Map::GetNeigbourCount(const int row, const int column)
{
	// Starts at -1 to make sure that, if the cell itself is a wall, it is not included
	int neigbourCount{ m_Map[row][column] == true ? -1 : 0 };

	// Loops over all the 8 surrounding cells and also the cell itself
	for (int neighbourRow{ row - 1 }; neighbourRow <= (row + 1); ++neighbourRow)
	{
		for (int neighbourCol{ column - 1 }; neighbourCol <= (column + 1); ++neighbourCol)
		{
			// Add the value of the cell to the count because the value will be converted to either 0 or 1
			neigbourCount += m_Map[neighbourRow][neighbourCol];
		}
	}
	return neigbourCount;
}
