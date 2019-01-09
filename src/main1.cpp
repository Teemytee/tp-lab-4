#include "Automata.h"
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	Automata a;
	a.Coin(30);
	a.Coin(20);
	a.Choice(2);
	return 0;
}