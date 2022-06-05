
#pragma once

#include <string>
#include <fstream>
#include <vector>

class CSVwriter {
private:
	std::string m_fileName;
	char m_delimiter;
	char m_comment;
	std::fstream m_file;


public:
	CSVwriter(const std::string& fileName, char delimiter=';', char comment='#');
	~CSVwriter();

	void write(const std::string& text);
	void writeComment(const std::string& comment);
	void writeDataLine(const std::vector<double>& vect);
	void writeHeader(const std::vector<std::string>& vect);
};
