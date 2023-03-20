#pragma once
#include <vector>
#include <string>
#include <memory>
#include <stack>

class Tile;
class Map final
{
public:
	explicit Map(const unsigned int rows, const unsigned int cols, const float windowWidth, const float windowHeight);
	~Map();

	Map(const Map&) = delete;
	Map& operator=(const Map&) = delete;
	Map(Map&&) = delete;
	Map& operator=(Map&&) = delete;

	// Let the cellular automate happen once
	void IterateCellularAutomata();
	// Goes back to the previous state
	void RetrogradeCellularAutomata();

	void GenerateMap();
	const std::vector<std::vector<bool>>& GetData() const;
	unsigned int GetRows() const;
	unsigned int GetColumns() const;
	const Tile* Map::GetTile(int row, int column) const;

	// Debug
	void PrintMap() const;
private:
	std::vector<std::vector<bool>> m_Data;
	std::stack<std::vector<std::vector<bool>>> m_PreviousDataSets;
	std::vector<std::vector<std::unique_ptr<Tile>>> m_upTiles;
	const unsigned int m_Rows;
	const unsigned int m_Columns;
	const float m_CellSize;
	Point2f m_FirstNodePosition;

	const int m_NoiseDensityPercentage;
	std::string m_Seed{"seed"};
	bool m_UseRandomSeed{ true };

	const unsigned int m_CellularAutomataIterations{ 5 };

	void GenerateNoiseMap();
	void GenerateTiles();
	int GetNeigbourCount(const int row, const int column);
};
