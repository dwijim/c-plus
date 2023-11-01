/* ------------------------------------------
   program untuk membuat tulisan bergerak
   dari kiri ke kanan
   menggunakan library ncurses
   1 november 2023
   dwi sakethi
   ------------------------------------------ */

// menyertakan ncurses
#include "ncurses.h"

// alat I/O standar
#include "iostream"

// untuk mempermudah penulisan program
using namespace std;

// program dalam bahasa C++ minimal
// terdiri dari satu fungsi
// yaitu fungsi main()

// kolom awal pencetakan
#define kolom_awal 5

// kolom akhir pencetakan
#define kolom_akhir 75

// baris pencetakan
#define baris 10

int main(){

  // deklrasasi variabel
	int kolom;

  // awal program dengan ncurses
	initscr();

for (kolom=kolom_awal;kolom<=kolom_akhir;kolom++)
{
  // mencetak suatu tulisan
  mvprintw(baris,kolom, "dwijim");
  
  // berhenti sampai penekanan tombol
  getch();
  
  // menghapus tulisan
  mvprintw(baris,kolom, "      ");
}

  // akhir program dengan ncurses
  endwin();
  
  // akhir fungsi main()
  return 46;
}

