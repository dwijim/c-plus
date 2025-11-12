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
    int tombol,i,jumlah_karakter;
    short int baris, kolom;
    short int baris_posisi[11], kolom_posisi[11];
 
    string hewan="0++++++++> ";
   
    // memberi posisi baris di bagian bawah
    baris = baris_bawah;
 
    // meletakkan posisi awal di tengah kolom layar
    kolom = kolom_tengah;
 
    jumlah_karakter = 11;
 
    // menentukan posisi baris dan kolom
    baris_posisi[0]=baris;
    baris_posisi[1]=baris;
    baris_posisi[2]=baris;
    baris_posisi[3]=baris;
    baris_posisi[4]=baris;
    baris_posisi[5]=baris;
    baris_posisi[6]=baris;
    baris_posisi[7]=baris;
    baris_posisi[8]=baris;
    baris_posisi[9]=baris;
    baris_posisi[10]=baris;
 
    kolom_posisi[0]=kolom;
    kolom_posisi[1]=kolom+1;
    kolom_posisi[2]=kolom+2;
    kolom_posisi[3]=kolom+3;
    kolom_posisi[4]=kolom+4;
    kolom_posisi[5]=kolom+5;
    kolom_posisi[6]=kolom+6;
    kolom_posisi[7]=kolom+7;
    kolom_posisi[8]=kolom+8;
    kolom_posisi[9]=kolom+9;
    kolom_posisi[10]=kolom+10;
 
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
 
    for (i=0;i<=jumlah_karakter;i++)
    {
      mvprintw(baris_posisi[i],kolom_posisi[i],"%c",hewan[i]);
      getch();
    }
    getch();
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
                   if (kolom==1) kolom=75;
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
                   //mvprintw(baris,kolom,"     ");
 
                   // bergerak ke atas, jadi baris berkurang
                   baris = baris - 1;
 
                   // jika sudah mentok ke atas, baris tetap 5
                   if (baris==5) baris=5;
                 }  
              else if(tombol == KEY_DOWN)
                 { 
                   
                   // di tempat lama, dihapus dengan mencetak spasi
                   //mvprintw(baris,kolom,"     ");
 
                   // bergerak ke atas, jadi baris berkurang
                   baris = baris + 1;
 
                   // jika sudah mentok ke atas, baris tetap 5
                   if (baris==baris_bawah) baris=baris_bawah;
                 }  
 
 
                 // cetak sesuatu sesuai dengan baris dan kolom
                 // di kanan dan kiri diberi spasi
                 // untuk menghapus
                 //mvprintw(baris,kolom,"%s",hewan);
                 for (i=jumlah_karakter;i>0;i--)
 //                for (i=1;i<jumlah_karakter;i++)
                 {
                   baris_posisi[i]=baris_posisi[i-1];
                   kolom_posisi[i]=kolom_posisi[i-1];
                 }
                 baris_posisi[0]=baris;
                 kolom_posisi[0]=kolom;
                 for (i=0;i<=jumlah_karakter;i++)
                   {
                     mvprintw(baris_posisi[i],kolom_posisi[i],"%c",hewan[i]);
                     //getch();
                   }
 
       }  
      }
 
    // menutup layar mode ncurses
    endwin();  
 
    // kembali ke program utama
    return 0;
 }