#pragma once

class Map;
class MapDrawer final
{
public:
	enum class DrawMethod
	{
		pixelMap,
		nodesMap,
		smoothMap,
	};

	explicit MapDrawer(const Map* pMap, const float windowWidth, const float windowHeight);
	~MapDrawer();

	MapDrawer(const MapDrawer&) = delete;
	MapDrawer& operator=(const MapDrawer&) = delete;
	MapDrawer(MapDrawer&&) = delete;
	MapDrawer& operator=(MapDrawer&&) = delete;

	void Draw() const;
	void ChangeDrawMethod(const DrawMethod drawMethod);

private:
	DrawMethod m_DrawMethod;
	const Map* m_pMap;

	const float m_CellSize;
	float m_MapWidth;
	float m_MapHeight;
	Point2f m_DrawingStartPoint;

	const Color4f m_WallColor;
	const Color4f m_FloorColor;

	void DrawPixelMap() const;
	void DrawNodesMap() const;
	void DrawSmoothMap() const;
};
