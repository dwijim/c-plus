/* ---------------------------------------------------------------------------
   program untuk membalikkan satu angka yang terdiri atas tiga digit bilangan
   namun angka ini dianggap sebagai suatu string, bukan suatu bilangan
   dwi sakethi, 3 september 2026
   nama berkas : balikstring1.cpp
   compile : g++ balikstring1.cpp -o coba
   
   proses adalah menukar digit pertama dengan digit ketiga.
   digit kedua karena tetap di tengah sehingga dibiarkan saja.
   
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

    char karakterSementara;
    // deklarasi variabel untuk menyimpan data satu karakter
    
    // Meminta pengguna memasukkan string angka 3 karakter
    cout << "Masukkan string bilangan (3 karakter): ";
    cin >> angka;

    // Menukar karakter pertama (indeks 0) dengan karakter terakhir (indeks 2)
    
    karakterSementara = angka[0]; 
    // Menyimpan sementara karakter pertama
    
    angka[0]          = angka[2];               
    // Karakter pertama diisi dengan karakter terakhir
    
    angka[2]          = karakterSementara;      
    // Karakter terakhir diisi dengan nilai sementara tadi

    // Menampilkan hasil string yang sudah dibalik
    cout << "String setelah dibalik: " << angka << endl;

    return 0; // Mengakhiri program dengan status sukses
}
