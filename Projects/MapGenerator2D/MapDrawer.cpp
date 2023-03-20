#include "pch.h"
#include "MapDrawer.h"
#include "Map.h"
#include "Tile.h"
#include "ControlNode.h"
#include "utils.h"

MapDrawer::MapDrawer(const Map* pMap, const float windowWidth, const float windowHeight)
	:m_DrawMethod{ DrawMethod::pixelMap }
	, m_pMap{ pMap }
	, m_CellSize{ windowWidth >= windowHeight ? windowHeight / pMap->GetRows() : windowWidth / pMap->GetColumns()}
	, m_WallColor{ 0.f, 0.f, 0.f, 1.f }
	, m_FloorColor{ 1.f, 1.f, 1.f, 1.f }
{
	m_MapHeight = { m_CellSize * pMap->GetRows() };
	m_MapWidth = { m_CellSize * pMap->GetColumns() };
	m_DrawingStartPoint = Point2f{ (windowWidth / 2.f) - (m_MapWidth / 2.f), ((windowHeight / 2.f) + (m_MapHeight / 2.f)) - m_CellSize };
}

MapDrawer::~MapDrawer()
{

}

void MapDrawer::Draw() const
{
	switch (m_DrawMethod)
	{
	case DrawMethod::pixelMap:
		DrawPixelMap();
		break;
	case DrawMethod::nodesMap:
		DrawNodesMap();
		break;
	case DrawMethod::smoothMap:
		DrawSmoothMap();
		break;
	}
}

void MapDrawer::ChangeDrawMethod(const DrawMethod drawMethod)
{
	m_DrawMethod = drawMethod;
}

void MapDrawer::DrawPixelMap() const
{
	if (m_pMap == nullptr)
	{
		return;
	}
	// If there is a generated map
	if (m_pMap->GetData().empty() == true)
	{
		return;
	}
	auto data = m_pMap->GetData();
	auto rows = m_pMap->GetRows();
	auto cols = m_pMap->GetColumns();

	// bottom left point of the first cell
	Point2f drawingPoint{ m_DrawingStartPoint };
	for (int row{ 0 }; row < rows; ++row)
	{
		for (int col{ 0 }; col < cols; ++col)
		{
			// Set right color according to this cell
			utils::SetColor((data[row][col] == true) ? m_WallColor : m_FloorColor);

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

void MapDrawer::DrawNodesMap() const
{
	if (m_pMap == nullptr)
	{
		return;
	}
	// If there is a generated map
	if (m_pMap->GetData().empty() == true)
	{
		return;
	}

	float controlNodeRadius{ m_CellSize / 4.f }, nodeRadius{ m_CellSize / 6.f };
	// Because the nodes are in the middle of the cell, there will be 1 less tile
	const unsigned int rows{m_pMap->GetRows() - 1}, cols{ m_pMap->GetColumns() - 1};

	// For every Tile in the map, draw all the nodes
	for (int row{0}; row < rows; ++row)
	{
		for (int col{0}; col < cols; ++col)
		{
			m_pMap->GetTile(row, col)->DrawNodes(controlNodeRadius, nodeRadius);
		}
	}
}

void MapDrawer::DrawSmoothMap() const
{
	// Because the nodes are in the middle of the cell, there will be 1 less tile
	const unsigned int rows{ m_pMap->GetRows() - 1 }, cols{ m_pMap->GetColumns() - 1 };

	// For every Tile in the map, check the configuration and draw the right polygon
	for (int row{ 0 }; row < rows; ++row)
	{
		for (int col{ 0 }; col < cols; ++col)
		{
			m_pMap->GetTile(row, col)->Draw();
		}
	}
}
