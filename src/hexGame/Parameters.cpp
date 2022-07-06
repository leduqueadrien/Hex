
#include "Parameters.hpp"

Parameters::Parameters() {
	setValue("BoardSize", "7");
    setValue("PlayerWhiteType", "Human");
	setValue("PlayerBlackType", "MonteCarlo");
	setValue("MonteCarloNbGame", "100");
}

void Parameters::addKeyValue(const std::string& key, const std::string& value) {
	m_map.insert({key, value});
}

const std::string& Parameters::getValue(const std::string& key) const {
	return m_map.at(key);
}

void Parameters::setValue(const std::string key, const std::string& value) {
	m_map.insert_or_assign(key, value);
}

Parameters::const_iterator Parameters::begin() {
	return m_map.begin();
}

Parameters::const_iterator Parameters::end() {
	return m_map.end();
}
