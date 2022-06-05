
#include <iostream>
#include<fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include "VoidUI.hpp"
#include "CSVwriter.hpp"
#include <hexGame/Game.hpp>
#include <hexGame/Board.hpp>
#include <AI/MonteCarlo.hpp>


void playAGame(Game* game, CSVwriter& writer) {
	std::vector<double> vect;
	int boardSize = (*(*game).getBoard()).size();
	clock_t clock_start;
	clock_t clock_end;

	vect.reserve(boardSize*boardSize);
	(*game).initGame();

	// boucle de jeu
	for(int i=0; i<boardSize*boardSize; ++i) {
		
		// On change le joueur qui a le trait
		(*game).changePlayerTurn();

		// On change le numero du tour
		(*game).incrementNumTurn();
		
		Move move;
		clock_start = clock();
		move = game->getPlayerTurn()->makeMove((*game).getBoard());
		clock_end = clock();
		vect.push_back(clock_end-clock_start);

		// On joue le coup
		(*(*game).getBoard()).addMoveToBoard(move);

	}

	writer.writeDataLine(vect);
}


void writeCommentSection(CSVwriter& writer,
						 const std::string& name,
						 const std::string& description,
						 int boardSize,
						 int nbGameEplored,
						 int nbThread,
						 int nbGame,
						 const std::string& timeUnit)
{

	writer.writeComment("AI Name : " + name);
	writer.writeComment("Description : " + description);
	writer.writeComment("Board size : " + std::to_string(boardSize));
	writer.writeComment("Number of game explored in the AI : " + std::to_string(nbGameEplored));
	writer.writeComment("Number of thread : " + std::to_string(nbThread));
	writer.writeComment("Number of game : " + std::to_string(nbGame));
	writer.writeComment("Time unit : " + timeUnit);
}


void writeTabHeader(CSVwriter& writer, int boardSize)
{
	std::vector<std::string> vect;
	
	for(int i=boardSize*boardSize; i>0; --i)
	{
		vect.push_back(std::to_string(i) + "_Tiles");
	}
	writer.writeHeader(vect);
}


int main(int argc, char const *argv[])
{
	int nb_game = 100;
	int board_size = 9;
	CSVwriter writer("AdjListTemplate_9_100_1.csv");
	Board* board = new Board(board_size);
	GameUI* gameUI = new VoidU();
	MonteCarlo* playerW = new MonteCarlo(Color::White);
	MonteCarlo* playerB = new MonteCarlo(Color::Black);
	Game* game = new Game(gameUI, playerW, playerB, board_size);

	writeCommentSection(writer, "name", "des", board_size, 100, 1, nb_game, "ms");
	writeTabHeader(writer, board_size);

	for (int i=0; i<nb_game; ++i) {
		playAGame(game, writer);
		std::cout << "Game " << (i+1) << " / " << nb_game << std::endl;
	}
	
	delete game;
	delete gameUI;

	return 0;
}
