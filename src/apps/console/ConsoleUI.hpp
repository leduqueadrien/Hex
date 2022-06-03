
#include "string"
#include <hexGame/Board.hpp>
#include <hexGame/Game.hpp>
#include <hexGame/GameUI.hpp>
#include <hexGame/Tile.hpp>

class ConsoleUI final : public GameUI {

  private:
  public:
    ConsoleUI();
    ~ConsoleUI();

    std::string displayTile(Tile *tile);
    void displayBoard(Board *board);
    void displayTurnInfo(int, Color);
    void displayMove(Move);
    void getPlayerMove(Move &move);
};
