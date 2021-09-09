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




// harus ada fungsi main()
int main(){

   // deklarasi variabel
   int tombol;
   short int baris, kolom, pilihan;
   
   // memberi posisi baris di bagian bawah
   baris = baris_bawah;

   // meletakkan posisi awal di tengah kolom layar
   kolom = kolom_tengah;

   // menyembunyikan tampilan kursor
   curs_set(1);

    // menampilkan tulisan
    mvprintw(barisnya+0,kolomnya,"Kemampuan Dasar Komputer");
    mvprintw(barisnya+2,kolomnya,"4. Melakukan Perulangan");
    
    
    mvprintw(barisnya+4,kolomnya,"Masukkan banyaknya perulangan: ");
    scanw("%d",&bilangan1);
 
    for (bilangan2=1;bilangan2<=bilangan1;bilangan2++)
     {
    mvprintw(barisnya+6+bilangan2,kolomnya,"Ilkom Unila \n");


     }    
    
    getch();
    

  // menutup layar mode ncurses
   endwin();  

   // kembali ke program utama
   return 0;
}
