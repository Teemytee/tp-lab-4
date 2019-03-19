#include "Automata.h"

Automata::Automata()
{
	this->money = 100;
	this->cash = 0;
	this->state = 0;
};
void Automata::on()
{
	this->state = 1;
	this->printState();
}
void Automata::off()
{
	this->state = 0;
}
void Automata::coin(double money)
{
	if (state != 0)
	{
		this->state = 2;
		this->printState();
		this->cash = money;
	}
	else
	{
		std::cout << "THE AUTOMATA IS OFF NOW, PLS TURN ON TO START" << std::endl;
		return;
	}

}
void  Automata::printMenu()
{
	if (this->state != 0)
	{
		for (auto i = 0; i < 6; i++)
		{
			std::cout << "To select " << menu[i] << " (" << price[i] << "$) press " << i << std::endl;
		}
	}
	else
	{
		std::cout << "THE AUTOMATA IS OFF NOW, PLS TURN ON TO START" << std::endl;
	}

}
unsigned int Automata::printState()
{
	std::cout << cur_state[this->state] << std::endl;
	return this->state;
}
//
bool  Automata::check(int choice)
{
	if (this->state = 3)
	{
		if (cash < price[choice])
		{
			std::cout << "You have no enough money. Add more or cancel the operation";
			return false;
		}
		else
		{
			return true;
		}
	}

}
void  Automata::choice(int choice)
{
	this->state = 3;
	this->printState();
	bool response = check(choice);
	if (response == true)
	{
		cook(choice);
	}
}
double  Automata::cancel()
{
	if (this->state != 0)
	{
		double change = cash;
		cash = 0;
		std::cout << "Please take your money ( " << change << "$ ) !" << std::endl;
		this->state = 1;
		return change;
	}
	else
	{
		std::cout << "THE AUTOMATA IS OFF NOW, PLS TURN ON TO START" << std::endl;
	}
}
void  Automata::cook(int choice)
{
	if (state = 3)
	{
		this->state = 4;
		this->printState();
		this->money += price[choice];
		this->cash -= price[choice];
		char a = 177, b = 219;
		std::cout << "\n\n\nPlease take your " << menu[choice] << "!\n ";
	}

}
double  Automata::finish()
{
	if (cash > 0)
	{
		std::cout << "\nKeep your change " << cash << " !" << std::endl;
		double change = cash;
		cash = 0;
		state = 1;
		this->state = 1;
		this->printState();
		return change;

	}
	this->state = 1;
	this->printState();
	return 0;
}