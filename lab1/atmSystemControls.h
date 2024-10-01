#ifndef atmSystemControls_H
#define atmSystemControls_H

#include <string>

class atmsc 
{
    public:
        atmsc(const char login[100], const char pass[100], double initbalance);
        bool withdraw(double amount);
        void deposit(double amount);
    private:
        std::string plogin;
        std::string ppass;
        double pinitbalance;
};
#endif
