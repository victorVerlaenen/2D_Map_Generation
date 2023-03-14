#pragma once
#include "BaseGame.h"
#include "Map.h"

class MapGenerator2D : public BaseGame
{
public:
	explicit MapGenerator2D( const Window& window );
	MapGenerator2D(const MapGenerator2D& other) = delete;
	MapGenerator2D& operator=(const MapGenerator2D& other) = delete;
	MapGenerator2D( MapGenerator2D&& other) = delete;
	MapGenerator2D& operator=(MapGenerator2D&& other) = delete;
	~MapGenerator2D();

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
	void Initialize( );
	void Cleanup( );
	void ClearBackground( ) const;

	Map m_Map;
};