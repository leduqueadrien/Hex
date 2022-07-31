
#include "Menu.hpp"

#include <iostream>

// ############################################################################
// ################################### MENU ###################################
// ############################################################################

Menu::Menu(std::shared_ptr<Cursor> cursor) : m_cursor(cursor) {
    m_cursor->clearScreen();
}


void Menu::display() {
    const_iterator it;
	int cnt = 1;
    m_cursor->println(m_question);
	for (it=begin(); it!=end(); ++it) {
        m_cursor->print(cnt);
        m_cursor->print(" -> ");
        m_cursor->println(*it);
		++cnt;
	}
}

int Menu::select() {
    std::string output = m_cursor->getString("");
    int choice = 0;
    try {
        choice = std::stoi(output.c_str());
    } catch(const std::invalid_argument&) {
        choice = 0;
    }
	return choice;
}

Menu::const_iterator Menu::begin() const {
    return m_answers.begin();
}

Menu::const_iterator Menu::end() const {
    return m_answers.end();
}

// ############################################################################
// ################################# MENU HOME ################################
// ############################################################################

MenuHome::MenuHome(std::shared_ptr<Cursor> cursor) : Menu(cursor) {
	m_question = "Menu principal";
	m_answers.push_back("Lancer la partie");
	m_answers.push_back("Parametrer le plateau");
	m_answers.push_back("Parametrer joueur Blanc");
	m_answers.push_back("Parametrer joueur Noir");
}

bool MenuHome::action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) {
	switch (choice)
	{
	case 1:
		current_menu = nullptr;
		break;
	case 2:
		current_menu = std::make_shared<MenuBoard>(m_cursor);
		break;
	case 3:
		current_menu = std::make_shared<MenuPlayer>(Color::White, m_cursor);
		break;
	case 4:
		current_menu = std::make_shared<MenuPlayer>(Color::Black, m_cursor);
		break;
	default:
		return false;
		break;
	}
	return true;
}

// ############################################################################
// ################################ MENU BOARD ################################
// ############################################################################

MenuBoard::MenuBoard(std::shared_ptr<Cursor> cursor) : Menu(cursor) {
	m_question = "taille du plateau : ";
}

bool MenuBoard::action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) {
	if (choice % 2 == 1) {
        std::dynamic_pointer_cast<ParameterBoardSize>(param.getParameter("BoardSize"))->setBoardSize(choice);
		current_menu = std::make_shared<MenuHome>(m_cursor);
		return true;
	} else {
		return false;
	}
}

// ############################################################################
// ############################### MENU PLAYER ################################
// ############################################################################

MenuPlayer::MenuPlayer(Color player_color, std::shared_ptr<Cursor> cursor) : Menu(cursor) {
	m_player_color = player_color;
	m_question = "Quel type de joueur : ";
	m_answers.push_back("Humain");
	m_answers.push_back("Aleatoire");
	m_answers.push_back("MonteCarlo");
}

bool MenuPlayer::action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) {
	std::string param_type = "PlayerWhite";
	if (m_player_color == Color::Black)
		param_type = "PlayerBlack";
	switch (choice)
	{
	case 1:
        std::dynamic_pointer_cast<ParameterPlayer>(param.getParameter(param_type))->setPlayerType("Human");
		current_menu = std::make_shared<MenuHome>(m_cursor);
		break;
	case 2:
        std::dynamic_pointer_cast<ParameterPlayer>(param.getParameter(param_type))->setPlayerType("Random");
		current_menu = std::make_shared<MenuHome>(m_cursor);
		break;
	case 3:
        std::dynamic_pointer_cast<ParameterPlayer>(param.getParameter(param_type))->setPlayerType("MonteCarlo");
		current_menu = std::make_shared<MenuMonteCarlo>(m_player_color, m_cursor);
	default:
		return false;
		break;
	}
	return true;
}

// ############################################################################
// ############################# MENU MONTECARLO ##############################
// ############################################################################

MenuMonteCarlo::MenuMonteCarlo(Color player_color, std::shared_ptr<Cursor> cursor) : Menu(cursor) {
	m_player_color = player_color;
	m_question = "Nombre de partie a explorer : ";
}

bool MenuMonteCarlo::action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) {
	if (choice < 1)
		return false;
    std::string param_type = "PlayerWhite";
	if (m_player_color == Color::Black)
		param_type = "PlayerBlack";
    std::dynamic_pointer_cast<ParameterPlayer>(param.getParameter(param_type))->setMonteCarloNbGame(choice);
	current_menu = std::make_shared<MenuHome>(m_cursor);
	return true;
}
