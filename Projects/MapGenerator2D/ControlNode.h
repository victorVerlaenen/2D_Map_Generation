#pragma once
#include "Node.h"
#include <memory>

class ControlNode final : public Node
{
public:
	explicit ControlNode(const Point2f& position, bool isActive, float cellSize);
	virtual ~ControlNode();

	ControlNode(const ControlNode&) = delete;
	ControlNode& operator=(const ControlNode&) = delete;
	ControlNode(ControlNode&&) = delete;
	ControlNode& operator=(ControlNode&&) = delete;

	const Node* GetAboveNode() const;
	const Node* GetRightNode() const;

	bool GetIsActive() const;
private:
	bool m_IsActive;
	std::unique_ptr<Node> m_upAboveNode, m_upRightNode;
};
