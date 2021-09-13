/* -------------------------------
   contoh program C++
   dengan menggunakan pustaka ncurses
   nama file: luassegitiga.cpp
   dicompile dengan perintah:
   g++ luassegitiga.cpp -o luas -l ncurses
   
   program ini ditulis di cocalc.com
   pada tanggal 13 september 2021

   ------------------------------- */

// ini karena menggunakan pustaka ncurses
#include "ncurses.h"

// input/output di dalam C++
#include "iostream"

// tidak disarankan menggunakan seperti ini
// supaya menyingkat penulisan
using namespace std;


int main(){
  
  float luas,alas,tinggi;
  
  //mengawali layar untuk ncurses
  initscr();
  
  // membersihkan layar
  clear();
  
  // menampilkan tulisan di layar pada posisi 5,10
  mvprintw(5,10,"Menghitung Luas");
  
  // memasukkan nilai alas dalam format pecahan
  // misal 7.0
  mvprintw(7,10,"Masukan alas: ");
  scanw("%f",&alas);

  // memasukkan nilai tinggi dalam format pecahan
  // misal 2.0
  mvprintw(8,10,"Masukan tinggi: ");
  scanw("%f",&tinggi);
  
  // menghitung luas segi tiga
  luas = (alas*tinggi)/2;
  
  // menampilkan nilai luas
  // karena tipe pecahan, jadi pakai %f
  mvprintw(9,10,"Luas : %f",luas);
  
  // menahan tampilan layar
  getch();
  
  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 11;
}
