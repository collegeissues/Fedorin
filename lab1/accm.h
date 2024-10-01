#ifndef ACCM_H
#define ACCM_H
#include "atmSystemControls.h"
#include <map>
#include <vector>

class accm 
{
    public:
        accm();

        void addAcc(const char login[100], const char pass[100], double initbalance);

        atmsc* getCurrentAccount();
    private:
        std::vector<atmsc> accounts;
        int currentAccountIndex;
};

#endif
