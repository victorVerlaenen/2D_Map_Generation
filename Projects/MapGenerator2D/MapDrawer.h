#pragma once

class Map;
class MapDrawer
{
public:
	enum class DrawMethod
	{
		pixelMap,
		nodesMap,
		smoothMap,
	};

	// TODO: rule5
	MapDrawer(Map* pMap, const float windowWidth, const float windowHeight);
	~MapDrawer();

	void Draw() const;
	void ChangeDrawMethod(const DrawMethod drawMethod);

private:
	DrawMethod m_DrawMethod;
	Map* m_pMap;

	const float m_CellSize;
	float m_MapWidth; // I would like to make these const but I cant use the initialized list
	float m_MapHeight;// I would like to make these const but I cant use the initialized list
	Point2f m_DrawingStartPoint;// I would like to make these const but I cant use the initialized list

	const Color4f m_WallColor;
	const Color4f m_EmptyColor;

	void DrawPixelMap() const;
	void DrawNodesMap() const;
	void DrawSmoothMap() const;
};
