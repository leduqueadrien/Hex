
#pragma once

#include <iostream>

#include "PositionSaver.hpp"

#define SAVE "\033[s"
#define LOAD "\033[u"
#define ESC "\033"
#define CSI "\033["
#define MOVE(l, c) "\033[" << (l) << ";" << (c) << "H"

/**
 * @brief Class for move the cursor
 */
class Cursor {
private:
    /**
     * @brief line of the current cursor position
     */
    int m_line;

    /**
     * @brief column of the current cursor position
     */
    int m_column;

public:
    /**
     * @brief Construct a new Cursor object
     */
    Cursor();

    /**
     * @brief Construct a new Cursor object
     * @param line line of the cursor
     * @param column  column of the cursor
     */
    Cursor(int line, int column);

    /**
     * @brief Destroy the Cursor object
     */
    ~Cursor() = default;

    /**
     * @brief Get the Line object
     * @return Current line
     */
    int getLine() const;

    /**
     * @brief Set the Line object
     * @param line New line position
     */
    void setLine(int line);

    /**
     * @brief Get the Column object
     * @return Current column
     */
    int getColumn() const;

    /**
     * @brief Set the Column object
     * @param column New column position
     */
    void setColumn(int column);

    /**
     * @brief Set the line and column to the origin
     * aka 0, 0
     */
    void setPositionToOrigine();
    
    /**
     * @brief Set the Virtual Terminal
     * For windows only
     * @return Does the setting sucess
     */
    bool setVirtualTerminal();

    /**
     * @brief Clear the screen
     */
    void clearScreen();

    /**
     * @brief Set the alternate buffer
     */
    void setAlternateBuffer();

    /**
     * @brief Quit the alternate buffer
     */
    void quitAlternateBuffer();

    /**
     * @brief Save the curent cursor position into a PositionSaver
     * @param position PositionSaver on which the position will be stored
     */
    void saveCursorPosition(PositionSaver &position) const;

    /**
     * @brief Get the string given by the user
     * @param str String to write befor get the user input
     * @param position Position on which the input is get
     * @return User input
     */
    std::string getString(const std::string &str, PositionSaver &position);

    /**
     * @brief Get the String object
     * @param str String to write befor get the user input
     * @return User input
     */
    std::string getString(const std::string &str);

    /**
     * @brief Delete a line content
     * @param num Number of caractere on the line
     * @param position Position of the line
     */
    void deleteLine(int num, PositionSaver &position);

    /**
     * @brief Wait until the user press the enter key
     */
    void waitEnter();

    /**
     * @brief Make a new line
     */
    void newLine();

    /**
     * @brief Print a text
     * @param str Text to print
     */
    void print(const std::string &str);

    /**
     * @brief Print a caractere
     * @param ch Caractere to be printed
     */
    void print(char ch);

    /**
     * @brief Print a integer
     * @param num Integer to be printed
     */
    void print(int num);

    /**
     * @brief Print a text and make a newline
     * @param str Text to print
     */
    void println(const std::string &str);

    /**
     * @brief Print a text and make a newline on a specific position
     * @param str Text to print
     * @param line Line of the printed message
     * @param column Column of the printed message
     */
    void println(const std::string &str, int line, int column) const;

    /**
     * @brief Print a text and make a newline on a specific position
     * @param str Text to print
     * @param position Position of the printed message
     */
    void println(const std::string &str, PositionSaver &position) const;

    /**
     * @brief Print a text on a specific position
     * @param str Text to print
     * @param line Line of the printed message
     * @param column Column of the printed message
     */
    void print(const std::string &str, int line, int column) const;

    /**
     * @brief Print a text on a specific position
     * @param str Text to print
     * @param position Position of the printed message
     */
    void print(const std::string &str, PositionSaver &position) const;

    /**
     * @brief Print a caractere on draw mode
     * @param ch Caractere to print
     */
    void printDrawMode(char ch);

    /**
     * @brief Print a caractere on draw mode and make a newline
     * @param ch Caractere to print
     */
    void printlnDrawMode(char ch);
};
