/* -------------------------------
   contoh format dasar program C++
   dengan menggunakan pustaka ncurses
   nama file: formatdasar.cpp
   dicompile dengan perintah:
   g++ sensorkata.cpp -o tes -l ncurses
   
   program ini ditulis di cocalc.com
   pada tanggal : 12 september 2021
                   7 oktober 2021

   pada awalnya sulit mengolah data		   
   berupa string di c++

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


// program dalam bahasa C minimal harus
// terdiri dari satu fungsi yaitu
// fungsi main()
int main(){
  
  // deklarasi variabel	
  int bilangan;
  
  short int hasil_pembandingan;
  
  string kata[banyaknya_kata];
  string kata_apa;
 
  // menentukan kamus kata jorok 
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

     // jika pembandingan bernilai 0 artinya
     // kedua kata sama
      if (hasil_pembandingan == 0)
     {

       init_pair(1,COLOR_RED,COLOR_WHITE);
       //start_color();
       //attron(COLOR_PAIR(1));       
       mvprintw(20,10,"Kata Anda kena sensor ...");
       //addstr("Kata Anda kena sensor ...");
       //attroff(COLOR_PAIR(1));       

       // jika kena sensor, looping tidak perlu dilanjutkan
       break;
     }
}
     mvprintw(bilangan,3,"Selesai");
  // menahan tampilan layar
  getch();
  clear();
  
  
  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 46;
}
