
#ifndef BOARD_HPP
#define BOARD_HPP

#include "Color.hpp"
#include <vector>

class Board{
	private :
		int size;
		Color turn;
		std::vector<std::vector<int>> board;
	
	public :
		Board(int);
		~Board();
};

#endif