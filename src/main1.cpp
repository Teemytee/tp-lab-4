#include <iostream>
#include "automata.h"
using namespace std;

int main() {
	enum state { OFF, ON, ACCEPT, CHECK, COOK };
	state st = OFF;
	Automata nc;
	nc.printMenu();
	string h = nc.on();
	cout << h << endl;
	nc.coin(10);
	nc.coin(30);
	cout << "sada" << endl;
	int c = nc.getcash();
	cout << c << endl;
	if (ACCEPT == nc.getstate())
		cout << "sada" << endl;
	string ans = nc.choice(2);
	cout << ans << endl;
	nc.printState();
	if (WAIT == nc.getstate())
		cout << "sada" << endl;

	return 0;
}