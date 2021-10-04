/* -------------------------------
   contoh format dasar program C++
   dengan menggunakan pustaka ncurses
   nama file: array.cpp
   dicompile dengan perintah:
   g++ array.cpp -o array -l ncurses
   
   program ini ditulis di cocalc.com
   pada tanggal: 12 september 2021
                  2 oktober 2021

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
  
    // deklarasi variabel
    float bilangan[jumlah_data_maksimal];

    // float bilangan[100];

    float jumlah_data;
    short int data_ke;

  //mengawali layar untuk ncurses
  initscr();
  
  // membersihkan layar
  clear();
  
    // memasukkan suatu nilai
    mvprintw(data_ke+1,10,"Masukan banyaknya bilangan: ");
    scanw("%d",&jumlah_data);
  
  // membersihkan layar
  clear();
  
  jumlah = 0;
    for (data_ke=0;data_ke<jumlah_data;data_ke++)
   {
    // memasukkan suatu nilai
    mvprintw(data_ke+1,10,"Masukan bilangan ke-%d: ",data_ke+1);
    scanw("%f",&bilangan[data_ke]);
    
      // jumlah data
      jumlah = jumlah + bilangan[data_ke];
   }

    mvprintw(data_ke+1,10,"Jumlah : %f",jumlah);

  
  // menahan tampilan layar
  getch();
  
  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 11;
}
