#define jumlah_data 5

// karena ada proses cetak ke layar dan
// pemasukan data via keyboard
#include <iostream>


using namespace std;

int main()
{
  float nilai_akhir[jumlah_data];
  
  int data_ke;
  
  for (data_ke=0;data_ke<jumlah_data;data_ke++)
   {
     cout << "Masukkan data ke-"<<data_ke+1;
   }

  return 1;
}

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


int main(){
  
  int bilangan;
  
  //mengawali layar untuk ncurses
  initscr();
  
  // membersihkan layar
  clear();
  
  // menampilkan tulisan di layar pada posisi 5,10
  mvprintw(5,10,"Jurusan Ilmu Komputer");
  
  // memasukkan suatu nilai
  mvprintw(7,10,"Masukan suatu bilangan: ");
  scanw("%d",&bilangan);
  
  // menahan tampilan layar
  getch();
  
  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 11;
}






