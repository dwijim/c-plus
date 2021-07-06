
#include "iostream"

using namespace std;

int main(){

   int bilangan;
   int sisa;

   cout << "Masukkan suatu bilangan : ";
   cin >> bilangan;
cout << "\n";
    
   sisa = bilangan % 2;

   if (sisa==0)
      {
         cout << "bilangan genap \n";
      }
   else
      {
         cout << "bilangan ganjil \n";
      }


   return 999;
}
