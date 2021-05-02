
#include <SDL.h>
#include "GraphicUI.hpp"
#include <iostream>

GraphicUI::GraphicUI():
    m_margin(100)
{
    m_framework = new Framework(800, 800);
}


GraphicUI::~GraphicUI()
{
}


void GraphicUI::displayBoard(Board* board)
{
    int tileSize = (m_framework->m_width - 2 * m_margin) / board->getSize();
    int placement;

    SDL_SetRenderDrawColor(m_framework->renderer, 255, 0, 255, SDL_ALPHA_OPAQUE);

    // Draw Grid
    for (int i=0; i<=board->getSize(); ++i) {
        placement = m_margin + tileSize * i;
        SDL_RenderDrawLine(m_framework->renderer,
                                m_margin, placement,
                                m_margin + tileSize * board->getSize(), placement);
        SDL_RenderDrawLine(m_framework->renderer,
                                placement, m_margin,
                                placement, m_margin + tileSize * board->getSize());
    }



	SDL_RenderPresent(m_framework->renderer);
}


void GraphicUI::getPlayerMove(Move& move)
{
}