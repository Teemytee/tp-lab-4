#include "automata.h"
using namespace std;

Automata::Automata() {
	this->state = OFF;
	this->cash = 0;
}

string Automata::on(){
	if (state == OFF) {
		state = WAIT;
		return "THE MACHINE HAS TURNED ON";
	}
	else
		return "THE MACHINE HAS ALREADY TURNED ON";
}

string Automata::off(){
	if (state == COOK) {
		return "WAIT. COOKING";
	}
	else {
		cancel();
		state = OFF;
		return "THE MACHINE HAS TURNED OFF";
	}
}

void Automata::coin(int x){
	switch (state){
	case(OFF) :
		break;
	case(WAIT) :
		state = ACCEPT;
		cash = x;
		break;
	case(ACCEPT) :
		cash += x;
		break;
	case(CHECK) :
		state = ACCEPT;
		cash += x;
		break;
	case(COOK) :
		break;
	}
}

void Automata::printMenu() {
	for (int i = 0; i < (sizeof(this->prices) / 4); i++)
		cout << i + 1 << ": " << this->menu[i] << endl;
}

void Automata::printState() {
	switch (state){
	case(OFF) :
		cout << "OFF" << endl;
		break;
	case(WAIT) :
		cout << "WAIT" << endl;
		break;
	case(ACCEPT) :
		cout << "ACCEPT" << endl;
		break;
	case(CHECK) :
		cout << "CHECK" << endl;
		break;
	case(COOK) :
		cout << "COOK" << endl;
		break;
	}
}

string Automata::choice(int num) {
	if (state == COOK){
		return "WAIT. COOKING";
	}
	else {
		if ((num < 1) or(num >(sizeof(this->prices) / 4))){
			return "ERROR. INVALID NUMBER";
		}
		else {
			num = num - 1;
			if (check(num)) {
				state = COOK;
				cook(num);
				cash = cash - prices[num];
				cancel();
				return "ENJOY YOUR DRINK";
			}
			else
				return "ERROR. NOT ENOUGHT MONEY";
		}
	}
}

bool Automata::check(int num) const {
	if (cash >= prices[num])
		return true;
	else
		return false;
}



void Automata::cancel(){
	if (cash) {
		cash = 0;
		state = WAIT;
	}
}

void Automata::cook(int num) {
	//sleep_for(5s);
	finish();
}

void Automata::finish() {
	state = WAIT;
}

int Automata::getcash() const{
	return cash;
}

const int Automata::getstate() const{
	return state;
}