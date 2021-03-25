#include "include/punkt_3.h"

Deck::Deck()
{
	matrix.resize(10);
	for (int i = 0; i < 10; i++)
	{
		matrix[i].resize(10);
		for (int z = 0; z < 10; z++)
			matrix[i][z] = std::make_unique<Point>();
	}
}

std::ostream& operator<<(std::ostream& out, const Deck& deck)
{
	for (auto &rows : deck.matrix)
	{
		for (auto &cols: rows)
		{
			out << cols->GetStatus() << " ";
		}
		out << "\n";
	}
	return out << endl;	
}

Robot::Robot(int pos_x, int pos_y) : m_pos_x(pos_x), m_pos_y(pos_y)
{
	m_desk = make_unique<Deck>();
	SetPosition(pos_x, pos_y, true);
}

void Robot::SetPosition(int pos_x, int pos_y, bool activ)
{
	m_desk->GetMatrix()[pos_y][pos_x]->SetStatus(activ);
}

void Robot::ChangePosition(CMD cmd)
{
	switch (cmd)
	{
	case CMD::left:
		if (m_pos_x == 0)
			throw OffTheField(m_pos_x, m_pos_y, cmd);
		SetPosition(m_pos_x--, m_pos_y, false);
		SetPosition(m_pos_x, m_pos_y, true);
		break;		
	case CMD::right:
		if (m_pos_x == 9)
			throw OffTheField(m_pos_x, m_pos_y, cmd);
		SetPosition(m_pos_x++, m_pos_y, false);
		SetPosition(m_pos_x, m_pos_y, true);
		break;
	case CMD::up:
		if (m_pos_y == 0)
			throw OffTheField(m_pos_x, m_pos_y, cmd);
		SetPosition(m_pos_x, m_pos_y--, false);
		SetPosition(m_pos_x, m_pos_y, true);
		break;
	case CMD::down:
		if (m_pos_y == 9)
			throw OffTheField(m_pos_x, m_pos_y, cmd);
		SetPosition(m_pos_x, m_pos_y++, false);
		SetPosition(m_pos_x, m_pos_y, true);
		break;
	default:
		break;
	}
}

void Robot::PrintDeck() 
{ 
	std::cout << *m_desk; 
	position = { short(m_pos_x + m_pos_x), short(m_pos_y + 1) };
	SetConsoleCursorPosition(hConsole, position);
}


string GetNameCMD(CMD cmd)
{
	switch (cmd)
	{
	case CMD::left:
		return "left";
		break;
	case CMD::right:
		return "right";
		break;
	case CMD::up:
		return "up";
		break;
	case CMD::down:
		return "down";
		break;
	}
}