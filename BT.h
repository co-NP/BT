////////////////////////////////////////////////////////////////////////////////
//
// Binary Table creator for simple funcsion (Boolean and others)
// BT.h
// Feb 14, 2013 (7:06pm) [Shahid Hussain]
// 
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>

class CBinaryTable
{
protected:
	size_t m_columns;
	signed long long m_seed;

	std::vector<std::vector<size_t>> m_table;

	std::string toBinary(size_t dec);
	std::string pad(const std::string& s, size_t cols, unsigned char pc);
	size_t pow(size_t n) { return !n ? 1 : (1 << n); }

	std::vector<size_t> toVector(const std::string& s);
	void createTable();

public:
	CBinaryTable(size_t cols, signed long long seed = -1) : m_columns(cols), m_seed(seed) { createTable(); }
	std::vector<std::vector<size_t>> GetTable() { return m_table; }
	std::vector<std::vector<size_t>> GetTable(size_t (*func)(const std::vector<size_t>&));
	std::vector<std::vector<size_t>> GetTableRand();
};

