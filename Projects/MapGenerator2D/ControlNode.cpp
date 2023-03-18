#include "pch.h"
#include "ControlNode.h"
#include <iostream>

ControlNode::ControlNode(const Point2f& position, bool isActive, float cellSize)
	:Node{ position }
	, m_IsActive{ isActive }
	, m_pAboveNode{ std::make_shared<Node>( Point2f{position.x, position.y + cellSize / 2.f}) }
	, m_pRightNode{ std::make_shared<Node>(Point2f{position.x + cellSize / 2.f, position.y}) }
{

}

ControlNode::~ControlNode()
{
	/*std::cout << "delete m_pAboveNode\n";
	delete m_pAboveNode;
	m_pAboveNode = nullptr;

	std::cout << "delete m_pRightNode\n";
	delete m_pRightNode;
	m_pRightNode = nullptr;*/
}

std::shared_ptr<Node> ControlNode::GetAboveNode() const
{
	return m_pAboveNode;
}

std::shared_ptr<Node> ControlNode::GetRightNode() const
{
	return m_pRightNode;
}

bool ControlNode::GetIsActive() const
{
	return m_IsActive;
}
