#include "gtest/gtest.h"
#include "../include/Automata.h"


// task1
TEST(lab4,task1_1)
{
Automata vender;
unsigned int state_off=0;
EXPECT_EQ(state_off,vender.printState);
}
TEST(lab4,task1_2)
{
Automata vender;
vender.on();
unsigned int state_wait=1;
EXPECT_EQ(state_wait,vender.printState);
}
// task2
TEST(lab4,task2_1)
{
double change=199.5;
Automata vender;
vender.on();
vender.coin(change);
EXPECT_EQ(change,vender.cancel());
}
TEST(lab4,task2_2)
{
Automata vender;
unsigned int state_off=0;
vender.coin(199.5);
EXPECT_EQ(state_off,vender.printState);
}
TEST(lab1,task2_3)
{
double cash=100;
Automata vender;
vender.on();
vender.coin(cash);
EXPECT_EQ(cash,vender.cancel());
}
TEST(lab1,task2_4)
{
double cash=100;
Automata vender;
vender.on();
vender.coin(cash);
vender.choice(0);
double change=cash-90;
EXPECT_EQ(change,vender.finish());
}
