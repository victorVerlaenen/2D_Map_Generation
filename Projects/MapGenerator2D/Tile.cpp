#include "pch.h"
#include "Tile.h"
#include "Node.h"
#include "ControlNode.h"
#include "utils.h"

Tile::Tile(ControlNode* pBottomLeftNode, ControlNode* pBottomRightNode, ControlNode* pTopLeftNode, ControlNode* pTopRightNode)
	:m_pBottomLeftNode{ pBottomLeftNode }
	, m_pBottomRightNode{ pBottomRightNode }
	, m_pTopLeftNode{ pTopLeftNode }
	, m_pTopRightNode{ pTopRightNode }
	, m_pCentreLeftNode{ pBottomLeftNode->GetAboveNode() }
	, m_pCentreRightNode{ pBottomRightNode->GetAboveNode() }
	, m_pCentreTopNode{ pTopLeftNode->GetRightNode() }
	, m_pCentreBottomNode{ pBottomLeftNode->GetRightNode() }
{
}

Tile::~Tile()
{
	delete m_pBottomLeftNode;
	m_pBottomLeftNode = nullptr;

	delete m_pBottomRightNode;
	m_pBottomRightNode = nullptr;

	delete m_pTopLeftNode;
	m_pTopLeftNode = nullptr;

	delete m_pTopRightNode;
	m_pTopRightNode = nullptr;

	delete m_pCentreLeftNode;
	delete m_pCentreRightNode;
	delete m_pCentreTopNode;
	delete m_pCentreBottomNode;
}

void Tile::DrawNodes(float controlNodeRadius, float otherNodeRadius) const
{
	// Draw the control nodes
	utils::SetColor(ControlNode::s_Color);
	m_pBottomLeftNode->Draw(controlNodeRadius);
	m_pBottomRightNode->Draw(controlNodeRadius);
	m_pTopLeftNode->Draw(controlNodeRadius);
	m_pTopRightNode->Draw(controlNodeRadius);

	// Draw the other nodes
	utils::SetColor(Node::s_Color);
	m_pCentreLeftNode->Draw(otherNodeRadius);
	m_pCentreRightNode->Draw(otherNodeRadius);
	m_pCentreTopNode->Draw(otherNodeRadius);
	m_pCentreBottomNode->Draw(otherNodeRadius);
}

void Tile::Draw() const
{
}
