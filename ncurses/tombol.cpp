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
#define baris_tengah 12

// harus ada fungsi main()
int main(){

   // deklarasi variabel
   int tombol,i,jumlah_karakter;
   short int baris, kolom;

  
   // memberi posisi baris di bagian bawah
   baris = baris_tengah;

   // meletakkan posisi awal di tengah kolom layar
   kolom = kolom_tengah;

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
   
   // tampilan awal di tengah layar
   //mvprintw(baris,kolom,"%s",hewan.c_str());
   //mvprintw(17,5,"%s",hewan.c_str());

   // membuat looping selama tidak menekan tombol ESC
     while (tombol != KEY_ESC) 
     {
       
          if ((tombol = getch()) == ERR) {
              /* user hasn't responded
               ...
              */
          }
          else 
              /* user has pressed a key ch
               ...
              */ 
             if (tombol == KEY_ENTER)
                { 
                  }  
             else if(tombol == KEY_LEFT)
                { 
                  // bergerak ke kiri, jadi kolom berkurang
                  kolom = kolom - 1;

                  // jika sudah mentok ke kiri, kolom tetap 1
                  if (kolom<=1) kolom=1;
                  mvprintw (baris,kolom,"*");
                  mvprintw (baris,kolom+1," ");
                }  
             else if(tombol == KEY_RIGHT)
                { 
                  // bergerak ke kiri, jadi kolom berkurang
                  kolom = kolom + 1;

                  // jika sudah mentok ke kiri, kolom tetap 1
                  if (kolom>=75) kolom=75;
                  mvprintw (baris,kolom,"*");
                  mvprintw (baris,kolom-1," ");
                }  
             else if(tombol == KEY_UP)
                { 
                  // bergerak ke kiri, jadi kolom berkurang
                  baris = baris - 1;

                  // jika sudah mentok ke kiri, kolom tetap 1
                  if (baris<=1) baris=1;
                  mvprintw (baris,kolom,"*");
                  mvprintw (baris+1,kolom," ");
                }  
             else if(tombol == KEY_DOWN)
                { 
                  // bergerak ke kiri, jadi kolom berkurang
                  baris = baris + 1;

                  // jika sudah mentok ke kiri, kolom tetap 1
                  if (baris<=1) baris=1;
                  mvprintw (baris,kolom,"*");
                  mvprintw (baris-1,kolom," ");
                }  
      
     }

   // menutup layar mode ncurses
   endwin();  

   // kembali ke program utama
   return 0;
}
