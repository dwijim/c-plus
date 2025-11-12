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

#include "iostream"
#include "ncurses.h"
#include "string.h"

using namespace std;

// kolom tengah layar
#define kolom_tengah 40

// posisi baris bawah
#define baris_bawah 22

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

   baris = 10;
   kolom = 40;
   mvprintw(baris,kolom," aku ");
   // membuat looping selama tidak menekan tombol ESC
     while (tombol != 27) 
     {
        if ((tombol = getch()) == ERR) {
            /* user hasn't responded
             ...
            */
        }
        else {
              // cetak sesuatu sesuai dengan baris dan kolom
                // di kanan dan kiri diberi spasi
                // untuk menghapus
                mvprintw(baris,kolom," aku ");
               
     }
    }
   // menutup layar mode ncurses
   endwin();  
      // kembali ke program utama
   return 0;
}