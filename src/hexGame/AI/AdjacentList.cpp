
#include "AdjacentList.hpp"

AdjacentList::AdjacentList(int max_size) : m_max_size(max_size), m_tab(new Tile*[max_size]), m_size(0)
{
	for (int i=0; i<m_max_size; ++i)
		m_tab[i] = nullptr;
}

AdjacentList::AdjacentList(const AdjacentList& adjList) : m_max_size(adjList.m_max_size), m_tab(new Tile*[m_max_size]), m_size(adjList.m_size)
{
	for(int i=0; i<m_max_size; ++i)
		m_tab[i] = adjList.m_tab[i];
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

AdjacentList& AdjacentList::operator=(const AdjacentList& adjList)
{
	if (this != &adjList) {
		if (m_max_size != adjList.m_max_size) {
			delete m_tab;
			m_tab = new Tile* [adjList.m_max_size];
		}
		for(int i=0; i<m_max_size; ++i)
			m_tab[i] = adjList.m_tab[i];
	}
	return *this;
}

Tile* AdjacentList::operator [] (int index) {
	return m_tab[index];
}
