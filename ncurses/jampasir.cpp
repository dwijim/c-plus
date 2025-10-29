#include "ncurses.h"

using namespace std;


int main()

{
    int proses,bentuk;
    initscr();
    proses = 1;
    while (1==1)
    {
   
         proses++;
         bentuk = proses % 5;
         if (bentuk==1)
            {
                mvprintw(12,38,"%s"," | ");
            }
         else   
         if (bentuk==2)
            {
                mvprintw(12,38,"%s"," / ");
            }
         else   
         if (bentuk==3)
            {
                mvprintw(12,38,"%s"," - ");
            }
         else   
         if (bentuk==4)
            {
                mvprintw(12,38,"%s"," \\ ");
            }
         else   
         if (bentuk==0)
            {
                mvprintw(12,38,"%s"," - ");
            }
     getch();
    }

    endwin();
    return 123;
}