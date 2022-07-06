
#pragma once

#include "Menu.hpp"
#include <Parameters.hpp>
#include <list>
#include <string>
#include <memory>


class HomePage {
private:
	std::shared_ptr<Menu> m_current_menu;
	Parameters m_parameters;

public:
	HomePage();
	Parameters navigate();
	void displayMenu();
	int select();
	void lunchGame();
	void displayParameters();
};
