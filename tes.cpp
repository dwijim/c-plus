/* -----------------------------------
 * program untuk mencari bilangan terbesar
 * dari sekumpulan bilangan
 * dibuat oleh dwi sakethi diedit oleh M.Fadhil Azhari
 * nama file bilangan-terbesar.cpp
 ------------------------------------------- */

// karena ada fungsi cin>> dan cpout<<
#include <iostream>
using namespace std;

// deklarasi variabel yang digunakan
int BanyakData, DataKe;
int bilangan;
int terbesar;

// harus ada fungsi main()
int main()
{
    
/* -----------------------------------------
 * bilangan terbesar diberi nilai awal
 * dengan bilangan sekecil-kecilnya
 * (tergantung asumsi data yang ada
   ----------------------------------------- */

// karena mencari bilanga terbesar maka
// terbesar diberi awal sekecil-kecilnya
terbesar = -999;

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

  // karena int main() jadi bisa return 11
  return 11;
}
