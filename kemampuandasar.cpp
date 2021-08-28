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


// kolom tengah layar
#define kolom_tengah 14

// posisi baris bawah
#define baris_bawah 2


int MenjumlahBilangan(int barisnya, int kolomnya)
{
    int bilangan1,bilangan2,jumlah;
    
    // menghapus layar
    clear();
    
    // menampilkan tulisan
    mvprintw(barisnya+0,kolomnya,"Kemampuan Dasar Komputer");
    mvprintw(barisnya+2,kolomnya,"1. Menjumlahkan bilangan");
    
    
    mvprintw(barisnya+4,kolomnya,"Masukkan bilangan #1: ");
    scanw("%d",&bilangan1);
 
    mvprintw(barisnya+5,kolomnya,"Masukkan bilangan #2: ");
    scanw("%d",&bilangan2);
 
    jumlah = bilangan1+bilangan2;
    mvprintw(barisnya+6,kolomnya,"Jumlah: %d",jumlah);
    
    getch();
    
    return 0;
}
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

   pilihan = 1;
   
  // nodelay - enable or disable block during read
  // nodelay(stdscr, TRUE);
   
   // tampilan awal di tengah layar
     while (pilihan != 0) {
  // menginisiasi layar untuk penggunaan ncurses
   initscr();
   kolom = kolom_tengah;

                clear();
                mvprintw(baris+0,kolom,"Kemampuan Dasar Komputer");
                mvprintw(baris+2,kolom,"1. Menjumlahkan bilangan");
                mvprintw(baris+3,kolom,"2. Mengalikan bilangan");
                mvprintw(baris+4,kolom,"3. Membandingkan bilangan");
                mvprintw(baris+5,kolom,"4. Melakukan perulangan");
                mvprintw(baris+7,kolom,"5. Bilangan prima");
                mvprintw(baris+8,kolom,"0. Selesai");
                mvprintw(baris+9,kolom,"Pilihan Anda: ");

                scanw("%d",&pilihan);
                refresh();
                
                switch (pilihan) {
                    
                    case 1 : MenjumlahBilangan(baris,kolom);
                             break;
                    
                }
                    
                    
     }

   // menutup layar mode ncurses
   endwin();  

   // kembali ke program utama
   return 0;
}
