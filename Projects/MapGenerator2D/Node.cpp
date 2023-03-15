#include "pch.h"
#include "Node.h"
#include "utils.h"

Color4f Node::s_Color{ Color4f{0, 1, 0, 1} };

Node::Node(const Point2f& position)
	:m_Position{ position }
	, m_VertexIndex{ -1 }
{
}

void Node::Draw(float radius) const
{
	utils::FillEllipse(m_Position.x, m_Position.y, radius, radius);
}
