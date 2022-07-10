
#pragma once

#include <gameUtils.hpp>

#include <iostream>
#include <windows.h>

#define SAVE "\x1b[s"
#define LOAD "\x1b[u"
#define ESC "\x1b"
#define CSI "\x1b["
#define MOVE(l, c) "\x1b[" << (l) << ";" << (c) << "H"


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
    void setLineColumn(COORD coord);
    virtual void updateTerminal() = 0;
};

class NumTurnSaver : public PositionSaver {
private:
    int m_numTurn;
public:
    NumTurnSaver(int line, int column);
    NumTurnSaver();
    int getNumTurn() const;
    void setNumTurn(int numTurn);
    void updateTerminal() override;

};

class PlayerSaver : public PositionSaver {
private:
    Color m_color;
public:
    PlayerSaver(int line, int column);
    PlayerSaver();
    Color getColor() const;
    void setColor(Color color);
    std::string convertColorToString();
    void updateTerminal() override;
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
    void updateTerminal() override;
};

class GetTileSaver: public PositionSaver {

public:
    void updateTerminal() override;
    void deleteLine();
    std::string getString();
};
