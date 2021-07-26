////////////////////////////////////////////////////////////////////////////////
//
// Binary Table creator for simple funcsion (Boolean and others)
// BT.cpp
// Feb 14, 2013 (7:06pm) [Shahid Hussain]
// 
///////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "BT.h"
#include "random.h"


std::string CBinaryTable::toBinary(size_t dec)
{
	std::string bin = "";
	size_t x = dec;
	
	if(x == 0) { bin = "0"; }
	else
	{
		while(x > 0)
		{
			size_t r = x % 2;
			bin += std::to_string(r);
			x /= 2;
		}
	}
	return std::string(bin.rbegin(), bin.rend());
}


std::string CBinaryTable::pad(const std::string& s, size_t cols, unsigned char pc = '0')
{
	std::string bin;
	if(s.size() < m_columns)
	{
		std::string padding(m_columns - s.size(), pc);
		bin = padding;
	}

	return bin + s;
}

std::vector<std::vector<size_t>> CBinaryTable::GetTable(size_t (*func)(const std::vector<size_t>&))
{
	std::vector<size_t> f_val;
	f_val.resize(m_table.size());

	for(size_t i = 0; i < m_table.size(); ++i)
	{
		f_val[i] = (*func)(m_table[i]);
		m_table[i].push_back(f_val[i]);
	}

	return m_table;
}

std::vector<std::vector<size_t>> CBinaryTable::GetTableRand()
{
	CRandomNumber crn(m_seed);

	std::vector<size_t> f_val;
	f_val.resize(m_table.size());

	for(size_t i = 0; i < m_table.size(); ++i)
	{
		f_val[i] = crn.br();
		m_table[i].push_back(f_val[i]);
	}

	return m_table;
}

std::vector<size_t> CBinaryTable::toVector(const std::string& s)
{
	std::vector<size_t> v;
	std::copy(s.begin(), s.end(), std::back_inserter(v));

	std::for_each(v.begin(), v.end(), [](size_t& n){ n -= 48; });
	
	return v;
}

void CBinaryTable::createTable()
{
	m_table.resize(pow(m_columns));

	for(size_t row = 0; row < pow(m_columns); ++row)
	{
		std::string bin = pad(toBinary(row), m_columns);
		m_table[row].resize(m_columns);
		m_table[row] = toVector(bin);
	}
}




