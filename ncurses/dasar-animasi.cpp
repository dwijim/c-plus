/* -------------------------------
   contoh format dasar program C++
   dengan menggunakan pustaka ncurses
   nama file: formatdasar.cpp
   dicompile dengan perintah:
   g++ formatdasar.cpp -o format -l ncurses
   
   program ini ditulis di cocalc.com
   pada tanggal 12 september 2021

   ------------------------------- */

// ini karena menggunakan pustaka ncurses
#include "ncurses.h"

// input/output di dalam C++
#include "iostream"

// menggunakan fungsi untuk delay
#include <unistd.h> 

// tidak disarankan menggunakan seperti ini
// supaya menyingkat penulisan
using namespace std;


// program dalam bahasa C harus terdiri paling tidak
// satu fungsi, yaitu fungsi main()
int main(){
  
  int baris,bilangan,kolom;
  
  //mengawali layar untuk ncurses
  initscr();
  
  // membersihkan layar
  clear(); 
  
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  
  mvprintw(1,5,"                     ");
  mvprintw(1,5,"Jurusan Ilmu Komputer");
  
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  
  mvprintw(1,5,"                     ");
  mvprintw(2,5,"Jurusan Ilmu Komputer");
  
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  
  mvprintw(2,5,"                     ");
  mvprintw(3,5,"Jurusan Ilmu Komputer");
  
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  
  mvprintw(3,5,"                     ");
  mvprintw(4,5,"Jurusan Ilmu Komputer");
  
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  
  mvprintw(4,5,"                     ");
  mvprintw(5,5,"Jurusan Ilmu Komputer");
   
  clear();
  for (baris=1;baris<=22;baris++)
  {
  mvprintw(baris,5,"Birgita Jesika Wulansari");
  refresh(); sleep(1);  
  mvprintw(baris,5,"                        ");
    
     
  }

    clear();
  for (kolom=65;kolom>=1;kolom--)
  {
  mvprintw(12,kolom,"Birgita Jesika Wulansari");
  refresh(); sleep(1);  
  mvprintw(12,kolom,"                        ");
    
     
  }

  // menahan tampilan layar
  getch();
  
  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 11;
}







