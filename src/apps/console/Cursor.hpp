
#pragma once

#include <iostream>

#include "PositionSaver.hpp"

#define SAVE "\033[s"
#define LOAD "\033[u"
#define ESC "\033"
#define CSI "\033["
#define MOVE(l, c) "\033[" << (l) << ";" << (c) << "H"

class Cursor {
private:
    int m_line;
    int m_column;

public:
    Cursor();
    Cursor(int line, int column);
    ~Cursor() = default;

    int getLine() const;
    void setLine(int line);
    int getColumn() const;
    void setColumn(int column);

    void setPositionToOrigine();
    bool setVirtualTerminal();
    void clearScreen();
    void setAlternateBuffer();
    void quitAlternateBuffer();
    void saveCursorPosition(PositionSaver& position) const;
    std::string getString(const std::string& str, PositionSaver& position);
    std::string Cursor::getString(const std::string& str);
    void deleteLine(int num, PositionSaver& position);
    void waitEnter();

    void newLine();
    void print(const std::string& str);
    void print(char ch);
    void print(int num);
    void println(const std::string& str);
    void println(const std::string& str, int line, int column) const;
    void println(const std::string& str, PositionSaver& position) const;
    void print(const std::string& str, int line, int column) const;
    void print(const std::string& str, PositionSaver& position) const;
    void printDrawMode(char ch);
    void printlnDrawMode(char ch);
};