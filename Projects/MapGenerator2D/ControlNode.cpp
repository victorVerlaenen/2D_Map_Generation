#include "pch.h"
#include "ControlNode.h"

Color4f ControlNode::s_Color{ Color4f{1, 0, 0, 1} };

ControlNode::ControlNode(const Point2f& position, bool isActive, float cellSize)
	:Node{ position }
	, m_IsActive{ isActive }
	, m_pAboveNode{ new Node{ Point2f{position.x, position.y + cellSize / 2.f}} }
	, m_pRightNode{ new Node{ Point2f{position.x + cellSize / 2.f, position.y}} }
{

}

ControlNode::~ControlNode()
{
	delete m_pAboveNode;
	m_pAboveNode = nullptr;

	delete m_pRightNode;
	m_pRightNode = nullptr;
}

Node* ControlNode::GetAboveNode() const
{
	return m_pAboveNode;
}

Node* ControlNode::GetRightNode() const
{
	return m_pRightNode;
}
