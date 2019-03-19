#include "gtest/gtest.h"
#include "automata.h"
#include <string>

using namespace std;

//simple
TEST(lab4, scene1)
{
	Automata nc;
	string h = nc.on();
	EXPECT_EQ("THE MACHINE HAS TURNED ON", h);

	nc.coin(10);
	int c = nc.getcash();
	EXPECT_EQ(10, c);

	nc.coin(30);
	EXPECT_EQ(ACCEPT, nc.getstate());

	string ans = nc.choice(2);
	EXPECT_EQ("ENJOY YOUR DRINK", ans);
}
// double on()
TEST(lab4, scene2)
{
	Automata nc;
	string h = nc.on();
	EXPECT_EQ("THE MACHINE HAS TURNED ON", h);
	h = nc.on();
	EXPECT_EQ("THE MACHINE HAS ALREADY TURNED ON", h);

	nc.coin(10);
	int c = nc.getcash();
	EXPECT_EQ(10, c);

	nc.coin(30);
	EXPECT_EQ(ACCEPT, nc.getstate());

	string ans = nc.choice(2);
	EXPECT_EQ("ENJOY YOUR DRINK", ans);
}
//off
TEST(lab4, scene3)
{
	Automata nc;
	string h = nc.on();
	EXPECT_EQ("THE MACHINE HAS TURNED ON", h);

	nc.coin(10);
	int c = nc.getcash();
	EXPECT_EQ(10, c);

	nc.coin(30);
	EXPECT_EQ(ACCEPT, nc.getstate());

	string ans = nc.choice(2);
	EXPECT_EQ("ENJOY YOUR DRINK", ans);

	ans = nc.off();
	EXPECT_EQ("THE MACHINE HAS TURNED OFF", ans);
}

//not enough money
TEST(lab4, scene4)
{
	Automata nc;
	nc.on();
	nc.coin(10);
	string ans = nc.choice(2);
	EXPECT_EQ("ERROR. NOT ENOUGHT MONEY", ans);
	nc.off();
}

//wrong number of drinks
TEST(lab4, scene5)
{
	Automata nc;
	nc.on();
	nc.coin(50);
	string ans = nc.choice(16);
	EXPECT_EQ("ERROR. INVALID NUMBER", ans);
	nc.off();
}
//another one simple (WAIT AFTER FINISH)
TEST(lab4, scene6)
{
	Automata nc;
	string h = nc.on();
	EXPECT_EQ("THE MACHINE HAS TURNED ON", h);

	nc.coin(10);
	int c = nc.getcash();
	EXPECT_EQ(10, c);

	nc.coin(30);
	EXPECT_EQ(ACCEPT, nc.getstate());

	string ans = nc.choice(2);
	EXPECT_EQ("ENJOY YOUR DRINK", ans);

	EXPECT_EQ(WAIT, nc.getstate());
}

//another one simple (CASH AFTER FINISH)
TEST(lab4, scene7)
{
	Automata nc;
	string h = nc.on();
	EXPECT_EQ("THE MACHINE HAS TURNED ON", h);

	nc.coin(10);
	int c = nc.getcash();
	EXPECT_EQ(10, c);

	nc.coin(30);
	EXPECT_EQ(ACCEPT, nc.getstate());

	string ans = nc.choice(2);
	EXPECT_EQ("ENJOY YOUR DRINK", ans);

	EXPECT_EQ(WAIT, nc.getstate());

	EXPECT_EQ(0, nc.getcash());
}


// choosing after an error(number of drink)
TEST(lab4, scene8)
{
	Automata nc;
	nc.on();
	nc.coin(50);
	nc.choice(16);

	string ans = nc.choice(1);
	EXPECT_EQ("ENJOY YOUR DRINK", ans);

	nc.off();
}

// choosing after an error(money)
TEST(lab4, scene9)
{
	Automata nc;
	nc.on();
	nc.coin(10);
	string ans = nc.choice(1);
	EXPECT_EQ("ERROR. NOT ENOUGHT MONEY", ans);

	nc.coin(10);
	EXPECT_EQ(20, nc.getcash());

	ans = nc.choice(1);
	EXPECT_EQ("ENJOY YOUR DRINK", ans);

	nc.off();
}

