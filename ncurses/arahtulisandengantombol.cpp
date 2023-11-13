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

// posisi baris bawah
#define baris_bawah 20

// posisi baris dan kolom target
#define baris_target 2
#define kolom_target 37


// harus ada fungsi main()
int main(){

   // deklarasi variabel
   int tombol;
   short int baris, kolom;
   
   // memberi posisi baris di bagian bawah
   baris = baris_bawah;

   // meletakkan posisi awal di tengah kolom layar
   kolom = kolom_tengah;

  // menginisiasi layar untuk penggunaan ncurses
   initscr();

   // supaya dapat dideteksi penekanan tombol khusus seperti
   // F1 .. F10, panah kanan, panah kiri dst ...
   keypad(stdscr,TRUE);

  //keypad (win, true);
  
   // menyembunyikan tampilan kursor
   curs_set(0);

  // nodelay - enable or disable block during read
   nodelay(stdscr, TRUE);
   
   // tampilan awal di tengah layar
   mvprintw(baris,kolom," aku ");

   // membuat looping selama tidak menekan tombol ESC
     while (tombol != KEY_ESC) {
       
       mvprintw (baris_target,kolom_target,"*");
          if ((tombol = getch()) == ERR) {
              /* user hasn't responded
               ...
              */
          }
          else {
              /* user has pressed a key ch
               ...
              */ 
             if (tombol == KEY_ENTER)
                { 
                  // misal kalau menekan tombol enter
                  // ada sesuatu yang akan dilakukan
                  // dapat dituliskan di sini
                
               int baris_peluru;
               
                  for (baris_peluru=baris-1;baris_peluru<=baris_target;baris_peluru--)
                  {
                    mvprintw(baris_peluru,kolom,"^");
//sleep(1);
                    mvprintw(baris_peluru,kolom," ");
                    
                  }
                  }  
             else if(tombol == KEY_LEFT)
                { 
                  // bergerak ke kiri, jadi kolom berkurang
                  kolom = kolom - 1;

                  // jika sudah mentok ke kiri, kolom tetap 1
                  if (kolom==1) kolom=1;
                }  
             else if(tombol == KEY_RIGHT)
                { 
                  // bergerak ke kanan, jadi kolom bertambah
                  kolom = kolom + 1;

                  // jika sudah mentok ke kanan, kolom tetap 75
                  if (kolom>batas_kanan_kolom) kolom=batas_kanan_kolom;
                }  
             else if(tombol == KEY_UP) 
                { 
                  
                  // di tempat lama, dihapus dengan mencetak spasi
                  mvprintw(baris,kolom,"     ");

                  // bergerak ke atas, jadi baris berkurang
                  baris = baris - 1;

                  // jika sudah mentok ke atas, baris tetap 5
                  if (baris==5) baris=5;
                }  
             else if(tombol == KEY_DOWN)
                { 
                  
                  // di tempat lama, dihapus dengan mencetak spasi
                  mvprintw(baris,kolom,"     ");

                  // bergerak ke atas, jadi baris berkurang
                  baris = baris + 1;

                  // jika sudah mentok ke atas, baris tetap 5
                  if (baris==baris_bawah) baris=baris_bawah;
                }  


                // cetak sesuatu sesuai dengan baris dan kolom
                // di kanan dan kiri diberi spasi
                // untuk menghapus
                mvprintw(baris,kolom," aku ");
                
	  }  
     }

   // menutup layar mode ncurses
   endwin();  

   // kembali ke program utama
   return 0;
}
