/* ---------------------------------------------
 * program untuk mendeteksi tombol yang ditekan
 * kemudian menggeser tulisan ke kiri atau ke kanan
 * sesuai dengan tombol panah yang ditekan
 * dibuat oleh dwi sakethi:
 * - 4 juli 2021
 * - 5 juli 2021
 * 
 * 
 * file ini disimpan dengan nama tombol.cpp
 * compile g++ tombol.cpp - tombol -l ncurses
 * --------------------------------------------- */

#include "iostream"
#include "ncurses.h"
#include "string.h"

using namespace std;

#define KEY_ESC 27

// harus ada fungsi main()
int main(){

   // deklarasi variabel
   int tombol;
   short int baris, kolom;
   
   // memberi posisi baris di bagian bawah
   baris = 22;

   // meletakkan posisi awal di tengah kolom layar
   kolom = 40;

  // menginisiasi layar untuk penggunaan ncurses
   initscr();

   // supaya dapat dideteksi penekanan tombol khusus seperti
   // F1 .. F10, panah kanan, panah kiri dst ...
   keypad(stdscr,TRUE);

   // menyembunyikan tampilan kursor
   curs_set(0);

   nodelay(stdscr, TRUE);

   // membuat looping selama tidak menekan tombol ESC
     while (tombol != KEY_ESC) {
          if ((tombol = getch()) == ERR) {
              /* user hasn't responded
               ...
              */
          }
          else {
              /* user has pressed a key ch
               ...
              */ 
             if(tombol == KEY_ENTER)
                { 
                  // bergerak ke kiri, jadi kolom berkurang
                  //beep(230,100);
                  ///beep();
                  cout << "\a";
                  char ascii = 7;
                  cout << ascii;
                  mvprintw(baris,kolom,"\a");
                  // Sleep(500);
                }  
             else if(tombol == KEY_LEFT)
                { 
                  // bergerak ke kiri, jadi kolom berkurang
                  kolom = kolom - 1;

                  // jika sudah mentok ke kiri, kolom tetap 1
                  if (kolom==1) kolom=1;
                }  
             else if(tombol == KEY_RIGHT)
                { 
                  // bergerak ke kanan, jadi kolom bertambah
                  kolom = kolom + 1;

                  // jika sudah mentok ke kanan, kolom tetap 75
                  if (kolom==75) kolom=75;
                }  

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
