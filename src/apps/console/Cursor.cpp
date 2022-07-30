
#include "Cursor.hpp"

#include <string>

#ifdef _WIN32
    #include <Windows.h>
#endif

Cursor::Cursor(int line, int column) : m_line(line), m_column(column) {
    #ifdef _WIN32
        setVirtualTerminal();
    #endif
    setAlternateBuffer();
    clearScreen();
}

Cursor::Cursor() : Cursor(1, 1) {}

int Cursor::getLine() const {
    return m_line;
}

void Cursor::setLine(int line) {
    m_line = line;
}

int Cursor::getColumn() const {
    return m_column;
}

void Cursor::setColumn(int column) {
    m_column = column;
}

void Cursor::setPositionToOrigine() {
    // Set the cursor at 1,1 (top left corner)
    std::cout << CSI "1;1H";
    m_line = 1;
    m_column = 1;
}

bool Cursor::setVirtualTerminal() {
    // Set output mode to handle virtual terminal sequences
    HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hout == INVALID_HANDLE_VALUE) {
        return false;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hout, &dwMode)) {
        return false;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hout, dwMode)) {
        return false;
    }
    return true;
}

void Cursor::setAlternateBuffer() {
    // Enter the alternate buffer
    std::cout << CSI "?1049h";
}

void Cursor::clearScreen() {
    // Set the cursor at 1,1 (top left corner)
    setPositionToOrigine();
    // Clear screen
    std::cout << CSI "2J";
    // Clear all tab stops
    std::cout << CSI "3g";
}

void Cursor::quitAlternateBuffer() {
    // Exit the alternate buffer
    std::cout << CSI "?1049l";
}

void Cursor::newLine() {
    std::cout << std::endl;
    m_line += 1;
    m_column = 1;
}


void Cursor::print(const std::string& str) {
    std::cout << str;
    m_column += (int)str.size();
}

void Cursor::print(char ch) {
    std::cout << ch;
    m_column += 1;
}

void Cursor::print(int num) {
    std::cout << num;
    m_column += (int)std::to_string(num).size();
}

void Cursor::println(const std::string& str) {
    std::cout << str << std::endl;
    m_line += 1;
    m_column = 1;
}

void Cursor::print(const std::string& str, int line, int column) const {
    std::cout << SAVE << MOVE(line, column) << str << LOAD;
}

void Cursor::println(const std::string& str, int line, int column) const {
    std::cout << SAVE << MOVE(line, column) << str << LOAD;
}

void Cursor::print(const std::string& str, PositionSaver& position) const{
    print(str, position.getLine(), position.getColumn());
}

void Cursor::println(const std::string& str, PositionSaver& position) const {
    println(str, position.getLine(), position.getColumn());
}

void Cursor::saveCursorPosition(PositionSaver& position) const{
    position.setLine(m_line);
    position.setColumn(m_column);
}

void Cursor::printDrawMode(char ch) {
    std::cout << ESC"(0" << ch << ESC"(B";
    m_column += 1;
}

void Cursor::printlnDrawMode(char ch) {
    std::cout << ESC"(0" << ch << ESC"(B" << std::endl;
    m_line += 1;
    m_column = 1;
}

std::string Cursor::getString(const std::string& str, PositionSaver& position) {
    int line = position.getLine();
    int column = position.getColumn();
    std::cout << MOVE(line, column) << str;
    std::string output;
    std::cin >> output;
    m_column = 1;
    m_line += 1;
    return output;
}

std::string Cursor::getString(const std::string& str) {
    std::cout << str;
    std::string output;
    std::cin >> output;
    m_column = 1;
    m_line += 1;
    return output;
}

void Cursor::deleteLine(int num, PositionSaver& position) {
    int line = position.getLine();
    int column = position.getColumn();
    std::cout << SAVE << MOVE(line, column) << CSI << num << "P" << LOAD;

}

void Cursor::waitEnter() {
    std::cout << "Press enter to quit the game ";
    // std::string str;
    // std::getline(std::cin, str);
    char c;
    std::cin >> c;
}
