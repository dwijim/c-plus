/* -------------------------------
   contoh format dasar program C++
   dengan menggunakan pustaka ncurses
   nama file: formatdasar.cpp
   dicompile dengan perintah:
   g++ formatdasar.cpp -o format -l ncurses
   
   program ini ditulis di cocalc.com
   pada tanggal 12 september 2021

   ------------------------------- */

// ini karena menggunakan pustaka ncurses
#include "ncurses.h"

// input/output di dalam C++
#include "iostream"

// tidak disarankan menggunakan seperti ini
// supaya menyingkat penulisan
using namespace std;

#define baris 5

#define maksimal_banyak_data 100

int main(){
  
  int banyakbilangan,perulangan,bilangancari;
  
  
  int bilanganke[maksimal_banyak_data];
  
  //mengawali layar untuk ncurses
  initscr();
  
  // membersihkan layar
  clear();
  
  // menampilkan tulisan di layar pada posisi 5,10
  mvprintw(0,10,"Pencarian Bilangan");
  
  // memasukkan suatu nilai
  mvprintw(2,10,"Banyaknya bilangan: ");
  scanw("%d",&banyakbilangan);
  
  for (perulangan=0;perulangan<banyakbilangan;perulangan++)
  {
    mvprintw(baris+perulangan,5,"Masukkan bilangan ke-%d : ",perulangan+1);
    scanw("%d",&bilanganke[perulangan]);
    
  }
  
    mvprintw(baris+perulangan,5,"Masukkan bilangan yang akan dicari : ");
    scanw("%d",&bilangancari);

  // menahan tampilan layar
  getch();
  
  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 11;
}






