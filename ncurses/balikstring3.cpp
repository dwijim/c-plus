/* ---------------------------------------------------------------------------
   program untuk membalikkan satu angka yang terdiri atas tiga digit bilangan
   namun angka ini dianggap sebagai suatu string, bukan suatu bilangan
   dwi sakethi, 3 september 2026
   nama berkas : balikstring3.cpp
   compile : g++ balikstring3.cpp -o coba
   
   di sini digunakan fungsi yang sudah ada yaitu reverse
   cara ini sangat mudah tapi tidak disarankan supaya kita
   bisa mencari ide sendiri
   
   --------------------------------------------------------------------------- */
   
#include <iostream>   
// Header untuk input dan output

#include <string>     
// Header untuk tipe data string

#include <algorithm>  
// Header untuk fungsi reverse()

using namespace std;  
// Menggunakan namespace standar untuk mempermudah penulisan program

int main() {
    string angka;      
    // deklarasi variabel untuk menyimpan input string angka

    // Meminta pengguna memasukkan string angka 3 karakter
    cout << "Masukkan string bilangan (3 karakter): ";
    cin >> angka;

    reverse(angka.begin(), angka.end());

    // Menampilkan hasil string yang sudah dibalik
    cout << "String setelah dibalik: " << angka << endl;

    return 0; // Mengakhiri program dengan status sukses
}
