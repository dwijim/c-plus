/* ---------------------------------------------------------------------------
   program untuk membalikkan satu angka yang terdiri atas tiga digit bilangan
   namun angka ini dianggap sebagai suatu string, bukan suatu bilangan
   dwi sakethi, 3 september 2026
   nama berkas : balikstring2.cpp
   compile : g++ balikstring2.cpp -o coba
   
   proses adalah dengan menjejerkan string dari kanan kiri.
   kalau dalam pemrograman stringnya dijumlahkan
   
   --------------------------------------------------------------------------- */
   
#include <iostream>   
// Header untuk input dan output

#include <string>     
// Header untuk tipe data string

using namespace std;  
// Menggunakan namespace standar untuk mempermudah penulisan program

int main() {
    string angka;      
    // deklarasi variabel untuk menyimpan input string angka

    string angkaBalik;      
    // deklarasi variabel untuk menyimpan input string angka

    // Meminta pengguna memasukkan string angka 3 karakter
    cout << "Masukkan string bilangan (3 karakter): ";
    cin >> angka;

    // string kemudian dijejerkan lagi tapi mulai dari kanan ke kiri
    angkaBalik = string(1, angka[2]) + string(1, angka[1]) + string(1, angka[0]);

    // Menampilkan hasil string yang sudah dibalik
    cout << "String setelah dibalik: " << angkaBalik << endl;

    return 0; // Mengakhiri program dengan status sukses
}
