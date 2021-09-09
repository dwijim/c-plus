
/* -----------------------------------
 * program untuk mencari bilangan terbesar
 * dari sekumpulan bilangan
 * dibuat oleh dwi sakethi diedit oleh M.Fadhil Azhari
 * nama file bilangan-terbesar.cpp
   dimodifikasi sesuai dengan penggunaan ncurses
   9 september 2021

 * file ini disimpan dengan nama bilangan-terbesar.cpp
 * compile g++ bilangan-terbesar.cpp -o bilangan -l ncurses
 
  dijalankan dengan perintah: ./bilangan

 ------------------------------------------- */

// karena menggunakan library ncurses
#include "ncurses.h"

// karena ada fungsi input dan output
#include <iostream>

// untuk menyingkat penulisan tapi sebenarnya ...
using namespace std;

// program dalam bahasa C++ harus ada fungsi main()
int main()
{
    
// deklarasi variabel yang digunakan
int BanyakData, DataKe;
int bilangan;
int terbesar;

/* -----------------------------------------
 * bilangan terbesar diberi nilai awal
 * dengan bilangan sekecil-kecilnya
 * (tergantung asumsi data yang ada
   ----------------------------------------- */

// karena mencari bilanga terbesar maka
// terbesar diberi awal sekecil-kecilnya
terbesar = -999;

// menginisiasi layar untuk penggunaan ncurses
initscr();

// menanyakan banyaknya data
cout<<"Berapa banyaknya data: "; 
cin>>BanyakData;

// looping dari data pertama sampai terakhir
for (DataKe=1; DataKe<=BanyakData; DataKe++)
{
   // memasukkan datanya 
   cout<<"Sebutkan data ke- "<<DataKe<<" :";
   cin>>bilangan;
   
   // membandingkan dua data dan
   // menyimpan data yang lebih besar
   if (bilangan>terbesar) terbesar=bilangan;
}
  cout<<"Bilangan terbesar :  "<<terbesar;

// menahan tampilan di layar, supaya dapat dibaca
    getch();

   // menutup layar mode ncurses
   endwin();  

  // karena int main() jadi bisa return 11
  return 11;
}
