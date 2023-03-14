#include "Map.h"
#include "utils.h"
#include <iostream>
#include <chrono>

Map::Map(const int rows, const int cols)
	:m_Map{ rows, std::vector<bool>(cols) }
	, m_NoiseDensityPercentage{ 48 }
{
	GenerateMap();
}

void Map::GenerateMap()
{

}

void Map::PrintMap() const
{
	for (int i{ 0 }; i < m_Map[0].size(); ++i)
	{
		for (int j{ 0 }; j < m_Map.size(); ++j)
		{
			std::cout << "[" << m_Map[i][j] << "] ";
		}
		std::cout << std::endl;
	}
}

void Map::GenerateNoiseMap()
{
	if (m_UseSeed == true)
	{
		// Random seed based on the current time
		m_Seed = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	}
}
