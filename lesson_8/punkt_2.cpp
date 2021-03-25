#include "include/punkt_2.h"

EX::~EX()
{
	std::cout << "EX destruct" << std::endl;
}
Bar::~Bar()
{
	std::cout << "BAR destruct" << std::endl;
}


void Bar::Set(float a)
{
	float result = m_y + a;
	if (result > 100)
		throw EX(a*m_y);
	else
		m_y = a;
}