#include "accm.h"
#include "atmSystemControls.h"
#include <ncurses.h>

accm::accm() : currentAccountIndex(-1){}

void accm::addAcc(const char login[100], const char pass[100], double initbalance)
{
    accounts.emplace_back(login, pass, initbalance);
    mvprintw(10,10,"Creating done successfully!");
    currentAccountIndex = accounts.size() - 1;
}

bool accm::loginAcc(const char login[100], const char pass[100]) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if(accounts[i].getLogin() == login && accounts[i].getPass() == pass) {
            currentAccountIndex = i;
            mvprintw(10,10,"Logged in successful!");
            return true;
        }
    }
    mvprintw(10,10,"Login failed! Incorrect login or password.");
    return false;
}


atmsc* accm::getCurrentAccount()
{
    if (currentAccountIndex == -1 || currentAccountIndex >= accounts.size())
    {
        mvprintw(1,1,"No account selected");
        return nullptr;
    }
    return &accounts[currentAccountIndex];
}

double accm::getCurrentAccountBalance() {
    atmsc* account = getCurrentAccount();
    if (account) {
        return account->getBalance();
    }
    return 0.0;
}
