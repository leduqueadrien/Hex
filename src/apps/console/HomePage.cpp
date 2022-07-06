
#include "HomePage.hpp"
#include <iostream>
#include <cstdlib>

HomePage::HomePage() : m_current_menu(std::make_shared<MenuHome>()) {}

Parameters HomePage::navigate() {
	int choice;
	while (m_current_menu != nullptr) {
		std::cout << "SELECT" << std::endl;
		displayMenu();
		choice = select();
		m_current_menu->action(choice, m_parameters, m_current_menu);
	}
    return m_parameters;
}

void HomePage::displayMenu() {
	Menu::const_iterator it;
	int cnt = 1;
	std::cout << m_current_menu->getQuestion()	 << std::endl;
	for (it=m_current_menu->begin(); it!=m_current_menu->end(); ++it) {
		std::cout << cnt << " -> " << *it << std::endl;
		++cnt;
	}
}

int HomePage::select() {
	int value;
	std::cin >> value;
	return value;
}

void HomePage::displayParameters() {
	std::cout << "PARAMETERS : " << std::endl;
	Parameters::const_iterator it;
	for (it=m_parameters.begin(); it != m_parameters.end(); ++it)
		std::cout << it->first << ", " << it->second << std::endl;
}
