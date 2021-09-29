/* -------------------------------
   contoh format dasar program C++
   dengan menggunakan pustaka ncurses
   nama file: kotak.cpp
   dicompile dengan perintah:
   g++ kotak.cpp -o kotak -l ncurses
   
   program ini ditulis di cocalc.com
   pada tanggal 12 september 2021

   ------------------------------- */

// ini karena menggunakan pustaka ncurses
#include "ncurses.h"

// input/output di dalam C++
#include "iostream"

// tidak disarankan menggunakan seperti ini
// supaya menyingkat penulisan
using namespace std;

#define pojok (43)
//#     pojok  "+"

#define horisontal (45)
//#     garis mendatar  "-"

#define vertikal (124)
//#     garis vertikal  "|"

void kotak(int baris11, int kolom11,int baris22,  int kolom22)
{
  int kolom1,kolom2,baris1,baris2;
  int kol,bar;
  // baris atas mendatar
  kolom1 = kolom11;
  baris1 = baris11;
  kolom2 = kolom22;
  baris2 = baris22;
  
  mvprintw(baris1,kolom1,"%c",pojok);
  
  for (kol=kolom1+1;kol<=kolom2-1;kol++)
  {    
    mvprintw(baris1,kol,"%c",horisontal);    
  }
  mvprintw(baris1,kolom2,"%c",pojok);

  // baris samping kanan ke bawah
  
  for (bar=baris1+1;bar<=baris2-1;bar++)
  {    
    mvprintw(bar,kolom2,"%c",vertikal);    
  }
  mvprintw(baris2,kolom2,"%c",pojok);
 
  // baris bawah ke kiri
  
  for (kol=kolom2-1;kol>=kolom1+1;kol--)
  {    
    mvprintw(baris2,kol,"%c",horisontal);    
  }
  mvprintw(baris2,kolom1,"%c",pojok);

  // baris samping kiri ke atas
  
  for (bar=baris2-1;bar>=baris1+1;bar--)
  {    
    mvprintw(bar,kolom1,"%c",vertikal);    
  }

  
  
}

int main(){
  
  int gerak;
   
  //mengawali layar untuk ncurses
  initscr();
  
  // membersihkan layar
  clear();
  
  kotak(3,8,9,15);

  kotak(11,20,20,45);

  kotak(3,30,10,50);
  
  // menahan tampilan layar
  getch();
   
     clear();
  for (gerak=1;gerak<=40;gerak++)
  {
    
    kotak(gerak,5,10+gerak,25);
    getch();
    clear();
  }

  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 46;
}






