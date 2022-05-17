
#pragma once

#include "HexGameLib_export.hpp"

#include <hexGame/Tile.hpp>
#include <hexGame/Board.hpp>


class AdjacentList
{
private:
	int m_max_size;
	Tile** m_tab;
	int m_size;

public:
	AdjacentList(int max_size);

	AdjacentList(const AdjacentList& adjList);

	~AdjacentList();

	int size();

	void push_back(Tile* p);

	void fillWithBoard(Board* board);

	void remove(int index);

	AdjacentList& operator =(const AdjacentList& adjList);

	Tile* operator [] (int index);
};
