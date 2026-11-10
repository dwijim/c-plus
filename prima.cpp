/* ---------------------------------------
   program untuk menentukan bilangan prima
   dibuat menggunakan bahasa C++
   mulai ditulis pada hari Selasa, 26 Oktober 2021
   dwi sakethi

   --------------------------------------- */

// karena di dalam program ada perintah cin cout
#include "iostream"

// sebenarnya tidak disarankan, mempermudah penulisan program
using namespace std;


// program dalam bahasa C++ minimal terdiri dari satu fungsi
// yaitu fungsi main()
int main(){

  int bilangan,cek,sisa;
  bool prima;

  cout << "Program Bilangan Prima\n\n";

  cout << "Masukan suatu bilangan: ";
  cin>>bilangan;

  cout << bilangan<< "\n";;

  // diasumsikan bilangan prima
  prima = true;

  for (cek=2;cek<bilangan;cek++)
  {

    // cout << cek << "\n";
    sisa = bilangan % cek;
    if (sisa==0)
    {
      // cout << cek << " Pembagi \n";
      prima = false;
      break;
    }
  }

  // cek hasil
  if (prima==true)
  {
    cout << "Bilangan prima\n";

  }
  else
  {
    cout << "Bukan bilangan prima\n";

  }
  // hasil fungsi main
  return 46;
}
