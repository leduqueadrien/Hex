
#include <hexGame/GameUI.hpp>
#include <hexGame/Board.hpp>
#include "framework/Framework.hpp"

class GraphicUI final : public GameUI
{

private:
	/**
	 * @brief the SDL2 framework
	 */
    Framework* m_framework;

	/**
	 * @brief margin distance between the window and the board
	 */
    int m_margin;

public:
	/**
	 * @brief Construct a new GraphicUI object
	 */
	GraphicUI();

	/**
	 * @brief Destroy the GraphicUI object
	 */
	~GraphicUI();

	/**
	 * @brief Display the board using SDL
	 * 
	 * @param board board to be displayed
	 */
	void displayBoard(Board* board);


	/**
	 * @brief Get the Player Move once the player clicked on the screen
	 * 
	 * @param move Move the player made
	 */
	void getPlayerMove(Move& move);

};
