////////////////////////////////////////////////////////////////////////////////
//
// Binary Table creator for simple function (Boolean and others)
// function.h
// Feb 14, 2013 (8:37pm) [Shahid Hussain]
// 
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <vector>
#include "random.h"

class CFunction
{
public:
	static size_t Sum(const std::vector<size_t> &v);
	static size_t Majority(const std::vector<size_t> &v);
	static size_t Conjunction(const std::vector<size_t> &v);
	static size_t Disjunction(const std::vector<size_t> &v);
	static size_t Count(const std::vector<size_t> &v);
	static size_t Linear(const std::vector<size_t> &v);
};

size_t CFunction::Sum(const std::vector<size_t> &v)
{
	size_t s = 0;
	std::for_each(v.begin(), v.end(), [&](size_t n) { s += n; });

	return s;
}

size_t CFunction::Majority(const std::vector<size_t> &v)
{
	size_t s = Sum(v);
	return (s > v.size() / 2) ? 1 : 0;
}

size_t CFunction::Conjunction(const std::vector<size_t> &v)
{
	size_t s = Sum(v);
	return (s == v.size()) ? 1 : 0;
}

size_t CFunction::Disjunction(const std::vector<size_t> &v)
{
	size_t s = Sum(v);
	return (s >= 1) ? 1 : 0;
}

size_t CFunction::Count(const std::vector<size_t> &v)
{
	size_t l = v.size() - 1;
	size_t c = 0;
	for_each(v.begin(), v.end(), [&](size_t n){
		if(n == 1) { c += ((size_t)1 << l);}
		l--;
	});
	return c;
}

size_t CFunction::Linear( const std::vector<size_t> &v )
{
	size_t s = Sum(v);
	return s % 2;
}

