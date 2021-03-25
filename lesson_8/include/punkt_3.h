#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <conio.h>
#include <windows.h>

using namespace std;

static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
static COORD position;

class Point
{
	public:
		Point() {};
		~Point() {};
		bool GetStatus() { return busy;  }
		void SetStatus(bool status) { busy = status; }

	private:
		bool busy = false;

};

class Deck
{
	public:
		Deck();
		~Deck() { cout << "Deck desctruct" << endl; };
		friend ostream& operator<<(ostream& out, const Deck& genPlayer);
		auto& GetMatrix() { return matrix; };

	private:
		vector<std::vector<unique_ptr<Point>>> matrix;
};

enum CMD
{
	left,
	right,
	up,
	down
};

string GetNameCMD(CMD cmd);

class Robot
{	
	public:		
		Robot(int pos_x = 0, int pos_y = 0);
		~Robot() { cout << "Robot desctruct" << endl; };
		void ChangePosition(CMD cmd);
		void PrintDeck();
	private:	
		void SetPosition(int pos_x, int pos_y, bool activ);
		unique_ptr<Deck> m_desk;
		int m_pos_x = 0;
		int m_pos_y = 0;

};

class ExceptionRobot
{
	public:
		ExceptionRobot(int pos_x, int pos_y, CMD cmd): m_pos_x(pos_x), m_pos_y(pos_y), m_cmd(cmd){};
		virtual ~ExceptionRobot() { };
		int m_pos_x = 0;
		int m_pos_y = 0;
		CMD m_cmd;
};

class OffTheField : public ExceptionRobot
{
	public:
		OffTheField(int pos_x, int pos_y, CMD cmd) : ExceptionRobot(pos_x, pos_y, cmd) {};
		~OffTheField() { cout << "OffTheField desctruct" << endl; };
};

class IllegalCommand : public ExceptionRobot
{
public:
	IllegalCommand(int pos_x, int pos_y, CMD cmd) : ExceptionRobot(pos_x, pos_y, cmd) {};
	~IllegalCommand() { cout << "IllegalCommand desctruct" << endl; };
};