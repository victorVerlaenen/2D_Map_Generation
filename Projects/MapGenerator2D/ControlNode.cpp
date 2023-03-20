#include "pch.h"
#include "ControlNode.h"
#include <iostream>

ControlNode::ControlNode(const Point2f& position, bool isActive, float cellSize)
	:Node{ position }
	, m_IsActive{ isActive }
	, m_upAboveNode{ std::make_unique<Node>(Point2f{position.x, position.y + cellSize / 2.f}) }
	, m_upRightNode{ std::make_unique<Node>(Point2f{position.x + cellSize / 2.f, position.y}) }
{

}

const Node* ControlNode::GetAboveNode() const
{
	return m_upAboveNode.get();
}

const Node* ControlNode::GetRightNode() const
{
	return m_upRightNode.get();
}

bool ControlNode::GetIsActive() const
{
	return m_IsActive;
}
