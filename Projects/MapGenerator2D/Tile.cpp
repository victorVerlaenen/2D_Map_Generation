#include "pch.h"
#include "Tile.h"
#include "Node.h"
#include "ControlNode.h"
#include <iostream>
#include "utils.h"

Tile::Tile(std::shared_ptr<ControlNode> pBottomLeftNode, std::shared_ptr<ControlNode> pBottomRightNode, std::shared_ptr<ControlNode> pTopLeftNode, std::shared_ptr<ControlNode> pTopRightNode)
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
	/*std::cout << "delete m_pBottomLeftNode: ";
	if (m_pBottomLeftNode != nullptr)
		delete m_pBottomLeftNode;
	m_pBottomLeftNode = nullptr;

	std::cout << "delete m_pBottomRightNode: ";
	if (m_pBottomRightNode != nullptr)
		delete m_pBottomRightNode;
	m_pBottomRightNode = nullptr;

	std::cout << "delete m_pTopLeftNode: ";
	if (m_pTopLeftNode != nullptr)
		delete m_pTopLeftNode;
	m_pTopLeftNode = nullptr;

	std::cout << "delete m_pTopRightNode: ";
	if (m_pTopRightNode != nullptr)
		delete m_pTopRightNode;
	m_pTopRightNode = nullptr;*/
}

void Tile::DrawNodes(float controlNodeRadius, float otherNodeRadius) const
{
	// Draw the control nodes
	utils::SetColor(m_pBottomLeftNode->GetIsActive() ? Color4f{ 0,0,0,1 } : Color4f{ 1,1,1,1 });
	m_pBottomLeftNode->Draw(controlNodeRadius);
	utils::SetColor(m_pBottomRightNode->GetIsActive() ? Color4f{ 0,0,0,1 } : Color4f{ 1,1,1,1 });
	m_pBottomRightNode->Draw(controlNodeRadius);
	utils::SetColor(m_pTopLeftNode->GetIsActive() ? Color4f{ 0,0,0,1 } : Color4f{ 1,1,1,1 });
	m_pTopLeftNode->Draw(controlNodeRadius);
	utils::SetColor(m_pTopRightNode->GetIsActive() ? Color4f{ 0,0,0,1 } : Color4f{ 1,1,1,1 });
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
