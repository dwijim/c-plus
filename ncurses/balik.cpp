  /* ini program untuk membalik angka
 * yang terdiri dari 3 digit tidak boleh lebih
 * dan tidak boleh kurang.
 * 8 september 2021
 
   dwi sakethi
 */

#include "ncurses.h"
// menyertakan library standar input dan output
#include <iostream>

// ini sebenarnya kebiasaan kurang baik
using namespace std;

// program dalam bahasa C++ terdiri paling tidak
// satu fungsi, yaitu fungsi main()
int main(){

  int bilangan;
 // bilangan adalah data yang dimasukan dan akan dibalik
 
 int hasil,satuan, puluhan, ratusan;
 // satuan adalah angka pertama
 // puluhan adalah angka kedua
 // ratusan adalah angka ketiga

// inisialisasi layar
  initscr();
  
// menampilkan judul program
mvprintw(8,30,"Program Untuk Membalik Bilangan 3 Digit");

// masukan suatu angka
mvprintw(10,30,"Masukkan suatu bilangan: ");
scanw("%d",&bilangan);


// menghitung nilai satuan 
satuan   = bilangan % 10;

// menghitung nilai puluhsan
puluhan  = ((bilangan-satuan)%100) / 10;

// menghitung nilai ratusan
ratusan  = (bilangan-((puluhan*10)+satuan)) / 100;

// membalikkan angka
hasil    = (satuan*100)+(10*puluhan)+ratusan;

// mencetak hasil
cout<<"Setelah Dibalik Menjadi : "<< hasil;
 
 // karena int main, jadi hasilnya adalah bilangan bulat
 // salah satunya 0
 return 0;
 
}
  


