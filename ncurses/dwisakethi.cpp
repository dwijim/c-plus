
/* -----------------------------------------
   program untuk mencetak tulisan yang 
   berjalan dari bawah layar ke atas layar
   per karakter
   dibuat oleh dwi sakethi
   menggunakan g++ compiler dan pustaka ncurses
   - 30 september 2021 di studio foto
   - 2 oktober 2021 alhamdulillah jadi juga
   
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

// menggunakan fungsi-fungsi string
#include<cstring>

// menggunakan fungsi untuk delay
#include<unistd.h>

#include <chrono>
#include <thread>

// untuk mempermudah penulisan program
using namespace std;


// fungsi utama di dalam bahasa C++
int main ()
{
  
// mendefinisikan kalimat string 60 karakter
// diberi spasi fungsinya untuk menghapus	
 string kalimat01="  wi sakethi ilmu komputer unila ";
 string kalimat02="  wi sakethi ilmu komputer unila ";
 string kalimat03="  wi sakethi ilmu komputer unila ";
 string kalimat04="  wi sakethi ilmu komputer unila ";
 string kalimat05=" dwi sakethi ilmu komputer unila ";
 string kalimat06=" dwi sakethi ilmu komputer unila ";
 string kalimat07=" dwi sakethi ilmu komputer unila ";
 string kalimat08=" dwi sakethi ilmu komputer unila ";
 string kalimat09=" dwi sakethi ilmu komputer unila ";
//char kalimat[]=" dwi sakethi ";

// kiri untuk tulisan sebelah kiri
string kiri=" ";
//char kiri[]=" ";

// kanan untuk tulisan sebelah kanan
string kanan=" ";
//char kanan[]=" ";

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

  long int berhenti;
  
// mengawali mode ncurses
initscr();

//clears the screen
clear();

//menghilangkan kursor
//initcursor(0);

// menghitung panjang kalimat
panjang_kalimat = kalimat.length();
//panjang_kalimat = strlen(kalimat);

// dibagi dua karena ada potongan kanan dan kiri
perulangan = (panjang_kalimat/2)+1;

baris = 12; 

// looping dari huruf pertama-huruf terakhir
for (huruf=0;huruf<perulangan;huruf++)
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
    
    kiri = kiri + kalimat[huruf];
    //kiri += kalimat[huruf];
    //kiri = kalimat.substr(0,huruf+1);
    //strcat(kiri,kalimat[huruf]);
   
    kanan = kalimat[panjang_kalimat-1-huruf]+kanan;

   /* ------------------------------------------
    * pada posisi sekarang (baris), 
    * cetak karakter saat ini
    *------------------------------------------- */  
    mvprintw(baris,kolom,"%s%s",kiri.c_str(),kanan.c_str());
    mvprintw(20,1,"kiri: %s",kiri.c_str());
    mvprintw(21,1,"kanan: %s",kanan.c_str());

    // menghentikan proses selama 1 detik
    refresh(); sleep(1);  
}

    refresh(); sleep(5);  
// menutup mode ncurses
endwin();

// akhir program mengembalikan suatu nilai
return 0;

}
