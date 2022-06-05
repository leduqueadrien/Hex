
#pragma once

#include "HexGameLib_export.hpp"

#include <hexGame/Board.hpp>
#include <vector>

template <typename T>
class AdjacentList {
  private:
    std::vector<T*> m_tab;
    // T **m_tab;

  public:
    AdjacentList(int max_size) {
        m_tab.reserve(max_size);
    }

    AdjacentList(const AdjacentList<T> &adjList) {
        m_tab.reserve(adjList.size())
        for (int i = 0; i < adjList.max_size(); ++i)
            m_tab[i] = adjList.m_tab[i];
    }

    ~AdjacentList() = default;

    size_t size() { return m_tab.size(); }

    size_t max_size() { return m_tab.max_size(); }

    void push_back(T *p) {
        m_tab.push_back(p);
    }

    template <typename C>
    void fillWithContainer(C& c, bool(*statement)(T*)) {
    // void fillWithBoard(C& c) {
        C::iterator it;
        for (it = c.begin(); it != c.end(); ++it)
            if ( (**it).getColor() == Color::Undefined)
                push_back((*it));
    }

    void remove(int index) {
        m_tab[index] = m_tab.at(m_tab.size()-1);
        m_tab.pop_back();
    }

    AdjacentList &operator=(const AdjacentList &adjList) {
        m_tab = adjList.m_tab;
        return *this;
    }

    T* operator[](int index) {
        return m_tab[index];
    }

    T* at(int index) {
        return m_tab.at(index);
    }
};
