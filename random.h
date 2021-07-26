// random.h
// sh

#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <string>
#include <assert.h>

class CRandomNumber
{
protected:
	size_t m_seed;
	std::mt19937_64 m_g;
public:
	CRandomNumber(signed long long seed)
	{
		if(seed == -1)
		{
			m_seed = (size_t)std::chrono::system_clock::now().time_since_epoch().count();
		}
		else
		{
			m_seed = seed;
		}
		m_g.seed((unsigned long)m_seed);
	}
	virtual size_t operator () ()          { return (size_t)m_g(); }
	virtual size_t operator () (size_t mx) { return (size_t)m_g() % mx; }
	virtual size_t br();
	const std::mt19937_64 generator()      { return m_g; }
};

