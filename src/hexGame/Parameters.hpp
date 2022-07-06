
#pragma once

#include "HexGameLib_export.hpp"

#include <string>
#include <map>
#include <stdexcept>

struct Parameters {
private:
	std::map<std::string, std::string> m_map;

public:
	Parameters();
	
	void addKeyValue(const std::string& key, const std::string& value);

	const std::string& getValue(const std::string& key) const;

	void setValue(const std::string key, const std::string& value);
	
	using const_iterator = std::map<std::string, std::string>::const_iterator;

	const_iterator begin();

	const_iterator end();

};
