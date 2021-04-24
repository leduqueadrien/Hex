
#include <hexGame/GameUI.hpp>
#include <hexGame/Board.hpp>
#include "framework/Framework.hpp"

class GraphicUI final : public GameUI
{

private:
    Framework* m_framework;
    int m_margin;

public:
	GraphicUI();
	~GraphicUI();

	void displayBoard(Board* board);
	void getPlayerMove(Move& move);

};
