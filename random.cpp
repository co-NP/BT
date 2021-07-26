// random.cpp
// sh

#pragma once

#include <iostream>
#include <string>
#include "random.h"

size_t CRandomNumber::br()
{
	return (size_t)m_g() % 2;
}
