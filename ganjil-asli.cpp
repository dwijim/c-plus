/* -------------------------------------------------------------
   contoh ini telah di-compile pada sistem operasi Windows 10 
   dengan compiler g++. nama file ganjil-asli.cpp
   
   perintah compile : gcc ganjil-asli.cpp -o ganjil-asli        
   
   jika tidak ada kesalahan, program dapat dijalankan dengan 
   memberikan perintah:

   ./ganjil-asli

   #dwi sakethi 10 oktober 2018     
    dikonversi ke bahasa C++ oleh Muhammad Arief Islamy   
   ------------------------------------------------------------- */

// menyertakan library untuk memasukkan data dan mencetak
// data ke layar
#include <iostream>

using namespace std;

// program bahasa C++ harus memiliki fungsi main
int main()
{
   int bilangan;
   int sisa_pembagian;
   
   // mencetak judul
   cout<<"Program Bilangan Ganjil/Genap";

   // menanyakan suatu bilangan
   cout<<"\nMasukkan suatu bilangan: ";cin>>bilangan;
   
   // menghitung sisa pembagian
   sisa_pembagian = bilangan % 2;
   
   // mencek apakah sisa pembagian sama dengan 0
   if (sisa_pembagian==0)
      {
	     cout<<("\nBilangan genap");
      }
   else   
      {
	     cout<<("\nBilangan ganjil");
      }
      
  // karena int main, maka harus ada return
  // salah satu contoh bilangan int adalah 1
  return 1;   
}
