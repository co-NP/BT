////////////////////////////////////////////////////////////////////////////////
//
// Binary Table creator for simple funcsion (Boolean and others)
// main.cpp
// Feb 15, 2013 (8:08pm) [Shahid Hussain]
// 
///////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "BT.h"
#include "functions.h"
#include "csv_writer.h"

size_t func_val(const std::string &f)
{
	if(!f.compare("CON"))
		return 1;
	else if(!f.compare("DIS"))
		return 2;
	else if(!f.compare("MAJ"))
		return 3;
	else if(!f.compare("SUM"))
		return 4;
	else if(!f.compare("COUNT"))
		return 5;
	else if(!f.compare("LINEAR"))
		return 6;
	else if(!f.compare("RAND"))
		return 7;
	else if(!f.compare("NOFUNC"))
		return 10;
	else 
		return -1;
}

bool isHeader(const std::string &h)
{
	return (!h.compare("NOHEAD"));
}

int main(int argc, char *argv[])
{
	if(argc < 5)
	{
		std::cout << "Incorrect format." << std::endl;
		std::cout << "Usage: BT <filename> <n_cols> <function> <seed> [NOHEAD]" << std::endl;
		std::cout << "      <filename> = output file name [output is in csv format]" << std::endl;
		std::cout << "        <n_cols> = number of attributes" << std::endl;
		std::cout << "      <function> = function for computing decision attribute" << std::endl;
		std::cout << "  E.g.,     CON  = conjunction of all attributes" << std::endl;
		std::cout << "            DIS  = disjunction of all attributes" << std::endl;
		std::cout << "            MAJ  = 1 if more than half of attributes are 1 else 0" << std::endl;
		std::cout << "            SUM  = sum of attribute values" << std::endl;
		std::cout << "           COUNT = sequence of integer [dec value of attributes]" << std::endl;
		std::cout << "          LINEAR = linear functions modulo 2" << std::endl;
		std::cout << "            RAND = random 0-1" << std::endl;
		std::cout << "          NOFUNC = no function attached" << std::endl;
		std::cout << "          <seed> = random seed, -1 for random seed" << std::endl;
		std::cout << "        [NOHEAD] = is an optional parameter that does not create header." << std::endl;
	}
	else
	{

		std::string filename  = argv[1];
		size_t      n_cols    = std::stoi(argv[2]);
		std::string func      = argv[3];
		signed long long seed = std::stoi(argv[4]);
		
	
		std::vector<std::vector<size_t>> data;
		bool error = false;
		CBinaryTable cbt(n_cols, seed);
		
		switch(func_val(func))
		{
		case 1: // CON
			data = cbt.GetTable(CFunction::Conjunction);
			break;
		case 2: // DIS
			data = cbt.GetTable(CFunction::Disjunction);
			break;
		case 3: // MAJ
			data = cbt.GetTable(CFunction::Majority);
			break;
		case 4: // SUM
			data = cbt.GetTable(CFunction::Sum);
			break;
		case 5: // COUNT
			data = cbt.GetTable(CFunction::Count);
			break;
		case 6:
			data = cbt.GetTable(CFunction::Linear);
			break;
		case 7: // RAND
			data = cbt.GetTableRand();
			break;
		case 10: // NOFUNC
			data = cbt.GetTable();
			break;
		default:
			error = true;
		};
		if(!error)
		{
			bool h = false;
			if(argc == 5) h = isHeader(argv[4]);

			CCSVWriter csv_writer(filename, n_cols + 1, !h);
			for(size_t i = 0; i < data.size(); ++i)
			{
				csv_writer.addline(data[i]);
			}
			std::cout << filename << ": done." << std::endl;
		}
		else
		{
			std::cout << "Undefined function type: " << func  << std::endl;
		}
	}
	return 0;
}
