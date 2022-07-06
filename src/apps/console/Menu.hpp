
#pragma once

#include <AI/MonteCarlo.hpp>
#include <Parameters.hpp>
#include <gameUtils.hpp>
#include <string>
#include <list>
#include <memory>

class Menu {
protected:
	std::string m_question;
	std::list<std::string> m_answers;
public:
	Menu() = default;

	virtual bool action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) = 0;
	
	const std::string& getQuestion() {
		return m_question;
	} 

	using const_iterator = std::list<std::string>::const_iterator;

	const_iterator begin() const {
		return m_answers.begin();
	}

	const_iterator end() const {
		return m_answers.end();
	}
};

class MenuHome : public Menu {
public:
	MenuHome();
	bool action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) override;
};

class MenuBoard : public Menu {
public:
	MenuBoard();
	bool action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) override;
};

class MenuPlayer : public Menu {
private:
	Color m_player_color;
public:
	MenuPlayer(Color player_color);
	bool action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) override;
};

class MenuMonteCarlo : public Menu {
private:
	Color m_player_color;
public:
	MenuMonteCarlo(Color player_color);
	bool action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) override;
};
