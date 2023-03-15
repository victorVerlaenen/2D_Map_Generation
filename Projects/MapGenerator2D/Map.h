#pragma once
#include <vector>
#include <string>

class Map
{
public:
	Map(const unsigned int rows, const unsigned int cols, const float windowWidth, const float windowHeight);
	~Map() = default;

	Map(const Map&) = delete;
	Map& operator=(const Map&) = delete;
	Map(Map&&) = delete;
	Map& operator=(Map&&) = delete;

	void Draw() const;
	void IterateCellularAutomata();

	void GenerateMap();

	// Debug
	void PrintMap() const;
private:
	std::vector<std::vector<bool>> m_Map;
	const unsigned int m_Rows;
	const unsigned int m_Columns;
	const float m_CellSize;
	float m_MapWidth; // I would like to make these const but I cant use the initialized list
	float m_MapHeight;// I would like to make these const but I cant use the initialized list

	Point2f m_DrawingStartPoint;// I would like to make these const but I cant use the initialized list

	const int m_NoiseDensityPercentage;
	std::string m_Seed{"seed"};
	bool m_UseRandomSeed{ true };

	const unsigned int m_CellularAutomataIterations{ 5 };

	void Initialize();
	void GenerateNoiseMap();
	int GetNeigbourCount(const int row, const int column);

	const Color4f m_WallColor;
	const Color4f m_EmptyColor;
};
