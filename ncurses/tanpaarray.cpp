/* -------------------------------
   contoh format dasar program C++ 
   dengan menggunakan pustaka ncurses
   nama file: array.cpp
   dicompile dengan perintah:
   g++ array.cpp -o array -l ncurses
   
   program ini ditulis di cocalc.com
   pada tanggal: 12 september 2021
                  2 oktober 2021
<sup></sup><sup></sup>
   ------------------------------- */

// menentukan batas banyaknya data
#define jumlah_data_maksimal 100

// ini karena menggunakan pustaka ncurses
#include "ncurses.h"

// input/output di dalam C++
#include "iostream"

// tidak disarankan menggunakan seperti ini
// supaya menyingkat penulisan
using namespace std;

// program dalam bahasa C++ terdiri paling tidak atas satu fungsi
// yaitu fungsi main()
int main(){
  
    // deklarasi variabel tapa array
    float bilangan01,bilangan02,bilangan03,bilangan04,bilangan05;
    float bilangan06,bilangan07,bilangan08,bilangan09,bilangan10;
    short int jumlah_data;
    float jumlah;
    short int data_ke;

  //mengawali layar untuk ncurses
  initscr(); 
  
  // membersihkan layar
  clear();
  
    // memasukkan suatu nilai
    mvprintw(data_ke+1,10,"Masukan banyaknya bilangan: ");
    scanw("%f",&jumlah_data);
  
  // membersihkan layar
  clear();
  
    // memasukkan suatu nilai bilangan01
    mvprintw(1,10,"Masukan bilangan ke-1: ");
    scanw("%f",&bilangan01);
  clear();
  
    // memasukkan suatu nilai bilangan02
    mvprintw(1,10,"Masukan bilangan ke-2: ");
    scanw("%f",&bilangan02);
  clear();
  
    // memasukkan suatu nilai bilangan03
    mvprintw(1,10,"Masukan bilangan ke-3: ");
    scanw("%f",&bilangan03);
  clear();
  
   jumlah = bilangan01+bilangan02+bilangan03;
    mvprintw(1,10,"Jumlah bilangan %f",jumlah);
  
  
  // menahan tampilan layar
  getch();
  
  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 11;
}
