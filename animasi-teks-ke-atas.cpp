
/* -----------------------------------------
   program untuk mencetak tulisan yang 
   berjalan dari bawa layar ke atas layar
   per karakter
   dibuat oleh dwi sakethi
   menggunakan C++ Compiler
   ----------------------------------------- */

// karena ada proses cetak ke layar dan
// pemasukan data via keyboard
#include <iostream>

// menggunakan fungsi-fungsi standar
#include<stdlib.h>

// menggunakan fungsi-fungsi standar
#include<string.h>

// menggunakan fungsi-fungsi standar
//#include<unistd.h>

//fungsi untuk memindahkan posisi pointer
//di layar

using namespace std;

void PosisiLayar(int x,int y)
{
	cout << "\x1B["<<y<<";"<<x<<"f";
}

// fungsi utama di dalam bahasa C
int main ()
{
  
// mendefinisikan kalimat string 60 karakter	
char kalimat[60]="dwi sakethi - universitas lampung";

// mendefinisikan variabel baris
short int baris;

// mendefinisikan posisi huruf
short int huruf;

// mendefinisikan posisi huruf
short int kolom;

// mendefinisikan posisi huruf
short int panjang_kalimat;

// mendefinisikan variabel untuk jeda
// int waktu,waktu2;

// ini kalau di OS Linux
system("clear"); //clears the screen

// ini kalau di Windows
//system("cls"); //clears the screen

cout << "Masukkan suatu kalimat:";
//gets(kalimat);

//system("clear"); //clears the screen

 

//PosisiLayar(30,25); //reposition cursor   
//printf("%s", kalimat);

panjang_kalimat = strlen(kalimat);

for (huruf=0;huruf<panjang_kalimat;huruf++)
{
 kolom=15+huruf;
 //printf("bingung ");
// potongan=substr(kalimat,huruf-1,1);  
 for (baris=23;baris>=3;baris--)
 {
   PosisiLayar(kolom,baris+1); //reposition cursor   
   cout << " ";
   
  PosisiLayar(kolom,baris); //reposition cursor   
   cout << kalimat[huruf];
   

  //sleep(1);

   PosisiLayar(1,1); //reposition cursor   
   getchar();
  	
 }

}

return 0;

}
