#include <iostream>
#include <fstream>
#include "TileMap.h"

/***** TODO *****
set the tile objects properties in the following way:
* (x, y) to be the upper left corner coordinate depending on the row and col you are reading from the file
* width should be set to TILE_WIDTH
* height should be set to TILE_HEIGHT
* color should be set to Color::Black if the correspondente value in the data file is 0, otherwise set to Color::Blue
* walkable should be set to true if the correspondente value in the data file is 0, otherwise set to false */
void TileMap::LoadFromFile(string fileName) {
    ifstream data(fileName);

    if (data.fail()) {
    	cerr << "Error opening file" << endl;
    	exit(1);
    }

    int temp;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            data >> temp;
            Tile t;
            t.x = j * TILE_WIDTH;
            t.y = i * TILE_HEIGHT;
            t.walkable = temp!=1;

            switch (temp) {
            case 0:
            	t.color = Color(0,0,0);
            	break;
            case 1:
            	t.color = Color(0,0,255);
            	break;
            case 2:
            	t.color = Color(0,255,0);
            	break;
            default:
            	t.color = Color(255,0,0);
            }

            if (temp==2) {
            	data >> t.portalX;
            	data >> t.portalY;

            	t.portalX *= TILE_WIDTH;
            	t.portalY *= TILE_HEIGHT;
            } else {
            	t.portalX = -1;
            	t.portalY = -1;
            }

            t.width = TILE_WIDTH;
            t.height = TILE_HEIGHT;
            tile[j][i] = t;
        }
    }
    data.close();
}

/***** TODO *****
return the correspondent tile object based on a (x, y) coordinate */
Tile TileMap::GetTile(int x, int y) const {
    return tile[x/TILE_HEIGHT][y/TILE_WIDTH]; // this is a stub; replace this with your implementation
}

void TileMap::draw(RenderTarget& window, RenderStates states) const {
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            window.draw(tile[row][col], states);
}
