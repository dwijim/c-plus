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

#define pojok (43)
//#     pojok  "+"

int main(){
  
  int bilangan;
  
  //mengawali layar untuk ncurses
  initscr();
  
  // membersihkan layar
  clear();
  
  // menampilkan tulisan di layar pada posisi 5,10
  mvprintw(5,10,"Jurusan Ilmu Komputer");
  
  // memasukkan suatu nilai
  mvprintw(7,10,"Membuat kotak");
  mvprintw(9,10,"Kiri atas %d %c ...",pojok,pojok);
  
  // menahan tampilan layar
  getch();
  
  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 11;
}







