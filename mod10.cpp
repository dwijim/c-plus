#include "iostream"

using namespace std;

int main()
{  int bilangan, sisa;
   cout << "Masukan bilangan :";
   cin >> bilangan;

   sisa = bilangan % 10;

   if ( (sisa==0) or
        (sisa==2) or
        (sisa==4) or
        (sisa==6) or
        (sisa==8)
      )
   {
      cout << "Bilangan genap \n";
   }
   else
   {
      cout << "Bilangan ganjil \n";
   }

   return 0;
}
