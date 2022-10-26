/* -------------------------------
   26 oktober 2022
   contoh program animasi manual
   dengan menggunakan pustaka ncurses
   nama file: animasi-manual.cpp
   
   dicompile dengan perintah:
   g++ animasi-manual.cpp -o animasi -l ncurses
   
   kemudian dijalankan dengan perintah:
   ./animasi


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

// program dalam bahasa C/C++ harus terdiri paling tidak
// satu fungsi, yaitu fungsi main()
int main(){
  
  int baris,bilangan,kolom;
  
  //mengawali layar untuk ncurses
  initscr();
  
  // membersihkan layar
  clear(); 
  
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  

  // menghapus tampilan sebelumnya
  mvprintw(1,5,"                     ");
  // mencetak tampilan di lokasi baru
  mvprintw(1,5,"Jurusan Ilmu Komputer");
  
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  
  // menghapus tampilan sebelumnya
  mvprintw(1,5,"                     ");
  // mencetak tampilan di lokasi baru
  mvprintw(2,5,"Jurusan Ilmu Komputer");
  
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  
  // menghapus tampilan sebelumnya
  mvprintw(2,5,"                     ");
  // mencetak tampilan di lokasi baru
  mvprintw(3,5,"Jurusan Ilmu Komputer");
  
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  
  // menghapus tampilan sebelumnya
  mvprintw(3,5,"                     ");
  // mencetak tampilan di lokasi baru
  mvprintw(4,5,"Jurusan Ilmu Komputer");
  
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  
  // menghapus tampilan sebelumnya
  mvprintw(4,5,"                     ");
  // mencetak tampilan di lokasi baru
  mvprintw(5,5,"Jurusan Ilmu Komputer");
   
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  
  // menghapus tampilan sebelumnya
  mvprintw(5,5,"                     ");
  // mencetak tampilan di lokasi baru
  mvprintw(6,5,"Jurusan Ilmu Komputer");
   
  // menghentikan proses selama 1 detik
  refresh(); sleep(1);  
  // menghapus tampilan sebelumnya
  mvprintw(6,5,"                     ");
  // mencetak tampilan di lokasi baru
  mvprintw(7,5,"Jurusan Ilmu Komputer");
   
  // menahan tampilan layar
  getch();
  
  //mengakhiri layar ncurses
  endwin();
  
  // hasil fungsi main() bertipe integer
  return 11;
}
