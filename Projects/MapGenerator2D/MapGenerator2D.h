#pragma once
#include "BaseGame.h"
#include <memory>

class Map;
class MapDrawer;
class MapGenerator2D final : public BaseGame
{
public:
	explicit MapGenerator2D( const Window& window );
	~MapGenerator2D();

	MapGenerator2D(const MapGenerator2D& other) = delete;
	MapGenerator2D& operator=(const MapGenerator2D& other) = delete;
	MapGenerator2D( MapGenerator2D&& other) = delete;
	MapGenerator2D& operator=(MapGenerator2D&& other) = delete;

	void Update( float elapsedSec ) override;
	void Draw( ) const override;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e ) override;
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e ) override;
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e ) override;

private:

	// FUNCTIONS
	void ClearBackground( ) const;

	std::unique_ptr<Map> m_upMap;
	std::unique_ptr<MapDrawer> m_upMapDrawer;
};