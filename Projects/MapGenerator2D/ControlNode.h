#pragma once
#include "Node.h"
#include <memory>

class ControlNode final : public Node
{
public:
	ControlNode(const Point2f& position, bool isActive, float cellSize);
	virtual ~ControlNode();

	std::shared_ptr<Node> GetAboveNode() const;
	std::shared_ptr<Node> GetRightNode() const;

	bool GetIsActive() const;
private:
	bool m_IsActive;
	std::shared_ptr<Node> m_pAboveNode, m_pRightNode;
};
