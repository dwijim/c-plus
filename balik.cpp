#include <iostream>

using namespace std;

int  main() 
{

   int bilangan1;
   int bilangan2;
   int wadah;

   cout << "Masukan bilangan 1: ";
   cin >> bilangan1;

   cout << endl;

   cout << "Masukan bilangan 2: ";
   cin >> bilangan2;

   cout << endl;
   
   wadah = bilangan1;

   bilangan1 = bilangan2;

   bilangan2 = wadah;

   cout << "Bilangan 1 : " << bilangan1<<endl;

   cout << "Bilanan 2 : " << bilangan2<<endl;

   return 200;
}

