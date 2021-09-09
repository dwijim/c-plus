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
   
   // menyembunyikan tampilan kursor
   curs_set(1);
kolom = 25;
  
    // menampilkan tulisan
    mvprintw(5,kolom,"Kemampuan Dasar Komputer");
    mvprintw(6,kolom,"*** Melakukan Perulangan ***");
    
    
    mvprintw(8,kolom,"Masukkan banyaknya perulangan: ");
    scanw("%d",&bilangan1);
 
    for (bilangan2=10;bilangan2<=bilangan1;bilangan2++)
     {
    mvprintw(bilangan2,25,"Ilkom Unila");


     }    
    
    getch();
    

  // menutup layar mode ncurses
   endwin();  

   // kembali ke program utama
   return 0;
}
