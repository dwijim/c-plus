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

/* ---------------------------------------------------------
   tampilan tulisan dipecah menjadi dua, yaitu setengah ke
   kiri dan setengah ke kanan
   oleh karena ini, dibuat variabel kiri untuk bagian kiri
   dan variabel kanan untuk bagian kanan
   --------------------------------------------------------- */
  
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
panjang_kalimat = kalimat01.length();

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
   
    kanan01 = kalimat01.substr(panjang_kalimat-1-huruf,huruf);
    kanan02 = kalimat02.substr(panjang_kalimat-1-huruf,huruf);
    kanan03 = kalimat03.substr(panjang_kalimat-1-huruf,huruf);
    kanan04 = kalimat04.substr(panjang_kalimat-1-huruf,huruf);
    kanan05 = kalimat05.substr(panjang_kalimat-1-huruf,huruf);
    kanan06 = kalimat06.substr(panjang_kalimat-1-huruf,huruf);
    kanan07 = kalimat07.substr(panjang_kalimat-1-huruf,huruf);
    kanan08 = kalimat08.substr(panjang_kalimat-1-huruf,huruf);
    kanan09 = kalimat09.substr(panjang_kalimat-1-huruf,huruf);
    kanan10 = kalimat10.substr(panjang_kalimat-1-huruf,huruf);
    kanan11 = kalimat11.substr(panjang_kalimat-1-huruf,huruf);

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
   
    kanan01 = kalimat01.substr(perulangan+penambah,huruf);
    kanan02 = kalimat02.substr(perulangan+penambah,huruf);
    kanan03 = kalimat03.substr(perulangan+penambah,huruf);
    kanan04 = kalimat05.substr(perulangan+penambah,huruf);
    kanan05 = kalimat05.substr(perulangan+penambah,huruf);
    kanan06 = kalimat06.substr(perulangan+penambah,huruf);
    kanan07 = kalimat07.substr(perulangan+penambah,huruf);
    kanan08 = kalimat08.substr(perulangan+penambah,huruf);
    kanan09 = kalimat09.substr(perulangan+penambah,huruf);
    kanan10 = kalimat10.substr(perulangan+penambah,huruf);
    kanan11 = kalimat11.substr(perulangan+penambah,huruf);

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
