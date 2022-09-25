/* --------------------------------
 * dibuat oleh dwi sakethi
 * di kelas sambil kuliah
 * 22 september 2022
 * -------------------------------- */

// program dalam bahasa c minimal terdiri 
// dari satu fungsi yaitu fungsi main()

#include "ncurses.h"

int main()
{
	int hari,posisi;
	int kolom,baris;
	int ganti_baris,awal;
	int banyaknya_hari,tanggal_satu;
  initscr();
  
// tanggal 1 ada di hari apa
mvprintw(1,1,"Tanggal 1 jatuh pada hari: ");
scanw("%d",&tanggal_satu);

// tanya banyaknya hari
mvprintw(2,1,"Masukkan banyaknya hari: ");
scanw("%d",&banyaknya_hari);

  kolom = 7;
  baris = 5;
  posisi = 1;
  // cetak strip
  for (awal=1;awal<tanggal_satu;awal++)
  {
    mvprintw(baris,kolom,"-");
    kolom = kolom + 4;
    posisi = posisi + 1;
  }
  for (hari=1;hari<=banyaknya_hari;hari++)
  {
     mvprintw(baris,kolom,"%d",hari);
     kolom = kolom + 4;
     ganti_baris = posisi % 7;
     posisi = posisi + 1;
     if (ganti_baris == 0)
     {
       baris = baris + 1;
       kolom = 7;
       posisi = 1;
     }
  }
  getch();
  endwin();
  return 127;
}

