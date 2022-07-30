
#pragma once

#include "Cursor.hpp"

#include <AI/MonteCarlo.hpp>
#include <Parameters.hpp>
#include <gameUtils.hpp>
#include <string>
#include <list>
#include <memory>


class Menu {
protected:
    std::shared_ptr<Cursor> m_cursor;
	std::string m_question;
	std::list<std::string> m_answers;
public:
	Menu(std::shared_ptr<Cursor> cursor);

	virtual bool action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) = 0;
    void display();
    int select();

	using const_iterator = std::list<std::string>::const_iterator;
	const_iterator begin() const;
	const_iterator end() const;
};


class MenuHome : public Menu {
public:
	MenuHome(std::shared_ptr<Cursor> cursor);
	bool action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) override;
};


class MenuBoard : public Menu {
public:
	MenuBoard(std::shared_ptr<Cursor> cursor);
	bool action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) override;
};


class MenuPlayer : public Menu {
private:
	Color m_player_color;
public:
	MenuPlayer(Color player_color, std::shared_ptr<Cursor> cursor);
	bool action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) override;
};


class MenuMonteCarlo : public Menu {
private:
	Color m_player_color;
public:
	MenuMonteCarlo(Color player_color, std::shared_ptr<Cursor> cursor);
	bool action(int choice, Parameters& param, std::shared_ptr<Menu>& current_menu) override;
};
