
/* -----------------------------------
 * program untuk mencari bilangan terbesar
 * dari sekumpulan bilangan
 * dibuat oleh dwi sakethi diedit oleh M.Fadhil Azhari
 * nama file bilangan-terbesar.cpp
 * perbaikan terakhir:
 * 13 september 2022
 ------------------------------------------- */

// karena ada fungsi cin>> dan cpout<<
#include <iostream>

// ini sebenarnya tidak disarankan
using namespace std;

// harus ada fungsi main()
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

// karena mencari bilangan terbesar maka
// terbesar diberi awal sekecil-kecilnya
terbesar = 999;

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
  cout<<"Bilangan terbesar :  "<<terbesar <<"\n";

  // karena int main() jadi bisa return 11
  return 11;
}
