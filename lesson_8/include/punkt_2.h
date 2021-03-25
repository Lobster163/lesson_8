#pragma once
#include <iostream>

class EX
{
	public:
		EX(float x) : m_x(x) {};
		~EX();
		float m_x;
};

class Bar
{
	public:
		Bar(float y=0) : m_y(y) {};
		~Bar();
		void Set(float a);
		float Get() { return m_y; };
	private:
		float m_y;
};


