#pragma once


class Node
{
public:
	Node(const Point2f& position);
	virtual ~Node();

	virtual void Draw(float radius) const;

	static Color4f s_Color;
private:
	const Point2f m_Position;
	const int m_VertexIndex;

};
