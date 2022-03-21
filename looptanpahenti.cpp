/* ---------------------------------------------
 * program untuk menunjukkan salah satu
 * contoh looping yang tidak berhenti
 * dibuat oleh dwi sakethi:
 * - 21 maret 2022
 * 
 * 
 * file ini disimpan dengan nama looptanpahenti.cpp
 * compile g++ looptanpahenti.cpp -o coba 
 * 
 * dijalankan dengan perintah: ./coba
 * --------------------------------------------- */


// karena ada fungsi input dan output
#include <iostream>

// untuk menyingkat penulisan tapi sebenarnya ...
using namespace std;

// program dalam bahasa C++ harus ada fungsi main()
int main()
{
 
   // deklarasi variabel
   long int baris;
   
  // kesalahan logika sehingga looping berjalan terus
    while (1>0)
     {
        // mencetak pada baris yang bertambah
        // supaya tulisan tambah ke bawah
        cout << "Proses: " << baris << "\n";
        baris++;
     }    
    
   // kembali ke program utama
   return 0;
}
