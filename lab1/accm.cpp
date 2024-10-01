#include "accm.h"
#include "atmSystemControls.h"
#include <ncurses.h>

accm::accm() : currentAccountIndex(-1){}

void accm::addAcc(const char login[100], const char pass[100], double initbalance)
{
    accounts.emplace_back(login, pass, initbalance);
    mvprintw(1,1,"Creating done successfully!");
}

atmsc* accm::getCurrentAccount()
{
    if (currentAccountIndex == -1)
    {
        mvprintw(1,1,"No account selected");
        return nullptr;
    }
    return &accounts[currentAccountIndex];
}
