
#include "Menu.hpp"

MenuHome::MenuHome() {
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
		current_menu = std::make_shared<MenuBoard>();
		break;
	case 3:
		current_menu = std::make_shared<MenuPlayer>(Color::White);
		break;
	case 4:
		current_menu = std::make_shared<MenuPlayer>(Color::Black);
		break;
	default:
		return false;
		break;
	}
	return true;
}

MenuBoard::MenuBoard() {
	m_question = "taille du plateau : ";
}

bool MenuBoard::action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) {
	if (choice % 2 == 1) {
		param.setValue("BoardSize", std::to_string(choice));
		current_menu = std::make_shared<MenuHome>();
		return true;
	} else {
		return false;
	}
}

MenuPlayer::MenuPlayer(Color player_color) {
	m_player_color = player_color;
	m_question = "Quel type de joueur : ";
	m_answers.push_back("Humain");
	m_answers.push_back("Aleatoire");
	m_answers.push_back("MonteCarlo");
}

bool MenuPlayer::action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) {
	std::string param_type = "PlayerWhiteType";
	if (m_player_color == Color::Black)
		param_type = "PlayerBlackType";
	switch (choice)
	{
	case 1:
		param.setValue(param_type, "Human");
		current_menu = std::make_shared<MenuHome>();
		break;
	case 2:
		param.setValue(param_type, "Random");
		current_menu = std::make_shared<MenuHome>();
		break;
	case 3:
		param.setValue(param_type, "MonteCarlo");
		current_menu = std::make_shared<MenuMonteCarlo>(m_player_color);
	default:
		return false;
		break;
	}
	return true;
}


MenuMonteCarlo::MenuMonteCarlo(Color player_color) {
	m_player_color = player_color;
	m_question = "Nombre de partie à explorer : ";
}

bool MenuMonteCarlo::action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) {
	if (choice < 1)
		return false;
	param.setValue("MonteCarloNbGame", std::to_string(choice));
	current_menu = std::make_shared<MenuHome>();
	return true;
}

