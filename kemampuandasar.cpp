/* ---------------------------------------------
 * program untuk menunjukkan kemampuan dasar
 * dari komputer
 * dibuat oleh dwi sakethi:
 * - 27 agustus 2021
 * 
 * 
 * file ini disimpan dengan nama kemampuandasar.cpp
 * compile g++ kemampuandasar.cpp -o kemampuandasar -l ncurses
 * 
 * --------------------------------------------- */

#include "iostream"
#include "ncurses.h"
#include "string.h"

using namespace std;

// mendefinisikan pilihan ESC nilai 27
#define KEY_ESC 27

// kolom tengah layar
#define kolom_tengah 4

// posisi baris bawah
#define baris_bawah 2

// harus ada fungsi main()
int main(){

   // deklarasi variabel
   int pilihan;
   short int baris, kolom;
   
   // memberi posisi baris di bagian bawah
   baris = baris_bawah;

   // meletakkan posisi awal di tengah kolom layar
   kolom = kolom_tengah;

  // menginisiasi layar untuk penggunaan ncurses
   initscr();

   // supaya dapat dideteksi penekanan pilihan khusus seperti
   // F1 .. F10, panah kanan, panah kiri dst ...
   keypad(stdscr,TRUE);

   // menyembunyikan atau menampilan kursor
   curs_set(1);

  // nodelay - enable or disable block during read
   nodelay(stdscr, TRUE);
   
   // tampilan awal di tengah layar
   mvprintw(baris,kolom,"Kemampuan Dasar Komputer");

   pilihan = 1;
   // membuat looping selama tidak menekan pilihan ESC
         /*
     while (pilihan != 1) {
         
                // cetak sesuatu sesuai dengan baris dan kolom
                // di kanan dan kiri diberi spasi
                // untuk menghapus
                mvprintw(baris+2,kolom,"1. Menjumlahkan bilangan");
                mvprintw(baris+3,kolom,"2. Mengalikan bilangan");
                mvprintw(baris+4,kolom,"3. Membandingkan bilangan");
                mvprintw(baris+5,kolom,"4. Melakukan perulangan");
                cin >> pilihan;
     }
                */

   // menutup layar mode ncurses
    printw("Hello World !!!");
   getch();
   endwin();  

   // kembali ke program utama
   return 0;
}


/* ncurses1.c */
/*
 * 
#include <ncurses.h>
int main()
{
    initscr();
    printw("Hello World !!!");
    getch();
    endwin();
    return 0;
}
*/
