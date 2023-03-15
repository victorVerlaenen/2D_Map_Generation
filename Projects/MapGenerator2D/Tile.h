#pragma once

class ControlNode;
class Node;
class Tile
{
public:
	Tile(ControlNode* pBottomLeftNode, ControlNode* pBottomRightNode, ControlNode* pTopLeftNode, ControlNode* pTopRightNode);
	~Tile();

	void DrawNodes(float controlNodeRadius, float otherNodeRadius) const;
	void Draw() const;

private:
	ControlNode* m_pBottomLeftNode;
	ControlNode* m_pBottomRightNode;
	ControlNode* m_pTopLeftNode;
	ControlNode* m_pTopRightNode;

	Node* m_pCentreLeftNode;
	Node* m_pCentreRightNode;
	Node* m_pCentreTopNode;
	Node* m_pCentreBottomNode;
};
