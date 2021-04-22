
#include "HexGameLib_export.hpp"

#include "Color.hpp"

class Tile
{
private:
    int i;
    int j;
    Color color;
    bool isChecked;

public:
    HEXGAMELIB_EXPORT Tile(int i, int j);
    HEXGAMELIB_EXPORT Tile(int i, int y, Color color, bool isChecked);
    HEXGAMELIB_EXPORT ~Tile();

    // Getters - Setters
    HEXGAMELIB_EXPORT int getI() {return i;}
    HEXGAMELIB_EXPORT int getJ() {return j;}
    HEXGAMELIB_EXPORT void setIndexes(int i, int j) {i = i; j = j;}
    HEXGAMELIB_EXPORT Color getColor() {return color;}
    HEXGAMELIB_EXPORT void setColor(Color color) {color = color;}
    HEXGAMELIB_EXPORT bool getIsChecked() {return isChecked;}
    HEXGAMELIB_EXPORT void setIsChecked(bool isChecked) {isChecked = isChecked;}

    // Operators
    HEXGAMELIB_EXPORT Tile& operator=(const Tile&);
};

HEXGAMELIB_EXPORT bool operator==(const Tile&, const Tile&);
HEXGAMELIB_EXPORT bool operator!=(const Tile&, const Tile&);