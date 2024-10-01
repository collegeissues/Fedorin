//#include <iostream>
#include <ncurses.h>
//#include <string>
//#include <type_traits>
#include "atmSystemControls.h"
//#include "accm.h"

atmsc::atmsc(const char login[100], const char pass[100], double initbalance) : plogin(login), ppass(pass), pinitbalance(initbalance) {}

bool atmsc::withdraw(double amount)
{
    if(amount > pinitbalance)
    {
        mvprintw(1,1,"Invalid amount to withdraw");
    }
    pinitbalance -= amount;
    return true;
}

void atmsc::deposit(double amount)
{
    pinitbalance += amount;
}
