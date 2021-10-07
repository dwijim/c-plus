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

// menggunakan fungsi-fungsi standar
#include<stdlib.h>

// menggunakan fungsi-fungsi string
#include<string>

// menggunakan fungsi-fungsi string
#include<cstring>

// menggunakan fungsi untuk delay
#include<unistd.h>

#include <chrono>
#include <thread>

#define banyaknya_kata 5

// tidak disarankan menggunakan seperti ini
// supaya menyingkat penulisan
using namespace std;


int main(){
  
  int bilangan;
  
  short int hasil_pembandingan;
  
  string kata[banyaknya_kata];
  string kata_apa;
  
  kata[0]="ass";
  kata[1]="monyet";
  kata[2]="bodoh";
  kata[3]="gila";
  kata[4]="jorok";

  //mengawali layar untuk ncurses
  initscr();
  
  // membersihkan layar
  clear();
  
  // menampilkan tulisan di layar pada posisi 5,10
  mvprintw(5,10,"Jurusan Ilmu Komputer");
  
  // memasukkan suatu nilai
  mvprintw(7,10,"Masukan suatu kata: ");
  //scanw("%s",&kata_apa);
  kata_apa = "gila";
  //kata_apa = kata_apa+"\n";
  // membersihkan layar 
  clear();

  for (bilangan=0;bilangan<banyaknya_kata;bilangan++)
  {
     mvprintw(bilangan,3,"Tabel Kata : %s vs %s",kata[bilangan].c_str(),kata_apa.c_str());
     hasil_pembandingan = kata_apa.compare(kata[bilangan]);
      if (hasil_pembandingan == 0)
     {
       mvprintw(20,10,"Kata Anda kena sensor ...");
     }
/*
else
     {
      // mvprintw(20,10,"Kata Anda tidak kena sensor ...");
     }
      */
}
     mvprintw(bilangan,3,"Selesai");
  // menahan tampilan layar
  getch();
  clear();
  
  
  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 11;
}
