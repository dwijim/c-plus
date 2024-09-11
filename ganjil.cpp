/* --------------------------------------------------
   program untuk menentukan suatu bilangan termasuk
   ke dalam kategori bilangan ganjil atau bilangan
   genap.
   file name : ganjilgenap.cpp
   compiling : g++ ./ganjilgenap.cpp -o bilangan
   running   : ./bilangan
   dwi sakethi
   -------------------------------------------------- */

// karena di dalam program ada perintah cin dan cout
#include "iostream"

// untuk memudahkan penulisan program
using namespace std;

/* --------------------------------------------------
   program dalam bahasa c++ minimal terdiri dari
   satu fungsi, yaitu fungsi main yang menghasilkan
   nilai bertipe integer
   -------------------------------------------------- */
int main(){

   // deklarasi variabel
   int bilangan;
   int sisa;

   // pemasukan data
   cout << "Masukkan suatu bilangan : ";
   cin >> bilangan;
   cout << "\n";

   // proses
   sisa = bilangan % 2;

   // mencetak hasil
   if (sisa==0)
      {
         cout << "bilangan genap \n";
      }
   else
      {
         cout << "bilangan ganjil \n";
      }

   // akhir program
   return 999;
}
