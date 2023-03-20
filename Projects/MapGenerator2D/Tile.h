#pragma once
#include <memory>
#include <vector>

class ControlNode;
class Node;
class Tile final
{
public:
	explicit Tile(std::shared_ptr<ControlNode> spBottomLeftNode, std::shared_ptr<ControlNode> spBottomRightNode, std::shared_ptr<ControlNode> spTopLeftNode, std::shared_ptr<ControlNode> spTopRightNode);
	~Tile();

	Tile(const Tile&) = delete;
	Tile& operator=(const Tile&) = delete;
	Tile(Tile&&) = delete;
	Tile& operator=(Tile&&) = delete;

	void DrawNodes(float controlNodeRadius, float otherNodeRadius) const;
	const unsigned int GetConfiguration() const;
	void Draw() const;

private:
	void Initialize();

	std::shared_ptr<ControlNode> m_spBottomLeftNode;
	std::shared_ptr<ControlNode> m_spBottomRightNode;
	std::shared_ptr<ControlNode> m_spTopLeftNode;
	std::shared_ptr<ControlNode> m_spTopRightNode;

	const Node* m_pCentreLeftNode;
	const Node* m_pCentreRightNode;
	const Node* m_pCentreTopNode;
	const Node* m_pCentreBottomNode;

	const Color4f m_WallColor{ 0.f, 0.f, 0.f, 1.f };
	const Color4f m_FloorColor{ 1.f, 1.f, 1.f, 1.f };
	const Color4f m_NodeColor{ 0.5f, 0.5f, 0.5f, 1.f };

	unsigned int m_Configuration;
	std::vector<Point2f> m_PolygonPoints;
};
