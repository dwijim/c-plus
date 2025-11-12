/* ---------------------------------------------
 * program untuk mendeteksi tombol yang ditekan
 * kemudian menggeser tulisan ke kiri atau ke kanan
 * sesuai dengan tombol panah yang ditekan
 * dibuat oleh dwi sakethi:
 * 12 november 2025
 * 
 * 
 * file ini disimpan dengan nama kerangka-tombol-0.cpp
 * compile g++ kerangka-tombol-0.cpp -o tombol -l ncurses
 *  
 * --------------------------------------------- */

// karena ada fungsi-fungsi yang berasal dari lib ncurses 
#include "ncurses.h"

// supaya penulisan program menjadi lebih ringkas
using namespace std;

// kolom tengah layar
#define kolom_tengah 40

// posisi baris tengah
#define baris_tengah 20

// posisi baris tengah
#define KEY_ESC 27

// harus ada fungsi main()
int main(){

   // deklarasi variabel
   int tombol;
   short int baris, kolom;
   
  // menginisiasi layar untuk penggunaan ncurses
   initscr();


   // menyembunyikan tampilan kursor
   curs_set(0);

  // nodelay - enable or disable block during read
// nodelay(stdscr, TRUE);
   tombol = 0;

   baris = baris_tengah;
   kolom = kolom_tengah;
   mvprintw(baris,kolom," aku ");

   // membuat looping selama tidak menekan tombol ESC
     while (tombol != KEY_ESC) 
     {
        if ((tombol = getch()) == ERR) {
            /* user hasn't responded
             ...
            */
        }
       else 
         {
           if(tombol == KEY_LEFT)
             { 
               // bergerak ke kiri, jadi kolom berkurang
               kolom = kolom - 1;
               mvprintw(baris,kolom,  " aku ");
               mvprintw(baris,kolom+1,"     ");
             }
         }  
     }
   // menutup layar mode ncurses
   endwin();  
      // kembali ke program utama
   return 0;
}


nasi goreng sendok makan saya 

