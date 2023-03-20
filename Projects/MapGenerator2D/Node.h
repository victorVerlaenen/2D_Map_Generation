#pragma once


class Node
{
public:
	explicit Node(const Point2f& position);
	virtual ~Node();

	Node(const Node&) = delete;
	Node& operator=(const Node&) = delete;
	Node(Node&&) = delete;
	Node& operator=(Node&&) = delete;

	virtual void Draw(float radius) const;

private:
	const Point2f m_Position;
	const int m_VertexIndex;

};
