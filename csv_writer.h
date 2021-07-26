////////////////////////////////////////////////////////////////////////////////
//
// Binary Table creator for simple funcsion (Boolean and others)
// csv_writer.h
// Feb 15, 2013 (7:02pm) [Shahid Hussain]
// 
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class CCSVWriter
{
protected:
	std::string   m_filename;
	std::ofstream m_file;
	size_t        m_columns;

	void prologue();
	void epilogue();

public:
	CCSVWriter(const std::string &filename, size_t cols, bool header);
	virtual ~CCSVWriter() { m_file.close(); }
	void addline(const std::vector<size_t>& line);
};