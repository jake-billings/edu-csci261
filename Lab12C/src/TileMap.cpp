#include "TileMap.h"
#include <iostream>

/***** TODO *****
set the tile objects properties in the following way:
* (x, y) to be the upper left corner coordinate depending on the row and col you are reading from the file
* width should be set to TILE_WIDTH
* height should be set to TILE_HEIGHT
* color should be set to Color::Black if the correspondente value in the data file is 0, otherwise set to Color::Blue
* walkable should be set to true if the correspondente value in the data file is 0, otherwise set to false */
void TileMap::LoadFromFile(string fileName) {
    ifstream data(fileName);

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
        	int temp;
            data >> temp;

            std::cout << temp;

            Tile ntile;

            ntile.x = i*TILE_WIDTH;
            ntile.y = i*TILE_WIDTH;

            ntile.width = TILE_WIDTH;
            ntile.height = TILE_HEIGHT;

            if (temp==0) {
            	ntile.color=Color(0,0,0);
            } else {
            	ntile.color=Color(0,0,255);
            }

            ntile.walkable=temp==0;

            //tile[i][j]=ntile;
        }
    data.close();
}

/***** TODO *****
return the correspondent tile object based on a (x, y) coordinate */
Tile TileMap::GetTile(int x, int y) const {
    return tile[x][y]; // this is a stub; replace this with your implementation
}

void TileMap::draw(RenderTarget& window, RenderStates states) const {
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            window.draw(tile[row][col], states);
}
