#pragma once
#include <memory>

class ControlNode;
class Node;
class Tile
{
public:
	Tile(std::shared_ptr<ControlNode> pBottomLeftNode, std::shared_ptr<ControlNode> pBottomRightNode, std::shared_ptr<ControlNode> pTopLeftNode, std::shared_ptr<ControlNode> pTopRightNode);
	~Tile();

	void DrawNodes(float controlNodeRadius, float otherNodeRadius) const;
	void Draw() const;

private:
	
	std::shared_ptr<ControlNode> m_pBottomLeftNode;
	std::shared_ptr<ControlNode> m_pBottomRightNode;
	std::shared_ptr<ControlNode> m_pTopLeftNode;
	std::shared_ptr<ControlNode> m_pTopRightNode;

	std::shared_ptr<Node> m_pCentreLeftNode;
	std::shared_ptr<Node> m_pCentreRightNode;
	std::shared_ptr<Node> m_pCentreTopNode;
	std::shared_ptr<Node> m_pCentreBottomNode;
};
