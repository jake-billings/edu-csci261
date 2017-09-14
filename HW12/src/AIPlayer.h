#pragma once

#include <SFML/Graphics.hpp>

#include "TileMap.h"
#include "Player.h"

using namespace sf;

class AIPlayer : public Drawable
{
private:

    int x, y;   // Top-left corner of the AIPlayer. Since the AIPlayers are
                // not circular, we choose to draw them as rectangles, and
                // describe their position using the top-left corner of that
                // rectangle
    int width,height;   // much space does this AI take up?

    int direction;  // Which direction is the player facing/moving?
    int speed;  // Number of pixels moved each frame


    // Helper functions to simplify the move logic
    bool CanWalk(const TileMap& tileMap, int direction);
    bool CanWalkExcept(const TileMap& tileMap, int dirA, int dirB);
    bool CanWalkNorth(const TileMap &tileMap);
    bool CanWalkEast(const TileMap &tileMap);
    bool CanWalkSouth(const TileMap &tileMap);
    bool CanWalkWest(const TileMap &tileMap);
    int OppositeDirection(int direction);

public:
    AIPlayer();
    bool PlayerCollide(const Player player) const;
    void Move(const TileMap &tileMap, const Player player);
    void draw(RenderTarget& window, RenderStates states) const;
};
