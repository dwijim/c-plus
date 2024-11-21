/* -------------------------------------------------------
 * program untuk mendeteksi tombol yang ditekan
 * kemudian menggeser tulisan ke kiri atau ke kanan
 * sesuai dengan tombol panah yang ditekan
 * untuk keluar dari program, tekan tombol ESC
 * dibuat oleh dwi sakethi:
 * - 4 juli 2021
 * - 5 juli 2021
 * - 14 november 2021
 * - 16 november 2021
 * - 14 november 2023
 
 * untuk mengkompilasi dan menjalankan program ini
 * sudah dicoba di Linux yang sudah dipasang
 * g++ compiler dan ncurses
 * serta dapat juga dikompilasi dan dijalankan
 * secara online di https://cocalc.com/
 *
 * file ini disimpan dengan nama arahtulisandengantombol.cpp
 * compile g++ arahtulisandengantombol.cpp -o tombol -l ncurses
 * 
 * ------------------------------------------------------- */

#include "iostream"
#include "ncurses.h"
#include "string.h"

using namespace std;

// mendefinisikan tombol ESC nilai 27
#define KEY_ESC 27

// definisi batas kanan kolom
#define batas_kanan_kolom 75

// kolom tengah layar
#define kolom_tengah 40

// posisi baris atas
#define baris_atas 5
#define baris_awal 5

// posisi baris dan kolom target
#define baris_target 2
#define kolom_target 37


// harus ada fungsi main()
int main(){

   string tulisan_menu[5];

   short int baris, posisi_menu, i;
   short int baris_bawah,tombol;


   tulisan_menu[0] = " Bahasa C++        ";
   tulisan_menu[1] = " Bahasa Java       ";
   tulisan_menu[2] = " Bahasa Python     ";
   tulisan_menu[3] = " Bahasa PHP        ";
   tulisan_menu[4] = " Bahasa JavaScript ";
 
  // menginisiasi layar untuk penggunaan ncurses
   initscr();
   clear();
   // supaya dapat dideteksi penekanan tombol khusus seperti
   // F1 .. F10, panah kanan, panah kiri dst ...
   keypad(stdscr,TRUE);

  //keypad (win, true);
  
   // menyembunyikan tampilan kursor
   curs_set(0);

  // nodelay - enable or disable block during read
   nodelay(stdscr, TRUE);
   start_color();  // Aktifkan penggunaan warna
   init_pair(1, COLOR_WHITE,COLOR_RED); // Pasangan warna 1: putih (foreground), merah (background)
   init_pair(2,COLOR_RED, COLOR_WHITE); // Pasangan warna 1: putih (foreground), merah (background)


   attron(COLOR_PAIR(1)); // Terapkan pasangan warna 1


getch();

   i = 0; 
   for (baris=baris_atas;baris<baris_atas+5;baris++)
   {
     attron(COLOR_PAIR(2)); // Terapkan pasangan warna 1
     mvprintw(baris,kolom_target,"%s",tulisan_menu[i].c_str());
     i++;
   }
     attron(COLOR_PAIR(1)); // Terapkan pasangan warna 1
     mvprintw(baris_awal,kolom_target,"%s",tulisan_menu[0].c_str());

   posisi_menu = 0;
   // membuat looping selama tidak menekan tombol ESC
     while (tombol != KEY_ESC) 
      {
       
          if ((tombol = getch()) == ERR) {
              /* user hasn't responded
               ...
              */
          }
        if (tombol == KEY_HOME )
                { 

                  // bergerak ke atas, jadi baris berkurang

                  // jika sudah mentok ke atas, baris tetap 5
                  clear();
                  printw("Anda memilih suatu menu");
                   getch();
                }  
        else if (tombol == KEY_UP) 
                { 

                  // bergerak ke atas, jadi baris berkurang
                  baris       = baris - 1;
                  posisi_menu = posisi_menu - 1;

                  // jika sudah mentok ke atas, baris tetap 5
                  if (baris==5) baris=5;
                }  
             else if(tombol == KEY_DOWN)
                { 
                  
                  // bergerak ke atas, jadi baris berkurang
                  baris       = baris + 1;
                  posisi_menu = posisi_menu + 1;

                  if (posisi_menu!=5)
                  {
                  // cetak
                  attron(COLOR_PAIR(1)); // Terapkan pasangan warna 1
                  mvprintw(baris_awal+posisi_menu,kolom_target,"%s",tulisan_menu[posisi_menu].c_str());

                  attron(COLOR_PAIR(2)); // Terapkan pasangan warna 1
                  mvprintw(baris_awal+posisi_menu-1,kolom_target,"%s",tulisan_menu[posisi_menu-1].c_str());
                }
                  // jika sudah mentok ke atas, baris tetap 5
                  if (posisi_menu==5) 
                     {
                        baris       = baris_awal;
                        posisi_menu = 0;
                  // cetak
                  attron(COLOR_PAIR(1)); // Terapkan pasangan warna 1
                  mvprintw(baris_awal,kolom_target,"%s",tulisan_menu[0].c_str());

                  attron(COLOR_PAIR(2)); // Terapkan pasangan warna 1
                  mvprintw(baris_awal+4,kolom_target,"%s",tulisan_menu[4].c_str());

                        
                     }
             }  


     }

   // menutup layar mode ncurses
   endwin();  

   // kembali ke program utama
   return 0;
}