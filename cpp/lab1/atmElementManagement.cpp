//#include <iostream>
#include <ncurses.h>
//#include <string>
//#include <type_traits>
#include "atmSystemControls.h"
//#include "accm.h"

atmsc::atmsc(const char login[100], const char pass[100], double initbalance) : plogin(login), ppass(pass), pinitbalance(initbalance) {}

std::string atmsc::getLogin() const {
    return plogin;
}

std::string atmsc::getPass() const {
    return ppass;
}

bool atmsc::withdraw(double amount)
{
    if(amount > pinitbalance || amount < 0)
    {
        return false;
    }
    pinitbalance -= amount;
    return true;
}

void atmsc::deposit(double amount)
{
    if(amount < 0) {
        mvprintw(10,10,"Invalid amount to deposit");
    }
    else {
        pinitbalance += amount;
    }
}

double atmsc::getBalance() const{
    return pinitbalance;
}
