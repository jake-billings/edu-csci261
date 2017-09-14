#include "TileMap.h"
#include "Tile.h"

void TileMap::LoadFromFile(string fileName)
{
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
            t.SetWalkable(temp!=1);
            t.SetPosition(i*Tile::TILE_WIDTH,j*Tile::TILE_HEIGHT);
            t.SetSize(Tile::TILE_WIDTH,Tile::TILE_HEIGHT);
            t.setPoints(t.IsWalkable()?5:0);

            switch (temp) {
            case 0:
            	t.SetColor(Color(0,0,0));
            	break;
            case 1:
            	t.SetColor(Color(0,0,255));
            	break;
            case 2:
            	t.SetColor(Color(0,255,0));
            	break;
            default:
            	t.SetColor(Color(255,0,0));
            }

            tile[j][i] = t;
        }
    }
    data.close();
}

Tile TileMap::GetTile(int x, int y) const
{
    // Given a pixel location x,y return the tile that exists at that spot
    return tile[y/Tile::TILE_WIDTH][x/Tile::TILE_HEIGHT];
}

void TileMap::draw(RenderTarget& window, RenderStates states) const
{
    for (int row = 0; row < ROWS; row++)
        for (int col = 0; col < COLS; col++)
            window.draw(tile[row][col], states);
}

// Given a pixel location (x,y), set the tile that it corresponds to's points
void TileMap::SetTilePoints(int x, int y, int points)
{
    tile[y/Tile::TILE_WIDTH][x/Tile::TILE_HEIGHT].SetPoints(points);
}

// Check all the tiles to see if they have points. i.e. did the player win?
bool TileMap::NoMorePoints()
{
	for (int row = 0; row < ROWS; row++)
	        for (int col = 0; col < COLS; col++)
	            if (tile[row][col].GetPoints() > 0)
	            	return false;
    return true;
}
