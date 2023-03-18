#pragma once
#include "Node.h"

class ControlNode final : public Node
{
public:
	ControlNode(const Point2f& position, bool isActive, float cellSize);
	virtual ~ControlNode();

	Node* GetAboveNode() const;
	Node* GetRightNode() const;

	bool GetIsActive() const;
private:
	bool m_IsActive;
	Node* m_pAboveNode, *m_pRightNode;
};
