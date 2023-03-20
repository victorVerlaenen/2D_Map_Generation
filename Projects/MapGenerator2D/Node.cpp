#include "pch.h"
#include "Node.h"
#include "utils.h"

Node::Node(const Point2f& position)
	:m_Position{ position }
	, m_VertexIndex{ -1 }
{

}

void Node::Draw(float radius) const
{
	utils::FillEllipse(m_Position.x, m_Position.y, radius, radius);
}

const Point2f& Node::GetPosition() const
{
	return m_Position;
}
