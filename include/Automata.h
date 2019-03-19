#ifndef AUTOMATA_AUTOMATA_H
#define AUTOMATA_AUTOMATA_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

enum STATES { OFF, WAIT, ACCEPT, CHECK, COOK };
class Automata{
private:
	int state;
	int cash;
	string menu[6] = { "TEA", "AMERICANO", "LATTE", "HOT CHOCOLATE", "HOT MILK", "HOT WATER" };
	int prices[6] = { 20, 30, 40, 50, 35, 20 };

public:
	Automata();
	string on();
	string off();
	void coin(int x);
	void printMenu();
	void printState();
	string  choice(int num);
	bool check(int num) const;
	void cancel();
	void cook(int num);
	void finish();
	int getcash() const;
	const int getstate() const;

};




#endif