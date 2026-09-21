#include "iostream"
/* #include "string" */

using namespace std;

int main()
{
	short int baris, tulisan_ke;
	string tulisan;

   cout << "Tulisan yang akan dicetak : ";
   cin >> tulisan;

   cout << "Berapa baris : ";
   cin >> baris;

   for (tulisan_ke=1;tulisan_ke<=baris;tulisan_ke++)
   {
      cout << tulisan << "\n";
   }

   return 37;
}
