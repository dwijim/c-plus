/* ---------------------------------------------
 * program untuk menunjukkan kemampuan dasar
 * dari komputer melakukan perulangan
 * dibuat oleh dwi sakethi:
 * - 9 september 2021
 * 
 * 
 * file ini disimpan dengan nama loopingcetak.cpp
 * compile g++ loopingcetak.cpp -o cetak -l ncurses
 * 
 * dijalankan dengan perintah: ./cetak
 * --------------------------------------------- */

// karena menggunakan library ncurses
#include "ncurses.h"

// karena ada fungsi input dan output
#include <iostream>

// untuk menyingkat penulisan tapi sebenarnya ...
using namespace std;

// program dalam bahasa C++ harus ada fungsi main()
int main()
{
 
   // deklarasi variabel
   short int baris, kolom;
   short int bilangan2, bilangan1;
   
   // mengawali layar untuk mode ncurses
  initscr();
  
   // menampilkan tampilan kursor
   curs_set(1);

   // menentukan posisi kolom
   kolom = 25;
  
    // menampilkan tulisan
    mvprintw(5,kolom,"Kemampuan Dasar Komputer");
    mvprintw(6,kolom,"*** Melakukan Perulangan ***");
    
    // menampilkan tulisa
    mvprintw(8,kolom,"Masukkan banyaknya perulangan: ");

    // memasukkan bilangan dengan tipe integer
    scanw("%d",&bilangan1);
 
    // looping dari 1 sampai ke nilai bilangan
    for (bilangan2=1;bilangan2<=bilangan1;bilangan2++)
     {
        // mencetak pada baris yang bertambah
        // supaya tulisan tambah ke bawah
        mvprintw(bilangan2+10,25,"Ilkom Unila");
 
     }    
    
    // menahan tampilan di layar, supaya dapat dilihat dulu
    getch();
    

  // menutup layar mode ncurses
   endwin();  

   // kembali ke program utama
   return 0;
}
