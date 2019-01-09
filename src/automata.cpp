#include "Automata.h"
using namespace std;
void WAITFor(double seconds){
	clock_t endWAIT;
	endWAIT = static_cast<clock_t>(clock() + seconds * CLOCKS_PER_SEC);
	while (clock() < endWAIT) {}
}

void table(){
	cout << "\n___________________\n";
}

Automata::Automata(){
	cash = 0; 
	state = OFF;
	num = -1;
}

string Automata::On() {
	if (state == OFF) {
		cout << "\n����� �������� ������� ������� - on\n";
		state = WAIT; 
		table();
		cout << "������� �����";
		table();
		changeState();
		return "Ready";
	}
	else return "Already on";
}

void Automata::changeState() {
	switch (state){
	case OFF:
		table();
		cout << "***������� �� ��������***";
		table();
		break;
	case WAIT:{
		if (num == -1){
			table();
			cout << "������� ������ ��� �������� �������...";
			table();
			break;
		}
		else{
			table();
			cout << "������� ������ ��� �������� �����";
			table();
			break;
		}

	}
	case ACCEPT:{
		table();
		cout << "������: " << cash;
		table();
		if (num != -1){
			state = CHECK;
			changeState();
			break;
		}
		state = WAIT;
		changeState();
		break;
	}
	case CHECK:{
		if (cash < prices[num]){
			table();
			cout << "������������ �������\n�������� ������ ��� �������� �����..";
			cout << "\n��� ����� ��� ������� " << prices[num] - cash << "������";
			table();
			state = WAIT;
			changeState();
		}
		else{
			cook();
		};
		break;
	}
	case COOKING:
		cook();
		finish();
		break;
	}
}


void Automata::Choice(int a){
	printMenu();
	cout << "\n================================\n������� ����� �������: " << a << endl;
	cout << "================================\n";
	num = a - 1;
	cout << "\n================================\n��������� ������� " << menu[num] << endl << "================================\n";
	state = CHECK;
	changeState();
}

void Automata::Cancel(){
	cout << "\n================================\n���������� " << cash << "������..\n";
	cout << "================================\n";
	cash = 0;
	state = WAIT;
	changeState();
}

int Automata::Coin(int a){
	if (state == OFF){
		cout << "\n������� �����\n";
	}
	state = ACCEPT;
	cash = cash + a;
	changeState();
	return cash;
}

int Automata::getCash(){
	return cash;
}

int Automata::getNum(){
	return num;
}

int Automata::getChange(){
	return prices[num] - cash;
}


void Automata::printMenu(){
	int menuSize = sizeof(prices) / sizeof(int);
	table();
	for (int i = 0; i < menuSize; i++){
		cout << i + 1 << ": " << menu[i] << " - " << prices[i] << "\n";
	}
	cout << "================================\n";
}

void Automata::cook(){
	table();
	if (cash - prices[num] != 0){
		cout << "\n�� �������� �����: " << cash - prices[num] << "������" << endl;
	}
	cout << "\n���������";
	table();
	finish();
}

bool Automata::finish(){
	table();
	cout << "��� ������� �����\n";
	table();
	state = WAIT;
	cash = 0;
	num = -1;
	changeState();
	return 1;
}

void Automata::Off(){
	cout << "\n����������...\n";
	state = OFF;
	cash = 0;
	num = -1;
	changeState();
}