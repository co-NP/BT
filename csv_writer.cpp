////////////////////////////////////////////////////////////////////////////////
//
// Binary Table creator for simple funcsion (Boolean and others)
// csv_writer.cpp
// Feb 15, 2013 (7:02pm) [Shahid Hussain]
// 
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "csv_writer.h"

CCSVWriter::CCSVWriter(const std::string& filename, size_t cols, bool header) : m_filename(filename), m_columns(cols)
{
	m_file.open(m_filename);
	if(header) prologue();
}

void CCSVWriter::prologue()
{
	for(size_t i = 0; i < m_columns - 1; ++i)
	{
		m_file << "f" << i + 1 << ",";
	}
	m_file << "class" << std::endl;
	for(size_t i = 0; i < m_columns - 1; ++i)
	{
		m_file << "c" << ",";
	}
	m_file << "c" << std::endl;;
}


void CCSVWriter::epilogue()
{
}

void CCSVWriter::addline(const std::vector<size_t>& line)
{
	size_t s = line.size();
	for(size_t i = 0; i < s; ++i)
	{
		m_file << line[i];
		if(i < s - 1) { m_file << ","; }
	}
	m_file << std::endl;
}