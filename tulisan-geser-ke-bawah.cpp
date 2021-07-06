
/* -----------------------------------------
   program untuk mencetak tulisan yang 
   berjalan dari atas layar ke bawah layar
   dibuat oleh dwi sakethi
   diedit oleh M.Fadhil Azhari
   menggunakan MinGW
   ----------------------------------------- */

// karena ada proses cetak ke layar dan
// pemasukan data via keyboard
#include <iostream>
#include <ostream>

using namespace std;

// menggunakan fungsi-fungsi standar
#include <stdlib.h>

// menggunakan fungsi-fungsi standar
#include <string.h>

//fungsi untuk memindahkan posisi pointer
//di layar
void PosisiLayar(int x,int y)
{
cout << "\x1B["<<y<<";"<<x<<"f";
}

// fungsi utama di dalam bahasa C++
int main ()
{

// mendefinisikan kalimat string 60 karakter	
// ini di microsoft windows
//char kalimat[60];

// ini di Linux
string kalimat;

// mendefinisikan kalimat kosong 60 karakter	
// char KalimatKosong[]="                                        ";
string KalimatKosong="                                        ";

// mendefinisikan variabel baris
short int baris;

// mendefinisikan variabel untuk jeda
long int waktu;

// pada sistem operasi Linux
//system("clear"); //clears the screen


// pada sistem operasi Windows 
system("cls"); //clears the screen

cout << "Masukkan suatu kalimat:";
// gets(kalimat);
std::getline(cin,kalimat);

for (baris=2;baris<=24;baris++)
{

  // di tempat yang lama, cetak tulisan kosong
  // gunanya untuk menghapus
  PosisiLayar(10,baris-1);
  // ini di microsoft windows  
  // puts(KalimatKosong);

  std::getline(cout,KalimatKosong);

  // di tempat yang baru, cetak tulisan aslinya
  PosisiLayar(10,baris);    
  puts(kalimat);


  // ini contoh jika tidak dihapus
  PosisiLayar(60,baris);    
  puts(kalimat);


  // untuk membuat jeda
  for (waktu=0;waktu<=20000000;waktu++);
  	
}


cout << "\x1b[0m"; // would set the background to blue.

// karena ada int main()
return 0;

}
