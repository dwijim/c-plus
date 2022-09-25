
#include "ncurses.h"


int main()
{
  int bilangan;

  int proses_ke,sisa;
int tanda_prima;

  initscr();

  mvprintw(5,15,"Masukkan suatu bilangan: ");
  scanw("%d",&bilangan);	
 
  tanda_prima = 1;

  for (proses_ke=2;proses_ke<bilangan;proses_ke++)
  {

     sisa = bilangan % proses_ke;
     mvprintw(5+proses_ke,15,"%d - %d",proses_ke,sisa);
     if (sisa==0) 
     { 
	     tanda_prima = 0;
	break;
  }
     //getch();
  }

  if (tanda_prima==0)
  {
	  mvprintw(20,1,"Bukan bilangan prima            ");
 
  }
  else 
  {
	  mvprintw(20,1,"Bilangan prima             ");
  }
  getch();
  endwin();

  return 46;
}

