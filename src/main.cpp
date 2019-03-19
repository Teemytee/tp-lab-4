#include "Automata.h"

int main()
{

	Automata coffe;
	coffe.printState();
	coffe.on();
	coffe.printMenu();
	coffe.coin(100);
	coffe.cancel();
	coffe.coin(100);
	coffe.choice(0);
	coffe.finish();
	system("pause");
	return 0;
}