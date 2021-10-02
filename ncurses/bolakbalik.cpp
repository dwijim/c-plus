
/* -----------------------------------------
   program untuk mencetak tulisan yang 
   berjalan dari bawah layar ke atas layar
   per karakter
   dibuat oleh dwi sakethi
   menggunakan g++ compiler dan pustaka ncurses
   - 30 september 2021 di studio foto
   program ini diberi nama: bolakbalik.cpp
   
   di-compile dengan perintah:
   g++ bolakbalik.cpp -o tulisan -l ncurses

   dijalankan dengan perintah: tulisan

   ----------------------------------------- */

// karena ada proses cetak ke layar dan
// pemasukan data via keyboard
#include <iostream>

// menyertakan pustaka ncurses untuk tampilan layar
#include "ncurses.h"

// menggunakan fungsi-fungsi standar
#include<stdlib.h>

// menggunakan fungsi-fungsi string
#include<string>

// menggunakan fungsi-fungsi standar
//#include<unistd.h>

// untuk mempermudah penulisan program
using namespace std;


// fungsi utama di dalam bahasa C++
int main ()
{
  
// mendefinisikan kalimat string 60 karakter
// diberi spasi fungsinya untuk menghapus	
string kalimat=" dwi sakethi ";

// kiri untuk tulisan sebelah kiri
string kiri=" ";

// kanan untuk tulisan sebelah kanan
string kanan=" ";

// char potongan;

// mendefinisikan variabel baris
short int baris;

// mendefinisikan posisi huruf
short int huruf;

// mendefinisikan posisi kolom
short int kolom;

// mendefinisikan panjang tulisan
short int panjang_kalimat;

// mendefinisikan variabel untuk looping
short int perulangan;

// mengawali mode ncurses
initscr();

//clears the screen
clear();

//menghilangkan kursor
//initcursor(0);

// menghitung panjang kalimat
panjang_kalimat = kalimat.length();

// dibagi dua karena ada potongan kanan dan kiri
perulangan = panjang_kalimat/2;

baris = 12;

// looping dari huruf pertama-huruf terakhir
for (huruf=0;huruf<panjang_kalimat;huruf++)
{
    // menentukan posisi kolom
    kolom=40-huruf;

    // dari baris paling bawah (23) ke baris atas (3)
    // potongan=substr(kalimat,huruf-1,1);

    /* ------------------------------------------
    * pada posisi baris sebelumnya yang makin berkurang
    * (baris+1)dan kolom tetap, cetak spasi
    * ini gunanya untuk menghapus
    *------------------------------------------- */  
    
    //kiri = kiri + kalimat[huruf];
    kiri = kalimat.substr(0,huruf+1);
   
    kanan = kanan+kalimat[panjang_kalimat+1-huruf];

   /* ------------------------------------------
    * pada posisi sekarang (baris), 
    * cetak karakter saat ini
    *------------------------------------------- */  
    mvprintw(baris,kolom,"%s%s",kiri,kanan);
    mvprintw(20,1,"kiri: %s",kiri);
    mvprintw(21,1,"%s",kanan);

    // menghentikan proses sampai ditekan suatu tombol
    getch();
}

// menutup mode ncurses
endwin();

// akhir program mengembalikan suatu nilai
return 0;

}
