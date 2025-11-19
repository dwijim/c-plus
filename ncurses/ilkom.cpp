#include <ncurses.h>

int main()
{
  int baris;

  initscr();
  clear();

  for (baris=1;baris<=7;baris++)
    {
      mvprintw(9+baris,7,"%s","Ilkom Unila");  
    }

  for (baris=1;baris<=5;baris++)
    {
      mvprintw(9+baris,37,"%s","Ilkom Unila");  
    }

  getch();
  endwin();


}