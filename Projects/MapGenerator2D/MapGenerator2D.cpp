#include "pch.h"
#include "MapGenerator2D.h"
#include "Map.h"
#include "MapDrawer.h"

#include "utils.h"

MapGenerator2D::MapGenerator2D(const Window& window)
	:BaseGame{ window }
	, m_upMap{ std::make_unique<Map>(80, static_cast<unsigned int>((80 / window.height) * window.width), window.width, window.height) }
	, m_upMapDrawer{ std::make_unique<MapDrawer>(m_upMap.get(), window.width, window.height) }
{

}

MapGenerator2D::~MapGenerator2D()
{

}

void MapGenerator2D::Update(float elapsedSec)
{
	// Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void MapGenerator2D::Draw() const
{
	ClearBackground();
	m_upMapDrawer->Draw();
}

void MapGenerator2D::ProcessKeyDownEvent(const SDL_KeyboardEvent& e)
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void MapGenerator2D::ProcessKeyUpEvent(const SDL_KeyboardEvent& e)
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	switch ( e.keysym.sym )
	{
	case SDLK_SPACE:
		m_upMap->GenerateMap();
		break;
	case SDLK_UP:
		m_upMap->IterateCellularAutomata();
		break;
	case SDLK_DOWN:
		m_upMap->RetrogradeCellularAutomata();
		break;
	case SDLK_1:
	case SDLK_KP_1:
		m_upMapDrawer->ChangeDrawMethod(MapDrawer::DrawMethod::pixelMap);
		break;
	case SDLK_2:
	case SDLK_KP_2:
		m_upMapDrawer->ChangeDrawMethod(MapDrawer::DrawMethod::nodesMap);
		break;
	case SDLK_3:
	case SDLK_KP_3:
		m_upMapDrawer->ChangeDrawMethod(MapDrawer::DrawMethod::smoothMap);
		break;
	}
}

void MapGenerator2D::ProcessMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void MapGenerator2D::ProcessMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void MapGenerator2D::ProcessMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	//std::cout << "MOUSEBUTTONUP event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void MapGenerator2D::ClearBackground() const
{
	glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
