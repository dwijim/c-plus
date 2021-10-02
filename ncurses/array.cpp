#define jumlah_data 5

// karena ada proses cetak ke layar dan
// pemasukan data via keyboard
#include <iostream>


using namespace std;

int main()
{

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

// program dalam bahasa C++ terdiri paling tidak atas satu fungsi
// yaitu fungsi main()
int main(){
  
  float nilai_akhir[jumlah_data];
  
  int data_ke;
  
  //mengawali layar untuk ncurses
  initscr();
  
  // membersihkan layar
  clear();
  
  for (data_ke=0;data_ke<jumlah_data;data_ke++)
   {
    // memasukkan suatu nilai
    mvprintw(7,10,"Masukan suatu bilangan: ");
    scanw("%d",&bilangan);
     cout << "Masukkan data ke-"<<data_ke+1;
   }
  
  
  // menahan tampilan layar
  getch();
  
  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 11;
}






