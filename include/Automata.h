#ifndef AUTOMATA_H
#define AUTOMATA_H

#include <string>
#include <iostream>
#include <ctime>

using namespace std;

class Automata {
private:
	enum STATES { OFF, WAIT, CHECK, ACCEPT, COOKING };
	int cash, num = -1;
	string menu[3] = { "tea", "americano", "latte" };
	int prices[3] = { 30, 50, 50 };
	STATES state;
	void changeState();
	void printMenu();
	void cook();
	bool finish();

public:

	Automata();
	string On();
	void Off();
	void Choice(int a);
	int Coin(int a);
	int getCash();
	int getNum();
	int getChange();
	void Cancel();
};


#endif