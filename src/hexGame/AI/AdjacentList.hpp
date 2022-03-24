
#pragma once

#include "HexGameLib_export.hpp"

#include <hexGame/Tile.hpp>


class AdjacentList
{
private:
	Tile** m_tab;
	int m_max_size;
	int m_size;

public:
	AdjacentList(int max_size);

	~AdjacentList();

	int size();

	void push_back(Tile* p);

	void remove(int index);

	Tile* operator [] (int index);
};
