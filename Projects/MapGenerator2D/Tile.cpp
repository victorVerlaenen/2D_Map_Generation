#include "pch.h"
#include "Tile.h"
#include "Node.h"
#include "ControlNode.h"
#include <iostream>
#include "utils.h"

Tile::Tile(std::shared_ptr<ControlNode> spBottomLeftNode, std::shared_ptr<ControlNode> spBottomRightNode, std::shared_ptr<ControlNode> spTopLeftNode, std::shared_ptr<ControlNode> spTopRightNode)
	:m_spBottomLeftNode{ spBottomLeftNode }
	, m_spBottomRightNode{ spBottomRightNode }
	, m_spTopLeftNode{ spTopLeftNode }
	, m_spTopRightNode{ spTopRightNode }
	, m_pCentreLeftNode{ spBottomLeftNode->GetAboveNode() }
	, m_pCentreRightNode{ spBottomRightNode->GetAboveNode() }
	, m_pCentreTopNode{ spTopLeftNode->GetRightNode() }
	, m_pCentreBottomNode{ spBottomLeftNode->GetRightNode() }
{

}

Tile::~Tile()
{
	
}

void Tile::DrawNodes(float controlNodeRadius, float otherNodeRadius) const
{
	// Draw the control nodes
	utils::SetColor(m_spBottomLeftNode->GetIsActive() ? m_WallColor : m_FloorColor);
	m_spBottomLeftNode->Draw(controlNodeRadius);

	utils::SetColor(m_spBottomRightNode->GetIsActive() ? m_WallColor : m_FloorColor);
	m_spBottomRightNode->Draw(controlNodeRadius);

	utils::SetColor(m_spTopLeftNode->GetIsActive() ? m_WallColor : m_FloorColor);
	m_spTopLeftNode->Draw(controlNodeRadius);

	utils::SetColor(m_spTopRightNode->GetIsActive() ? m_WallColor : m_FloorColor);
	m_spTopRightNode->Draw(controlNodeRadius);

	// Draw the other nodes
	utils::SetColor(m_NodeColor);
	m_pCentreLeftNode->Draw(otherNodeRadius);
	m_pCentreRightNode->Draw(otherNodeRadius);
	m_pCentreTopNode->Draw(otherNodeRadius);
	m_pCentreBottomNode->Draw(otherNodeRadius);
}

void Tile::Draw() const
{

}
