/* ---------------------------------------------
   program untuk menentukan bilangan ganjil atau
   bilangan genap, menggunakan pustaka ncurses
   dibuat oleh dwi sakethi, 6 september 2021
   nama file: ganjil.cpp
   compiling:
   g++ ./ganjil.cpp -o ganjil -l ncurses

   cara menjalankan: ./ganjil

   --------------------------------------------- */


#include "ncurses.h"
#include "iostream"

using namespace std;

// program dalam bahasa c++ minimal terdiri dari
// satu fungsi, yaitu fungsi main()
int main(){

    // deklarasi variabel yang digunakan dalam program
	int bilangan;
	int sisa;

    // inisialisasi layar dalam ncurses
	initscr();

// hapus layar
clear();

// mencetak tulisan pada baris dan kolom
mvprintw(10,30,"Masukkan suatu bilangan: ");

// pemasukan data
scanw("%d",&bilangan);

// menghitung sisa pembagian
sisa = bilangan % 2;

// mencek nilai sisa pembagian
if (sisa==0)
{
 // mencetak keterangan bilangan genap
 mvprintw(12,30,"Bilangan genap");
}
else
{
 // mencetak keterangan bilangan ganjil
  mvprintw(12,30,"Bilangan ganjil");
}

// menahan tampilan di layar agar tidak langsung dihapus
getch();

// menutup layar
endwin();

return 0;
} // akhir program
