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
	, m_Configuration{ 0 }
{
	Initialize();
}

void Tile::Initialize()
{
	// All 4 control nodes represent 1 digit of a binary number (16 possibilities)
	// If the control node is active, that digit is added to the configuration
	if (m_spTopLeftNode->GetIsActive() == true)
	{
		m_Configuration += 8;
	}
	if (m_spTopRightNode->GetIsActive() == true)
	{
		m_Configuration += 4;
	}
	if (m_spBottomRightNode->GetIsActive() == true)
	{
		m_Configuration += 2;
	}
	if (m_spBottomLeftNode->GetIsActive() == true)
	{
		m_Configuration += 1;
	}

	switch (m_Configuration)
	{
		// 1 active node
	case 1:
		m_PolygonPoints.push_back(m_spBottomLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreBottomNode->GetPosition());
		break;
	case 2:
		m_PolygonPoints.push_back(m_spBottomRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreBottomNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreRightNode->GetPosition());
		break;
	case 4:
		m_PolygonPoints.push_back(m_spTopRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreTopNode->GetPosition());
		break;
	case 8:
		m_PolygonPoints.push_back(m_spTopLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreTopNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreLeftNode->GetPosition());
		break;

		// 2 active nodes
	case 3:
		m_PolygonPoints.push_back(m_spBottomLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreRightNode->GetPosition());
		m_PolygonPoints.push_back(m_spBottomRightNode->GetPosition());
		break;
	case 6:
		m_PolygonPoints.push_back(m_spBottomRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreBottomNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreTopNode->GetPosition());
		m_PolygonPoints.push_back(m_spTopRightNode->GetPosition());
		break;
	case 9:
		m_PolygonPoints.push_back(m_spBottomLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_spTopLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreTopNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreBottomNode->GetPosition());
		break;
	case 12:
		m_PolygonPoints.push_back(m_spTopLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_spTopRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreLeftNode->GetPosition());
		break;
	case 5:
		m_PolygonPoints.push_back(m_spBottomLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreTopNode->GetPosition());
		m_PolygonPoints.push_back(m_spTopRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreBottomNode->GetPosition());
		break;
	case 10:
		m_PolygonPoints.push_back(m_spTopLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreTopNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreRightNode->GetPosition());
		m_PolygonPoints.push_back(m_spBottomRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreBottomNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreLeftNode->GetPosition());
		break;

		// 3 active nodes
	case 7:
		m_PolygonPoints.push_back(m_spBottomLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreTopNode->GetPosition());
		m_PolygonPoints.push_back(m_spTopRightNode->GetPosition());
		m_PolygonPoints.push_back(m_spBottomRightNode->GetPosition());
		break;
	case 11:
		m_PolygonPoints.push_back(m_spBottomLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_spTopLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreTopNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreRightNode->GetPosition());
		m_PolygonPoints.push_back(m_spBottomRightNode->GetPosition());
		break;
	case 13:
		m_PolygonPoints.push_back(m_spBottomLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_spTopLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_spTopRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreBottomNode->GetPosition());
		break;
	case 14:
		m_PolygonPoints.push_back(m_spTopLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_spTopRightNode->GetPosition());
		m_PolygonPoints.push_back(m_spBottomRightNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreBottomNode->GetPosition());
		m_PolygonPoints.push_back(m_pCentreLeftNode->GetPosition());
		break;

		// 4 active nodes
	case 15:
		m_PolygonPoints.push_back(m_spTopLeftNode->GetPosition());
		m_PolygonPoints.push_back(m_spTopRightNode->GetPosition());
		m_PolygonPoints.push_back(m_spBottomRightNode->GetPosition());
		m_PolygonPoints.push_back(m_spBottomLeftNode->GetPosition());
		break;

		// 0 active nodes
	default:
		break;
	}
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

const unsigned int Tile::GetConfiguration() const
{
	return m_Configuration;
}

void Tile::Draw() const
{
	utils::SetColor(m_WallColor);
	utils::FillPolygon(m_PolygonPoints);
}