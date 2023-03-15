#include "pch.h"
#include "MapDrawer.h"
#include "Map.h"
#include "utils.h"

MapDrawer::MapDrawer(Map* pMap, const float windowWidth, const float windowHeight)
	:m_DrawMethod{ DrawMethod::pixelMap }
	, m_pMap{ pMap }
	, m_CellSize{ windowWidth >= windowHeight ? windowHeight / pMap->GetRows() : windowWidth / pMap->GetColumns()}
	, m_WallColor{ 0, 0, 0, 1 }
	, m_EmptyColor{ 1, 1, 1, 1 }
	//, m_MapHeight{ m_CellSize * rows }
	//, m_MapWidth{ m_CellSize * cols }
	//, m_DrawingStartPoint{ (windowWidth / 2.f) - (m_MapWidth / 2.f), ((windowHeight / 2.f) + (m_MapHeight / 2.f)) - m_CellSize }
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
		break;
	case DrawMethod::smoothMap:
		break;
	}
}

void MapDrawer::ChangeDrawMethod(const DrawMethod drawMethod)
{

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
			utils::SetColor((data[row][col] == true) ? m_WallColor : m_EmptyColor);

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

}

void MapDrawer::DrawSmoothMap() const
{

}
