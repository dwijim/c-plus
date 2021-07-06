

#include "iostream"

using namespace std;


int main(){

   int titik1, titik2, jarak;	
   
   cout << "Masukan Posisi titik #1: ";
   cin >> titik1;
   cout << "\n";


   cout << "Masukan posisi titik #2: ";
   cin >> titik2;
   cout << "\n";

   jarak = titik2 - titik1;

   if (jarak<0)
   {
      jarak = -jarak;
   }
   cout << "Jarak :" << jarak << "\n";

   return 17;

}
