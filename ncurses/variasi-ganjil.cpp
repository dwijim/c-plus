#include <ncurses.h>
#include <cmath>

// untuk memudahkan penulisan
using namespace std;

// program dalam bahasa c++ minimal terdiri dari
// satu fungsi yaitu fungsi main
int main()
{
  // deklarasi variabel yang digunakan
  float bilangan,sisa,bilangan_akhir;
  float bilangan_awal;
  
  // menginisiasi mode ncurses
  initscr();
  // menghapus layar
  clear();
  
  // mencetak tulisan
  mvprintw(5,10,"Masukan suatu bilangan: ");
  
  // formatnya %d karena variabel bilangan
  // bertipe integer
  scanw("%f",&bilangan);
  
  // menghitung sisa pembagian dengan angka 2
  // hasilnya pasti antara 0 atau 1
  //sisa = bilangan % 2;
  sisa = 2.0;
  if (sisa==0)
    {
       //mvprintw(6,10,"Bilangan genap");
    }
  else
    {
       //mvprintw(6,10,"Bilangan ganjil");
    }
  
  //sisa = div_t(bilangan,2);
  sisa = floor(bilangan/2);
  bilangan_akhir = sisa * 2;
  
  if (bilangan==bilangan_akhir)
    {
       mvprintw(7,10,"Bilangan genap");
    }
  else
    {
       mvprintw(7,10,"Bilangan ganjil");
    }
  
  bilangan_awal = 0;
  while (bilangan_awal<bilangan)
  {
     bilangan_awal = bilangan_awal + 2;
  }
  
  if (bilangan==bilangan_awal)
    {
       mvprintw(8,10,"Bilangan genap");
    }
  else
    {
       mvprintw(8,10,"Bilangan ganjil");
    }
  
  bilangan_awal = bilangan;
  while (bilangan_awal>0)
  {
     bilangan_awal = bilangan_awal - 2;
  }
  
  if (bilangan_awal==0.0)
    {
       mvprintw(9,10,"Bilangan genap");
    }
  else
    {
       mvprintw(9,10,"Bilangan ganjil");
    }
  // mem-pause program
  getch();
  
  // akhir ncurses
  endwin();

}
