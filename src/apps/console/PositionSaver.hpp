
#pragma once

#include <gameUtils.hpp>

#include <iostream>

#ifdef _WIN32
    #include <Windows.h>
#else
#endif

    #define SAVE "\033[s"
    #define LOAD "\033[u"
    #define ESC "\033"
    #define CSI "\033["
    #define MOVE(l, c) "\033[" << (l) << ";" << (c) << "H"

class PositionSaver {
protected:
    int m_line;
    int m_column;

public:
    PositionSaver(int line, int column);
    PositionSaver();
    ~PositionSaver() = default;

    int getLine() const;
    void setLine(int line);
    int getColumn() const;
    void setColumn(int column);
};

class TileSaver: public PositionSaver {
private:
    Color m_color;
public:
    TileSaver(int line, int column);
    TileSaver();
    Color getColor() const;
    void setColor(Color color);
    std::string convertColorToString();
};
