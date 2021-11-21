/* -----------------------------------------
   program untuk mencetak tulisan yang 
   bergerak keluar masuk 
   tulisan merupakan kumpulan karakter
   sehingga ukuran dapat dibuat menjadi besar
   
   dibuat oleh dwi sakethi
   menggunakan g++ compiler dan pustaka ncurses
   - 30 september 2021 di studio foto
   - 2 oktober 2021 alhamdulillah jadi juga
   - 20 november 2021 di bandung
   
   program ini diberi nama: dwibolakbalik.cpp
   
   di-compile dengan perintah:
   g++ dwibolakbalik.cpp -o tulisan -l ncurses

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

// untuk mempermudah penulisan program
using namespace std;


// fungsi utama di dalam bahasa C++
int main ()
{
  
// mendefinisikan kalimat string 60 karakter
// diberi spasi fungsinya untuk menghapus	
 string kalimat = " dwijim-www.dwijim.wordpress.com-pengrajin teknologi informasi  ";

/* ---------------------------------------------------------
   tampilan tulisan dipecah menjadi dua, yaitu setengah ke
   kiri dan setengah ke kanan
   oleh karena ini, dibuat variabel kiri untuk bagian kiri
   dan variabel kanan untuk bagian kanan
   --------------------------------------------------------- */
  
// kiri untuk tulisan sebelah kiri
string kiri=" ";

// kanan untuk tulisan sebelah kanan
string kanan=" ";

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

// variabel untuk penambah posisi
  short int penambah;
    
// mengawali mode ncurses
initscr();

//clears the screen
clear();

//menghilangkan kursor
//initcursor(0);

// menghitung panjang kalimat
panjang_kalimat = kalimat.length();

// dibagi dua karena ada potongan kanan dan kiri
perulangan = (panjang_kalimat/2);

// tampilan dimulai dari baris ke 5 sampai bawah
baris = 5; 

// ini bagian tulisan yang bergerak ke luar
// looping dari huruf pertama sampai setengah tulisan
for (huruf=0;huruf<perulangan;huruf++)
{
    // menentukan posisi kolom
    kolom=40-huruf;

    /* ------------------------------------------
    * pada posisi baris sebelumnya yang makin berkurang
    * (baris+1)dan kolom tetap, cetak spasi
    * ini gunanya untuk menghapus
    *------------------------------------------- */  
    
    kiri = kalimat.substr(0,huruf);
   
    kanan = kalimat.substr(panjang_kalimat-1-huruf,huruf);

   /* ------------------------------------------
    * pada posisi sekarang (baris), 
    * cetak karakter saat ini
    *------------------------------------------- */  
    mvprintw(baris,kolom,"%s%s",kiri.c_str(),kanan.c_str());

    // menghentikan proses selama 1 detik
    refresh(); sleep(1);  
}

penambah = 0;
  
// ini bagian tulisan yang bergerak ke dalam 
// looping dari setengah tulisan sampai dengan satu
for (huruf=perulangan;huruf>1;huruf--)
{
    /* ------------------------------------------
    * pada posisi baris sebelumnya yang makin berkurang
    * (baris+1)dan kolom tetap, cetak spasi
    * ini gunanya untuk menghapus
    *------------------------------------------- */  

    /* ------------------------------------------
    * mengambil string dari posisi awal sampai dengan
    * setengah tulisan
    * kalau tulisan aslinya adalah 'dwi sakethi'
    * maka hasilnya adalah : dwi sa
    *                         dwi s
    *                          dwi 
    *                           dwi ... dst
    *------------------------------------------- */  

    kiri = kalimat.substr(0,huruf);
   
    kanan = kalimat.substr(perulangan+penambah,huruf);

   /* ------------------------------------------
    * pada posisi sekarang (baris), 
    * cetak karakter saat ini 
    *------------------------------------------- */  
    mvprintw(baris,kolom,"%s%s",kiri.c_str(),kanan.c_str());

    // variabel untuk menggeser posisi ke kanan
    penambah = penambah + 1;
  
    // posisi kolom makin geser ke kanan
    kolom = kolom + 1;
    
    // menghentikan proses selama 1 detik
    refresh(); sleep(1);  
}

// menutup mode ncurses
endwin();

// akhir program mengembalikan suatu nilai
return 0;

}
