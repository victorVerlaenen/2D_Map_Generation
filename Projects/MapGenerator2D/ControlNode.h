#pragma once
#include "Node.h"

class ControlNode final : public Node
{
public:
	ControlNode(const Point2f& position, bool isActive, float cellSize);
	virtual ~ControlNode();

	Node* GetAboveNode() const;
	Node* GetRightNode() const;

	static Color4f s_Color;
private:
	bool m_IsActive;
	Node* m_pAboveNode, *m_pRightNode;
};
