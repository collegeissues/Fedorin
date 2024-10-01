#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//#include <iostream>
#include "accm.h"
#include "atmSystemControls.h"
//#include "atmSystemControls.h"
#include <ncurses.h>
#include <unistd.h>
//#include <string>
// WARN! Compile with atmElementManagement.cpp
//
// thx <3

int auth;
char templog[100];
char temppass[100];
char amountm[100];
int userCounter=0;

accm accm;

int main()
{
    initscr();
    curs_set(0);
    keypad(stdscr, 1);

    int ch;
    int maxY;
    unsigned x=0,y=5;
    auth=0;

    do
    {
        if(auth==0)
        {
            mvprintw(1,5,"ATM emulate    [GUEST]");
            mvprintw(5,5,"Log/Sign-in");
            maxY=5;
            refresh();
        }
        else if(auth==1)
        {
            mvprintw(1,5,"ATM emulate");
            mvprintw(1,21,"[");mvprintw(1,22,templog);mvprintw(1,22+strlen(templog),"]");
            mvprintw(5,5,"Withdraw");
            mvprintw(6,5,"Deposit");
            mvprintw(7,5,"Personal");
            mvprintw(8,5,"Logout");
            maxY=8;
            refresh();
        }
        mvprintw(10,5,"Q - exit    I - about    Arrows to interact    S - submit");
        refresh();
        ch = getch();
        switch (ch) 
        {
            case KEY_UP    : mvprintw(y,19,"<<");if(y>5){y--;mvprintw(y+1,19,"  ");mvprintw(y,19,"<<");}break;
            case KEY_DOWN  : mvprintw(y,19,"<<");if(y<maxY){y++;mvprintw(y-1,19,"   ");mvprintw(y,19,"<<");}break;
            case 's':
                if(maxY==8 && y==7)
                {
                    int tempYpos=1;
                    clear();
                    mvprintw(1,5,"authorized as ");
                    if (strlen(templog)>8){tempYpos=2;}; 
                    mvprintw(tempYpos,27-strlen(templog),"[");
                    mvprintw(tempYpos,28-strlen(templog),templog);
                    mvprintw(tempYpos,28,"]");
                    mvprintw(4,5,"------------------------");
                    mvprintw(5,5,"| Personal Information |");
                    mvprintw(6,5,"------------------------");
                    mvprintw(8,5,"Name |");
                    mvprintw(8,29-strlen(templog),templog);
                    mvprintw(9,5,"Balance |        100,23$");
                    mvprintw(10,5,"Bill number |  123456789");
                    mvprintw(14,5,"------------------------");
                    mvprintw(15,5,"Press any button to exit");
                    ch = getch();
                    clear();
                    switch(ch){case'q':break;};                    
                }
                else if (maxY==8 && y==5) 
                {
                    int tempYpos=1;
                    clear();

                    atmsc* atmsc = accm.getCurrentAccount();

                    mvprintw(1,5,"authorized as ");
                    if (strlen(templog)>8){tempYpos=2;};
                    mvprintw(tempYpos,27-strlen(templog),"[");
                    mvprintw(tempYpos,28-strlen(templog),templog);
                    mvprintw(tempYpos,28,"]");
                    mvprintw(4,5,"------------------------");
                    mvprintw(5,5,"|       Withdrawal     |");
                    mvprintw(6,5,"------------------------");
                    mvprintw(14,5,"------------------------");
                    mvprintw(15,5,"Press any button to exit");
                    mvprintw(8,5,"Amount to deposit: ");
                    getstr(amountm);
                    double amount;
                    if (atmsc->withdraw(amount))
                    {
                        mvprintw(1,1,"Successes!");
                    }
                    ch=getch();
                    clear();
                    switch(ch){case'q':break;};
                }
                else if (maxY==8 && y==6)
                {
                    int tempYpos=1;
                    clear();

                    atmsc* atmsc = accm.getCurrentAccount();

                    mvprintw(1,5,"authorized as ");
                    if (strlen(templog)>8){tempYpos=2;};
                    mvprintw(tempYpos,27-strlen(templog),"[");
                    mvprintw(tempYpos,28-strlen(templog),templog);
                    mvprintw(tempYpos,28,"]");
                    mvprintw(4,5,"------------------------");
                    mvprintw(5,5,"|        Deposit       |");
                    mvprintw(6,5,"------------------------");
                    mvprintw(14,5,"------------------------");
                    mvprintw(15,5,"Press any button to exit");
                    mvprintw(8,5,"Amount to deposit: ");
                    double amount;
                    getstr(amountm);
                    atmsc->deposit(amount);
                    mvprintw(1,1,"Successes!");
                    ch=getch();
                    clear();
                    switch(ch){case'q':break;};
                }
                else if (maxY==8 && y==8){
                    clear();
                    refresh();
                    auth=0;
                }
                else if(auth==0)
                {
                    bool tempchoice=1;
                    clear();
                    mvprintw(1,5,"ATM emulate    [...]");
                    mvprintw(5,7," LOGIN     SIGNIN ");
                    mvprintw(10,5,"Q - exit    S - submit");
                    do
                    {
                        ch = getch();
                        switch (ch)
                        {
                            case KEY_LEFT  : mvprintw(5,7,"[LOGIN]    SIGNIN ");tempchoice=1;break;
                            case KEY_RIGHT : mvprintw(5,7," LOGIN    [SIGNIN]");tempchoice=0;break;
                            case 's':
                                if(tempchoice)
                                {
                                    clear();
                                    templog[1] = ' ';
                                    mvprintw(1,5,"IDENTIFY YOURSELF");
                                    mvprintw(5,5,"Login: ");
                                    getstr(templog); 
                                    mvprintw(7,5,"Pass: ");
                                    getstr(temppass); 
                                }
                                else
                                {
                                    clear();
                                    templog[1] = ' ';
                                    mvprintw(1,5,"LETS GETTING STARTED");
                                    mvprintw(5,5,"Login: ");
                                    getstr(templog);
                                    mvprintw(7,5,"Create pass: ");
                                    getstr(temppass);
                                    //atm.addAcc();
                                
                                    accm.addAcc(templog, temppass, 0.0);
                                }
                                ch='q';
                        }
                    }while(ch!='q');
                    clear();
                    ch=' ';
                    if(templog[1]!=' '){auth=1;}
                    else{auth=0;};
                }
                ch=' ';
                break;
               
        }            
   }while(ch!='q');
   
   endwin(); 
    
};

//int main()
//{
//    initscr();
//    curs_set(0);
//    keypad(stdscr, 1);
//
//    StartMenu();
//
//    endwin();
//    return 0;
//};
