
#include "AdjacentList.hpp"

AdjacentList::AdjacentList(int max_size) : m_tab(new Tile*[max_size]), m_max_size(max_size), m_size(0) {
	for (int i=0; i<m_max_size; ++i)
		m_tab[i] = nullptr;
}

AdjacentList::~AdjacentList()
{
	delete m_tab;
}

int AdjacentList::size() { return m_size; }

void AdjacentList::push_back(Tile* p) {
	m_tab[m_size] = p;
	++m_size;
}

void AdjacentList::remove(int index) {
	--m_size;
	m_tab[index] = m_tab[m_size];
	m_tab[m_size] = nullptr;
}

Tile* AdjacentList::operator [] (int index) {
	return m_tab[index];
}
