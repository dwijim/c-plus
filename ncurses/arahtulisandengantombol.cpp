/* ---------------------------------------------
 * program untuk mendeteksi tombol yang ditekan
 * kemudian menggeser tulisan ke kiri atau ke kanan
 * sesuai dengan tombol panah yang ditekan
 * dibuat oleh dwi sakethi:
 * - 4 juli 2021
 * - 5 juli 2021
 * - 14 november 2021
 * 
 * file ini disimpan dengan nama tombol.cpp
 * compile g++ tombol.cpp -o tombol -l ncurses
 * 
 * file ini juga disimpan di github, tapi masih bingung
 * --------------------------------------------- */

#include "iostream"
#include "ncurses.h"
#include "string.h"

using namespace std;

// mendefinisikan tombol ESC nilai 27
#define KEY_ESC 27

// kolom tengah layar
#define kolom_tengah 40

// posisi baris bawah
#define baris_bawah 22

// harus ada fungsi main()
int main(){

   // deklarasi variabel
   int tombol;
   short int baris, kolom;
   
   // memberi posisi baris di bagian bawah
   baris = baris_bawah;

   // meletakkan posisi awal di tengah kolom layar
   kolom = kolom_tengah;

  // menginisiasi layar untuk penggunaan ncurses
   initscr();

   // supaya dapat dideteksi penekanan tombol khusus seperti
   // F1 .. F10, panah kanan, panah kiri dst ...
   keypad(stdscr,TRUE);

   // menyembunyikan tampilan kursor
   curs_set(0);

  // nodelay - enable or disable block during read
   nodelay(stdscr, TRUE);
   
   // tampilan awal di tengah layar
   mvprintw(baris,kolom," aku ");

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
                  // misal kalau menekan tombol enter
                  // ada sesuatu yang akan dilakukan
                  // dapat dituliskan di sini
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
