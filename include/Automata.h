#pragma once
#include <iostream>
#include <string>
const char cur_state[5][7] = { "off", "wait", "accept", "check", "cook" };

class Automata {
private:
	double money;
	double cash;
	const char menu[6][20] = { "ESPRESSO", "DUO ESPRESSO", "AMERICANO", "LATTE", "CAPPUCCINO", "HOT CHOCOLATE" };
	double price[6] = { 90.0, 120.0, 150.0, 210.0, 210.0, 180.0 };
	unsigned int state;
public:
	Automata();
	void on();
	void off();
	void coin(double);
	void printMenu();
	unsigned int printState();
	void choice(int);
	bool check(int);
	double cancel();
	void cook(int);
	double finish();
};