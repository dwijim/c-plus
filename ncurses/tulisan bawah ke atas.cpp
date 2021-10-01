
/* -----------------------------------------
   program untuk mencetak tulisan yang 
   berjalan dari bawah layar ke atas layar
   per karakter
   dibuat oleh dwi sakethi
   menggunakan g++ compiler dan pustaka ncurses
   - 30 september 2021 di studio foto
   program ini diberi nama: tulsan ke atas.cpp
   
   di-compile dengan perintah:
   g++ tulisan ke atas.cpp -o tulisan -l ncurses

   dijalankan dengan perintah: tulisan

   ----------------------------------------- */

// karena ada proses cetak ke layar dan
// pemasukan data via keyboard
#include <iostream>

// menyertakan pustaka ncurses untuk tampilan layar
#include "ncurses.h"

// menggunakan fungsi-fungsi standar
#include<stdlib.h>

// menggunakan fungsi-fungsi standar
#include<string.h>

// menggunakan fungsi-fungsi standar
//#include<unistd.h>

// untuk mempermudah penulisan program
using namespace std;


// fungsi utama di dalam bahasa C++
int main ()
{
  
// mendefinisikan kalimat string 60 karakter	
char kalimat[60]="dwi sakethi";

// char potongan;

// mendefinisikan variabel baris
short int baris;

// mendefinisikan posisi huruf
short int huruf;

// mendefinisikan posisi huruf
short int kolom;

// mendefinisikan posisi huruf
short int panjang_kalimat;

// mengawali mode ncurses
initscr();

//clears the screen
clear();

//initcursor(0);

// menghitung panjang kalimat
// karena proses dilakukan dari huruf pertama
// sampai dengan huruf terakhir
panjang_kalimat = strlen(kalimat);

// looping dari huruf pertama-huruf terakhir
for (huruf=0;huruf<panjang_kalimat;huruf++)
{
    // menentukan posisi kolom
    kolom=15+huruf;
    
    // dari baris paling bawah (23) ke baris atas (3)
    // potongan=substr(kalimat,huruf-1,1);  
 for (baris=23;baris>=3;baris--)
 {
 
   /* ------------------------------------------
    * pada posisi baris sebelumnya yang makin berkurang
    * (baris+1)dan kolom tetap, cetak spasi
    * ini gunanya untuk menghapus
    *------------------------------------------- */  
    mvprintw(baris+1,kolom," ");
    
   /* ------------------------------------------
    * pada posisi sekarang (baris), 
    * cetak karakter saat ini
    *------------------------------------------- */  
    mvprintw(baris,kolom,"%c",kalimat[huruf]);

    // menghentikan proses sampai ditekan suatu tombol
    getch();
  	
 }

}

// menutup mode ncurses
endwin();

// akhir program mengembalikan suatu nilai
return 0;

}
