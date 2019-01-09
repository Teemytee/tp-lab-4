#include "gtest/gtest.h"
#include "Automata.h"
#include <string>

using namespace std;

Automata a;

TEST(Test, ON) {
	string temp = a.On();
	EXPECT_EQ("Ready", temp);
}

TEST(Test, twoCoins) {
	a.Coin(30);
	a.Coin(3);
	EXPECT_EQ(33, a.getCash());
}

TEST(Test, Cancel) {
	a.Coin(35);
	a.Cancel();
	a.Coin(1);
	EXPECT_EQ(1, a.getCash());
}

TEST(Test, finish) {
	a.Coin(60);
	a.Choice(1);
	EXPECT_EQ(0, a.getCash());
	EXPECT_EQ(-1, a.getNum());
}

TEST(Test, Cancel2) {
	a.Coin(35);
	a.Coin(10);
	a.Choice(2);
	a.Cancel();
	a.Coin(30);
	a.Choice(1);
	EXPECT_EQ(0, a.getCash());
	EXPECT_EQ(-1, a.getNum());
}

TEST(Test, OFF) {
	a.Coin(29);
	a.Off();
	EXPECT_EQ(0, a.getCash());
	EXPECT_EQ(-1, a.getNum());
}

TEST(Test, On_while_working) {
	a.Coin(29);
	EXPECT_EQ("Already on", a.On());
}
