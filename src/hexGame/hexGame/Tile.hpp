
#include "HexGameLib_export.hpp"

#include "gameUtils.hpp"

class Tile final
{
private:
    int m_i;
    int m_j;
    Color m_color;
    bool m_isChecked;

public:
    HEXGAMELIB_EXPORT Tile(int i, int j);
    HEXGAMELIB_EXPORT Tile(int i, int j, Color color, bool isChecked);
    HEXGAMELIB_EXPORT ~Tile()=default;

    // Getters - Setters
    HEXGAMELIB_EXPORT int getI() const;
    HEXGAMELIB_EXPORT int getJ() const;
    HEXGAMELIB_EXPORT void setIndexes(int i, int j);
    HEXGAMELIB_EXPORT Color getColor() const;
    HEXGAMELIB_EXPORT void setColor(Color color);
    HEXGAMELIB_EXPORT bool getIsChecked() const;
    HEXGAMELIB_EXPORT void setIsChecked(bool isChecked);

    // Operators
    HEXGAMELIB_EXPORT Tile& operator=(const Tile& tile);
};

HEXGAMELIB_EXPORT bool operator==(const Tile& tile1, const Tile& tile2);
HEXGAMELIB_EXPORT bool operator!=(const Tile& tile1, const Tile& tile2);
