
#include "CSVwriter.hpp"


CSVwriter::CSVwriter(const std::string& fileName, char delimiter, char comment) :
	m_fileName(fileName), m_delimiter(delimiter), m_comment(comment)
{
	m_file.open(m_fileName, std::ios::out | std::ios::app);
}


CSVwriter::~CSVwriter()
{
	m_file.close();
}


void CSVwriter::write(const std::string& text) {
	m_file << text;
}


void CSVwriter::writeComment(const std::string& comment)
{
	m_file << m_comment << " " << comment << std::endl;
}


void CSVwriter::writeDataLine(const std::vector<double>& vect)
{
	std::vector<double>::const_iterator it = vect.begin();
	while (it != vect.end())
	{
		m_file << *it;
		++it;
		if (it != vect.end())
			m_file << m_delimiter << " ";
	}
	m_file << std::endl;
}


void CSVwriter::writeHeader(const std::vector<std::string>& vect)
{
	std::vector<std::string>::const_iterator it = vect.begin();
	while (it != vect.end())
	{
		m_file << *it;
		++it;
		if (it != vect.end())
			m_file << m_delimiter << " ";
	}
	m_file << std::endl;
}
