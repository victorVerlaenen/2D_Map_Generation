#pragma once
#include <vector>
#include <string>

class Map
{
public:
	Map(const unsigned int rows, const unsigned int cols);
	~Map() = default;

	Map(const Map&) = delete;
	Map& operator=(const Map&) = delete;
	Map(Map&&) = delete;
	Map& operator=(Map&&) = delete;

	void IterateCellularAutomata();

	void GenerateMap();
	const std::vector<std::vector<bool>>& GetData() const;
	unsigned int GetRows() const;
	unsigned int GetColumns() const;

	// Debug
	void PrintMap() const;
private:
	std::vector<std::vector<bool>> m_Data;
	const unsigned int m_Rows;
	const unsigned int m_Columns;

	const int m_NoiseDensityPercentage;
	std::string m_Seed{"seed"};
	bool m_UseRandomSeed{ true };

	const unsigned int m_CellularAutomataIterations{ 5 };

	void Initialize();
	void GenerateNoiseMap();
	int GetNeigbourCount(const int row, const int column);
};
