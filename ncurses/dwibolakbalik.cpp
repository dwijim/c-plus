
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
 string kalimat01="     #                  #               ";
 string kalimat02="     #                                  ";
 string kalimat03="     #             #    #  #            ";
 string kalimat04="     #                  #               ";
 string kalimat05="  #### #        #  #    #  #   #######  ";
 string kalimat06=" #   #  #      #   #    #  #   #  #  #  ";
 string kalimat07=" #   #   #    #    #    #  #   #  #  #  ";
 string kalimat08=" #   #    ####     #    #  #   #  #  #  ";
 string kalimat09="  ###      # #    ### ##  ### ###   ### ";
 string kalimat10="    dwijim - www.dwijim.wordpress.com   ";
 string kalimat11="      pengrajin teknologi informasi     ";
//char kalimat[]=" dwi sakethi ";

// kiri untuk tulisan sebelah kiri
string kiri01=" ";
string kiri02=" ";
string kiri03=" ";
string kiri04=" ";
string kiri05=" ";
string kiri06=" ";
string kiri07=" ";
string kiri08=" ";
string kiri09=" ";
string kiri10=" ";
string kiri11=" ";
//char kiri[]=" ";

// kanan untuk tulisan sebelah kanan
string kanan01=" ";
string kanan02=" ";
string kanan03=" ";
string kanan04=" ";
string kanan05=" ";
string kanan06=" ";
string kanan07=" ";
string kanan08=" ";
string kanan09=" ";
string kanan10=" ";
string kanan11=" ";
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
panjang_kalimat = kalimat01.length();
//panjang_kalimat = strlen(kalimat);

// dibagi dua karena ada potongan kanan dan kiri
perulangan = (panjang_kalimat/2);

baris = 5; 

// ini bagian tulisan yang bergerak ke luar
// looping dari huruf pertama sampai setengah tulisan
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
    
    kiri01 = kiri01 + kalimat01[huruf];
    kiri02 = kiri02 + kalimat02[huruf];
    kiri03 = kiri03 + kalimat03[huruf];
    kiri04 = kiri04 + kalimat04[huruf];
    kiri05 = kiri05 + kalimat05[huruf];
    kiri06 = kiri06 + kalimat06[huruf];
    kiri07 = kiri07 + kalimat07[huruf];
    kiri08 = kiri08 + kalimat08[huruf];
    kiri09 = kiri09 + kalimat09[huruf];
    kiri10 = kiri10 + kalimat10[huruf];
    kiri11 = kiri11 + kalimat11[huruf];
    //kiri = kalimat.substr(0,huruf+1);
    //strcat(kiri,kalimat[huruf]);
   
    kanan01 = kalimat01[panjang_kalimat-1-huruf]+kanan01;
    kanan02 = kalimat02[panjang_kalimat-1-huruf]+kanan02;
    kanan03 = kalimat03[panjang_kalimat-1-huruf]+kanan03;
    kanan04 = kalimat04[panjang_kalimat-1-huruf]+kanan04;
    kanan05 = kalimat05[panjang_kalimat-1-huruf]+kanan05;
    kanan06 = kalimat06[panjang_kalimat-1-huruf]+kanan06;
    kanan07 = kalimat07[panjang_kalimat-1-huruf]+kanan07;
    kanan08 = kalimat08[panjang_kalimat-1-huruf]+kanan08;
    kanan09 = kalimat09[panjang_kalimat-1-huruf]+kanan09;
    kanan10 = kalimat10[panjang_kalimat-1-huruf]+kanan10;
    kanan11 = kalimat11[panjang_kalimat-1-huruf]+kanan11;

   /* ------------------------------------------
    * pada posisi sekarang (baris), 
    * cetak karakter saat ini
    *------------------------------------------- */  
    mvprintw(baris+1,kolom,"%s%s",kiri01.c_str(),kanan01.c_str());
    mvprintw(baris+2,kolom,"%s%s",kiri02.c_str(),kanan02.c_str());
    mvprintw(baris+3,kolom,"%s%s",kiri03.c_str(),kanan03.c_str());
    mvprintw(baris+4,kolom,"%s%s",kiri04.c_str(),kanan04.c_str());
    mvprintw(baris+5,kolom,"%s%s",kiri05.c_str(),kanan05.c_str());
    mvprintw(baris+6,kolom,"%s%s",kiri06.c_str(),kanan06.c_str());
    mvprintw(baris+7,kolom,"%s%s",kiri07.c_str(),kanan07.c_str());
    mvprintw(baris+8,kolom,"%s%s",kiri08.c_str(),kanan08.c_str());
    mvprintw(baris+9,kolom,"%s%s",kiri09.c_str(),kanan09.c_str());
    mvprintw(baris+10,kolom,"%s%s",kiri10.c_str(),kanan10.c_str());
    mvprintw(baris+11,kolom,"%s%s",kiri11.c_str(),kanan11.c_str());
    //mvprintw(20,1,"kiri: %s",kiri.c_str());
    //mvprintw(21,1,"kanan: %s",kanan.c_str());

    // menghentikan proses selama 1 detik
    refresh(); sleep(1);  
}

// ini bagian tulisan yang bergerak ke dalam 
// looping dari setengah tulisan sampai dengan satu
for (huruf=perulangan;huruf>1;huruf--)
{
    // menentukan posisi kolom

    // dari baris paling bawah (23) ke baris atas (3)
    // potongan=substr(kalimat,huruf-1,1);

    /* ------------------------------------------
    * pada posisi baris sebelumnya yang makin berkurang
    * (baris+1)dan kolom tetap, cetak spasi
    * ini gunanya untuk menghapus
    *------------------------------------------- */  
    
    kiri01 = kalimat01.substr(0,huruf);
    kiri02 = kalimat02.substr(0,huruf);
    kiri03 = kalimat03.substr(0,huruf);
    kiri04 = kalimat04.substr(0,huruf);
    kiri05 = kalimat05.substr(0,huruf);
    kiri06 = kalimat06.substr(0,huruf);
    kiri07 = kalimat07.substr(0,huruf);
    kiri08 = kalimat08.substr(0,huruf);
    kiri09 = kalimat09.substr(0,huruf);
    kiri10 = kalimat10.substr(0,huruf);
    kiri11 = kalimat11.substr(0,huruf);
    //kiri = kalimat.substr(0,huruf+1);
    //strcat(kiri,kalimat[huruf]);
   
    kanan01 = kalimat01.substr(perulangan+,huruf);
    kanan02 = kalimat02[panjang_kalimat-1-huruf]+kanan02;
    kanan03 = kalimat03[panjang_kalimat-1-huruf]+kanan03;
    kanan04 = kalimat04[panjang_kalimat-1-huruf]+kanan04;
    kanan05 = kalimat05[panjang_kalimat-1-huruf]+kanan05;
    kanan06 = kalimat06[panjang_kalimat-1-huruf]+kanan06;
    kanan07 = kalimat07[panjang_kalimat-1-huruf]+kanan07;
    kanan08 = kalimat08[panjang_kalimat-1-huruf]+kanan08;
    kanan09 = kalimat09[panjang_kalimat-1-huruf]+kanan09;
    kanan10 = kalimat10[panjang_kalimat-1-huruf]+kanan10;
    kanan11 = kalimat11[panjang_kalimat-1-huruf]+kanan11;

   /* ------------------------------------------
    * pada posisi sekarang (baris), 
    * cetak karakter saat ini
    *------------------------------------------- */  
    mvprintw(baris+1,kolom,"%s%s",kiri01.c_str(),kanan01.c_str());
    mvprintw(baris+2,kolom,"%s%s",kiri02.c_str(),kanan02.c_str());
    mvprintw(baris+3,kolom,"%s%s",kiri03.c_str(),kanan03.c_str());
    mvprintw(baris+4,kolom,"%s%s",kiri04.c_str(),kanan04.c_str());
    mvprintw(baris+5,kolom,"%s%s",kiri05.c_str(),kanan05.c_str());
    mvprintw(baris+6,kolom,"%s%s",kiri06.c_str(),kanan06.c_str());
    mvprintw(baris+7,kolom,"%s%s",kiri07.c_str(),kanan07.c_str());
    mvprintw(baris+8,kolom,"%s%s",kiri08.c_str(),kanan08.c_str());
    mvprintw(baris+9,kolom,"%s%s",kiri09.c_str(),kanan09.c_str());
    mvprintw(baris+10,kolom,"%s%s",kiri10.c_str(),kanan10.c_str());
    mvprintw(baris+11,kolom,"%s%s",kiri11.c_str(),kanan11.c_str());
    //mvprintw(20,1,"kiri: %s",kiri.c_str());
    //mvprintw(21,1,"kanan: %s",kanan.c_str());

    // menghentikan proses selama 1 detik
    refresh(); sleep(1);  
}

// looping dari huruf pertama-huruf terakhir
for (huruf=perulangan;huruf=1;huruf--)
{

}    refresh(); sleep(5);  
// menutup mode ncurses
endwin();

// akhir program mengembalikan suatu nilai
return 0;

}
