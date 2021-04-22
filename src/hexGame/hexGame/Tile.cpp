
#include "Tile.hpp"
#include "gameUtils.hpp"

Tile::Tile(int i, int y):
    i(i),
    j(j),
    color(Undefined),
    isChecked(false)
{
}


Tile::Tile(int i, int y, Color color, bool isChecked):
    i(i),
    j(j),
    color(color),
    isChecked(isChecked)
{
}



Tile::~Tile()
{
}
