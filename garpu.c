/* ---------------------------------------------
 * program untuk menunjukkan salah satu
 * efek dari perbanyakan proses di dalam sistem
 * dibuat oleh dwi sakethi:
 * - 21 maret 2022
 * 
 * 
 * file ini disimpan dengan nama garpu.c
 * compile gcc garpu.c -o garpu 
 * 
 * dijalankan dengan perintah: ./garpu
 * --------------------------------------------- */


// karena ada fungsi input dan output
#include <stdio.h>


// program dalam bahasa C harus ada fungsi main()
int main()
{
 
   // deklarasi variabel
   long int baris;
   
  // kesalahan logika sehingga looping berjalan terus
    while (1>0)
     {
        // mencetak pada baris yang bertambah
        // supaya tulisan tambah ke bawah
        printf("Proses: %d \n",baris);
        baris++;
        
        // perintah untuk membuat anak proses
        // perintah ini hanya ada di C dan
        // sudah tidak ada lagi di C++
        fork();
     }    
    
   // kembali ke program utama
   return 0;
}
