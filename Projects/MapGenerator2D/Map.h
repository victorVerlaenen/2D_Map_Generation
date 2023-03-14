#pragma once
#include <vector>
#include <string>

class Map
{
public:
    Map(const int rows, const int cols);
    ~Map() = default;

    Map(const Map&) = delete;
    Map& operator=(const Map&) = delete;
    Map(Map&&) = delete;
    Map& operator=(Map&&) = delete;

    void GenerateMap();

    // Debug
    void PrintMap() const;
private:
    std::vector<std::vector<bool>> m_Map;
    const int m_NoiseDensityPercentage;
    std::string m_Seed;
    bool m_UseSeed;

    void GenerateNoiseMap();
};
