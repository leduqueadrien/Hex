
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


int Tile::getI() const
{
    return i;
}


int Tile::getJ() const
{
    return j;
}


void Tile::setIndexes(int i, int j)
{
    i = i; j = j;
}


Color Tile::getColor() const
{
    return color;
}


void Tile::setColor(Color color)
{
    color = color;
}


bool Tile::getIsChecked() const
{
    return isChecked;
}


void Tile::setIsChecked(bool isChecked)
{
    isChecked = isChecked;
}



Tile& Tile::operator=(const Tile& tile)
{
	if (this != &tile) {
		i = tile.i;
		j = tile.j;
		color = tile.color;
		isChecked = tile.isChecked;
	}
	return *this;
}


bool operator==(const Tile& tile1, const Tile& tile2)
{
	return tile1.getI() == tile2.getJ();
}


bool operator!=(const Tile& tile1, const Tile& tile2)
{
	return tile1.getI() != tile2.getJ();
}
