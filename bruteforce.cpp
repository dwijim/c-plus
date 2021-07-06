/* --------------------------------------
 * program brute force dibuat oleh kiki
 * mulai dibuat tanggal 1 april 2019
 * perbaikan program:
   - 4 Januari 2021 - dwi sakethi
   
 * program ini bernama bruteforce.cpp
   file ini membutuhkan dua buah file lain
   yaitu md5.cpp dan md5.h yang dapat diunduh di 
     http://www.zedwood.com/article/cpp-md5-function

   kompilasi:
     g++ bruteforce.cpp md5.cpp    
 * -------------------------------------- */

#include <iostream>
// karena ada perintah cout

#include "md5.h"
// karena menggunakan fungsi md5

#include "sstream"
// karena ada fungsi konversi int ke string

#include "string"
using namespace std;

#define JumlahKarakter 26

#include <ctime>



/* ---------------------------------------------------------
 * fungsi untuk menentukan huruf a, b, c, d, ... z
 * --------------------------------------------------------- */
 
string huruf_apa(short int huruf_ke)
{

  string SemuaHuruf = "abcdefghijklmnopqrstuvwxyz";
  string HurufNya;
  
  HurufNya = SemuaHuruf[huruf_ke-1];
  
  
  return HurufNya;
  
}

// program dalam bahasa C++ paling tidak
// terdiri dari satu fungsi yaitu fungsi main()
int main(){ 
  
	
	int jumlah_looping;
   // deklarasi variabel

   int DigitKe;
   
   string KataYangDicari;
   // kata yang akan ditebak, ini hasil enkripsinya
   
   string KataPenebak;
   // kata untuk menebak satu per satu
   
   string KataPenebakProses;
   // kata untuk menebak satu per satu
   
   string IntKeString;
   // string untuk konversi int ke string  
   string KataAsli; 
   
   short int jumlahdigit=16;
   short int digit01,digit02,digit03,digit04,digit05,digit06,digit07,digit08,
	     digit09,digit10,digit11,digit12,digit13,digit14,digit15,digit16;
   
   short int digitke,hurufke,awaldigit,digit;
   // string untuk huruf berdasarkan digit
    string huruf01,huruf02,huruf03,huruf04,huruf05,huruf06,huruf07,huruf08,huruf09,
	   huruf10,huruf11,huruf12,huruf13,huruf14,huruf15,huruf16;
	
	
   short int menu;

   	cout<<"Algoritma Brute Foce"<<endl<<endl;
   	cout<<"Masukkan Kata Yang Dicari (sudah dienkripsi): "<<endl;
   	cin>>KataYangDicari;
   	//untuk memasukkan kata yang dicari
   	
   	cout<<KataYangDicari<<endl<<endl;
   	//untuk menampilkan kata yang dicari
        KataPenebakProses = md5(KataYangDicari);
        KataPenebakProses = KataYangDicari;

   	cout << "\t1. Angka\n\t2. Huruf 1-4 \n\t3.Huruf 5-6 \n\t4. Huruf 7 ";
	cout << "\n\t5. Huruf 8 \n\t6. Huruf 9 \n\t7. Huruf 10";
	cout << "\n\t8. Huruf 11 \n\t9. Huruf 12 \n\t10. Huruf 13 \n\t11. Huruf 14"; 
        cout << "\n\t12. Huruf 15 \n\t13. Huruf 16 \n\t14. Keluar"<<endl;
   	cin>>menu;
   	//untuk memasukkan menu yang dipilih
	clock_t startTime = clock();
   	
   	switch(menu)

   	{
   		   	
	 case 1:

           // deklarasi jumlah digit kata
           jumlah_looping = 99999999;
  
           // melakukan looping 
           for(int i=1; i<=jumlah_looping; i++){
      
              IntKeString = to_string(i); 
              // string ini kemudian dienkripsi dengan md5
              // hasilnya dibandingkan dengan kata yang ditebak
              KataPenebak = md5(IntKeString);
              cout << IntKeString << " - " << KataPenebak<<" ??? "; 
              //merubah string ke dalam md5   
              cout<<KataPenebakProses<<endl; 

              //proses penebakan data
              if ( KataPenebak==KataPenebakProses) 
                 { 
                	cout<<KataPenebak<<" "<<endl;
                	cout<<" sukses ketebak: ";
	                cout<<IntKeString<<'-';
  	                cout<<""<<endl;
  	                cout<<"Waktu Running:";
  	                cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
  	                return 0;
                 }
       
           }   
           break;
      
case 2:       
    
    cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {
          case 1 :
          
            for (digit01=1;digit01<=JumlahKarakter;digit01++)
                {
                     huruf01 = huruf_apa(digit01);
                     KataPenebak=huruf01;
                     cout << KataPenebak <<" ";
    				 KataAsli= KataPenebak; 
			 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {
                                        
                    cout << endl;
            		cout<<" sukses ketebak: ";
				    cout<<KataAsli<<'-';
      				cout<<""<<endl;
    				cout<<"Waktu Running:";
  					cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; 
		}    
        			cout << endl;
                }       
				         
            break;
          case 2 :
          
            for (digit01=1;digit01<=JumlahKarakter;digit01++)
                {
                  for (digit02=1;digit02<=JumlahKarakter;digit02++)
                      {
                              huruf01 = huruf_apa(digit01);
                              huruf02 = huruf_apa(digit02);
                              KataPenebak=huruf01+huruf02;
                              cout << KataPenebak <<" ";
								KataAsli= KataPenebak;         
      							KataPenebak = md5(KataPenebak);     
			   		  if (KataPenebak==KataPenebakProses)
         				{
         				cout<<endl;
           				cout<<" sukses ketebak: ";
    					cout<<KataAsli<<'-';
						cout<<""<<endl;
    					cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	    return 0; }                          
                      }     
					            
                   cout << endl;
                }
            break;
            
          case 3 :
            for (digit01=1;digit01<=JumlahKarakter;digit01++)
                {
                  for (digit02=1;digit02<=JumlahKarakter;digit02++)
                      {
                        for (digit03=1;digit03<=JumlahKarakter;digit03++)
                            {
                              huruf01 = huruf_apa(digit01);
                              huruf02 = huruf_apa(digit02);
                              huruf03 = huruf_apa(digit03);
                              KataPenebak=huruf01+huruf02+huruf03;
                              cout << KataPenebak <<" ";        
							  KataAsli= KataPenebak;
                     
 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {
                                        
            cout << endl;
            cout<<" sukses ketebak: ";
    		cout<<KataAsli<<'-';  
    		cout<<""<<endl;      
    		cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0;
		 }                            
                            }                
                        cout << endl;
                      }
                    
                }
            break;
            break;
            
          case 4 :
            for (digit01=1;digit01<=JumlahKarakter;digit01++)
                {
                  for (digit02=1;digit02<=JumlahKarakter;digit02++)
                      {
                        for (digit03=1;digit03<=JumlahKarakter;digit03++)
                            {
                              for (digit04=1;digit04<=JumlahKarakter;digit04++)
                                  {
                                    huruf01 = huruf_apa(digit01);
                                    huruf02 = huruf_apa(digit02);
                                    huruf03 = huruf_apa(digit03);
                                    huruf04 = huruf_apa(digit04);
                                    KataPenebak=huruf01+huruf02+huruf03+huruf04;
                                    cout << KataPenebak <<" ";
          KataAsli= KataPenebak;
                     
 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {
                                        
            cout << endl;
            cout<<" sukses ketebak: ";
      		cout<<KataAsli<<'-';  
      		cout<<""<<endl;
    		cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; } 
                                  } 
                              cout << endl;
                            }                
                      }
                    
                }
            break;
            
				  break;
			
			}

		}
		break;
			
				  
case 3:
 

    cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {
    

		case 1:
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
										  	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05;
										  	cout << KataPenebak <<" ";
KataAsli= KataPenebak;
                     
 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {
                                        
            cout << endl;
            cout<<" sukses ketebak: ";
      		cout<<KataAsli<<'-';  
      		cout<<""<<endl;
    		cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; } 
										  }
										  cout << endl;
								  }
							  }
					  }
				  }
				  break;
		case 2:
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									for (digit06=1;digit06<=JumlahKarakter;digit06++)
          									{
											 
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
          									huruf06 = huruf_apa(digit06);
										  	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05+huruf06;
										  	cout << KataPenebak <<" ";
                 KataAsli= KataPenebak;
                     
 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {
                                        
            cout << endl;
            cout<<" sukses ketebak: ";
    		cout<<KataAsli<<'-';  
    		cout<<""<<endl;
    		cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; } 
										  }
										  cout << endl;
								  }
								  }
							  }
					  }
				  }
				  break;
				   break;	
				  }
				 
}
break;

case 4:

    cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {
         	
         				case 1 :
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									for (digit06=1;digit06<=JumlahKarakter;digit06++)
          									{
          										for (digit07=1;digit07<=JumlahKarakter;digit07++)
											 {
											 
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
          									huruf06 = huruf_apa(digit06);
          									huruf07 = huruf_apa(digit07);
										  	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05+huruf06+huruf07;
										  	cout << KataPenebak <<" ";
                 KataAsli= KataPenebak;
                     
 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {
                                        
                    cout << endl;
             cout<<" sukses ketebak: ";
      
      cout<<KataAsli<<'-';  
      cout<<""<<endl;
    cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; } 
										  }
										  cout << endl;
								  }
								  }
							  }
					  }}
				  }
				  break;
			}}
			break;
			
case 5:
	
	cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {
         	
         	case 1 :
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									for (digit06=1;digit06<=JumlahKarakter;digit06++)
          									{
          										for (digit07=1;digit07<=JumlahKarakter;digit07++)
											 {
											 	for (digit08=1;digit08<=JumlahKarakter;digit08++)
											 {
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
          									huruf06 = huruf_apa(digit06);
          									huruf07 = huruf_apa(digit07);
          									huruf08 = huruf_apa(digit08);
										  	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05+huruf06+huruf07+huruf08;
										  	cout << KataPenebak <<" ";
                 KataAsli= KataPenebak;
                     
 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {
                                        
                    cout << endl;
             cout<<" sukses ketebak: ";  
      cout<<KataAsli<<'-';
      cout<<""<<endl;
    cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; } 
										  }
										  cout << endl;
								  }
								  }
							  }
					  }}
				  }}
				  break;
			}
			break;
		}
		break;
case 6:
    cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {	
         	case 1:
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									for (digit06=1;digit06<=JumlahKarakter;digit06++)
          									{
          										for (digit07=1;digit07<=JumlahKarakter;digit07++)
											 {
											 	for (digit08=1;digit08<=JumlahKarakter;digit08++)
											 {
											 	for (digit09=1;digit09<=JumlahKarakter;digit09++)
											 	{
												 
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
          									huruf06 = huruf_apa(digit06);
          									huruf07 = huruf_apa(digit07);
          									huruf08 = huruf_apa(digit08);
          									huruf09 = huruf_apa(digit09);
										  	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05+huruf06+huruf07+huruf08+huruf09;
										  	cout << KataPenebak <<" ";
             KataAsli= KataPenebak;       
 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {
                                        
                    cout << endl;
             cout<<" sukses ketebak: ";
      cout<<KataAsli<<'-';  
      cout<<""<<endl;
    cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; }  }
										  cout << endl;
								  }
								  }
							  }
						}
					  }}
				  }}
				  break;
}}
break;

case 7:
	  cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {
         	case 1:
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									for (digit06=1;digit06<=JumlahKarakter;digit06++)
          									{
          										for (digit07=1;digit07<=JumlahKarakter;digit07++)
											 {
											 	for (digit08=1;digit08<=JumlahKarakter;digit08++)
											 {
											 	for (digit09=1;digit09<=JumlahKarakter;digit09++)
											 	{
											 		for (digit10=1;digit10<=JumlahKarakter;digit10++)
											 		{									 
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
          									huruf06 = huruf_apa(digit06);
          									huruf07 = huruf_apa(digit07);
          									huruf08 = huruf_apa(digit08);
          									huruf09 = huruf_apa(digit09);
          									huruf10 = huruf_apa(digit10);
										  	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05+huruf06+huruf07+huruf08+huruf09+huruf10;
										  	cout << KataPenebak <<" ";
                 KataAsli= KataPenebak;
                     
 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {
                                        
                    cout << endl;
             cout<<" sukses ketebak: ";  
    cout<<KataAsli<<'-';
    cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
      cout<<""<<endl;
        return 0; } 
										  }
										  cout << endl;
								  }
								  }
							  }
						}
					  }}}
				  }}
				  break;
			}
			break;
		}
		break;
	
	case 8:
    cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {
         	case 1 :
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									for (digit06=1;digit06<=JumlahKarakter;digit06++)
          									{
          										for (digit07=1;digit07<=JumlahKarakter;digit07++)
											 {
											 	for (digit08=1;digit08<=JumlahKarakter;digit08++)
											 {
											 	for (digit09=1;digit09<=JumlahKarakter;digit09++)
											 	{
											 		for (digit10=1;digit10<=JumlahKarakter;digit10++)
											 		{	
													 for (digit11=1;digit11<=JumlahKarakter;digit11++)		
													 {
																			 
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
          									huruf06 = huruf_apa(digit06);
          									huruf07 = huruf_apa(digit07);
          									huruf08 = huruf_apa(digit08);
          									huruf09 = huruf_apa(digit09);
          									huruf10 = huruf_apa(digit10);
          									huruf11 = huruf_apa(digit11);
										  	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05+huruf06+huruf07+huruf08+huruf09+huruf10+huruf11;
										  	cout << KataPenebak <<" ";
                 KataAsli= KataPenebak;
                     
 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {
                                        
                    cout << endl;
             cout<<" sukses ketebak: ";
      
      cout<<KataAsli<<'-';
      cout<<""<<endl;
    cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; } 
										  }
										  cout << endl;
								  }
								  }
							  }
						}
					  }}}}
				  }}
				  break;	  		
				  
			}
			break;
		}
		break;
		
case 9:
    cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {
		 			case 1 :
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									for (digit06=1;digit06<=JumlahKarakter;digit06++)
          									{
          										for (digit07=1;digit07<=JumlahKarakter;digit07++)
											 {
											 	for (digit08=1;digit08<=JumlahKarakter;digit08++)
											 {
											 	for (digit09=1;digit09<=JumlahKarakter;digit09++)
											 	{
											 		for (digit10=1;digit10<=JumlahKarakter;digit10++)
											 		{	
													 for (digit11=1;digit11<=JumlahKarakter;digit11++)		
													 {
													 	for (digit12=1;digit12<=JumlahKarakter;digit12++)
														{
																			 
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
          									huruf06 = huruf_apa(digit06);
          									huruf07 = huruf_apa(digit07);
          									huruf08 = huruf_apa(digit08);
          									huruf09 = huruf_apa(digit09);
          									huruf10 = huruf_apa(digit10);
          									huruf11 = huruf_apa(digit11);
          									huruf12 = huruf_apa(digit12);
										  	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05+huruf06+huruf07+huruf08+huruf09+huruf10+huruf11+huruf12;
										  	cout << KataPenebak <<" ";
                 KataAsli= KataPenebak;
                     
 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {
                                        
                    cout << endl;
             cout<<" sukses ketebak: ";  
      cout<<KataAsli<<'-';
      cout<<""<<endl;
    cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; } 
										  }
										  cout << endl;
								  }
								  }
							  }
						}
					  }}}}}
				  }}
				  break;
			}
			break;
		}
	break;
	case 10:
    cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {
         				case 1 :
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									for (digit06=1;digit06<=JumlahKarakter;digit06++)
          									{
          										for (digit07=1;digit07<=JumlahKarakter;digit07++)
											 {
											 	for (digit08=1;digit08<=JumlahKarakter;digit08++)
											 {
											 	for (digit09=1;digit09<=JumlahKarakter;digit09++)
											 	{
											 		for (digit10=1;digit10<=JumlahKarakter;digit10++)
											 		{	
													 for (digit11=1;digit11<=JumlahKarakter;digit11++)		
													 {
													 	for (digit12=1;digit12<=JumlahKarakter;digit12++)
														{
															for (digit13=1;digit13<=JumlahKarakter;digit13++)
															{
															
																			 
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
          									huruf06 = huruf_apa(digit06);
          									huruf07 = huruf_apa(digit07);
          									huruf08 = huruf_apa(digit08);
          									huruf09 = huruf_apa(digit09);
          									huruf10 = huruf_apa(digit10);
          									huruf11 = huruf_apa(digit11);
          									huruf12 = huruf_apa(digit12);
          									huruf13 = huruf_apa(digit13);
										  	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05+huruf06+huruf07+huruf08+huruf09+huruf10+huruf11+huruf12+huruf13;
                                  	  	cout << KataPenebak <<" ";
				KataAsli= KataPenebak;
                     
 		 KataPenebak = md5(KataPenebak);   
		  if (KataPenebak==KataPenebakProses)
         {                    
                    cout << endl;
             cout<<" sukses ketebak: ";  
      cout<<KataAsli<<'-';
      cout<<""<<endl;
    cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; } 
										  }
										  cout << endl;
								  }
								  }
							  }
						}}
					  }}}}}
				  }}
				  break;
}
break;
}
break;

	case 11:
    cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {
         				case 1 :
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									for (digit06=1;digit06<=JumlahKarakter;digit06++)
          									{
          										for (digit07=1;digit07<=JumlahKarakter;digit07++)
											 {
											 	for (digit08=1;digit08<=JumlahKarakter;digit08++)
											 {
											 	for (digit09=1;digit09<=JumlahKarakter;digit09++)
											 	{
											 		for (digit10=1;digit10<=JumlahKarakter;digit10++)
											 		{	
													 for (digit11=1;digit11<=JumlahKarakter;digit11++)		
													 {
													 	for (digit12=1;digit12<=JumlahKarakter;digit12++)
														{
															for (digit13=1;digit13<=JumlahKarakter;digit13++)
															{
																for (digit14=1;digit14<=JumlahKarakter;digit14++)
																{			 
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
          									huruf06 = huruf_apa(digit06);
          									huruf07 = huruf_apa(digit07);
          									huruf08 = huruf_apa(digit08);
          									huruf09 = huruf_apa(digit09);
          									huruf10 = huruf_apa(digit10);
          									huruf11 = huruf_apa(digit11);
          									huruf12 = huruf_apa(digit12);
          									huruf13 = huruf_apa(digit13);
          									huruf14 = huruf_apa(digit14);
	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05+huruf06+huruf07+huruf08+huruf09+huruf10+huruf11+huruf12+huruf13+huruf14;
                                  	 cout << KataPenebak <<" ";
                                  	 KataAsli=KataPenebak;
									    KataPenebak = md5(KataPenebak);
                                  	  		  if (KataPenebak==KataPenebakProses)
         {
             cout<<" sukses ketebak: ";  
      cout<<KataAsli<<'-';
      cout<<""<<endl;
    cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; } 
										  }
										  cout << endl;
								  }
								  }}
							  }
						}}
					  }}}}}
				  }}
				  break; 
				  }
				  break;
			}
break;			
			
case 12:
    cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {	
	case 1 :
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									for (digit06=1;digit06<=JumlahKarakter;digit06++)
          									{
          										for (digit07=1;digit07<=JumlahKarakter;digit07++)
											 {
											 	for (digit08=1;digit08<=JumlahKarakter;digit08++)
											 {
											 	for (digit09=1;digit09<=JumlahKarakter;digit09++)
											 	{
											 		for (digit10=1;digit10<=JumlahKarakter;digit10++)
											 		{	
													 for (digit11=1;digit11<=JumlahKarakter;digit11++)		
													 {
													 	for (digit12=1;digit12<=JumlahKarakter;digit12++)
														{
															for (digit13=1;digit13<=JumlahKarakter;digit13++)
															{
																for (digit14=1;digit14<=JumlahKarakter;digit14++)
																{
																for (digit15=1;digit15<=JumlahKarakter;digit15++)	 
																{
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
          									huruf06 = huruf_apa(digit06);
          									huruf07 = huruf_apa(digit07);
          									huruf08 = huruf_apa(digit08);
          									huruf09 = huruf_apa(digit09);
          									huruf10 = huruf_apa(digit10);
          									huruf11 = huruf_apa(digit11);
          									huruf12 = huruf_apa(digit12);
          									huruf13 = huruf_apa(digit13);
          									huruf14 = huruf_apa(digit14);
          									huruf15 = huruf_apa(digit15);
	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05+huruf06+huruf07+huruf08+huruf09+huruf10+huruf11+huruf12+huruf13+huruf14+huruf15;
                                  cout << KataPenebak <<" ";
                                  KataAsli=KataPenebak;
								   KataPenebak = md5(KataPenebak);
												  if (KataPenebak==KataPenebakProses)
         {
             cout<<" sukses ketebak: ";  
      cout<<KataAsli<<'-';
      cout<<""<<endl;
	cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
        return 0; }   }
										  cout << endl;
								  }
								  }}}
							  }
						}}
					  }}}}}
				  }}
				  break;}
				  break;}
	break;			  
				  
case 13:
    cout<<""<<endl; 
   
   for (digit=1;digit<=jumlahdigit;digit++)
   {
       
       switch (digit)
         {
		 case 1 :
          	for (digit01=1;digit01<=JumlahKarakter;digit01++)
          		{
          			for (digit02=1;digit02<=JumlahKarakter;digit02++)
          				{
          					for (digit03=1;digit03<=JumlahKarakter;digit03++)
          					{
          						for (digit04=1;digit04<=JumlahKarakter;digit04++)
          							{
          								for (digit05=1;digit05<=JumlahKarakter;digit05++)
          								{
          									for (digit06=1;digit06<=JumlahKarakter;digit06++)
          									{
          										for (digit07=1;digit07<=JumlahKarakter;digit07++)
											 {
											 	for (digit08=1;digit08<=JumlahKarakter;digit08++)
											 {
											 	for (digit09=1;digit09<=JumlahKarakter;digit09++)
											 	{
											 		for (digit10=1;digit10<=JumlahKarakter;digit10++)
											 		{	
													 for (digit11=1;digit11<=JumlahKarakter;digit11++)		
													 {
													 	for (digit12=1;digit12<=JumlahKarakter;digit12++)
														{
															for (digit13=1;digit13<=JumlahKarakter;digit13++)
															{
																for (digit14=1;digit14<=JumlahKarakter;digit14++)
																{
																for (digit15=1;digit15<=JumlahKarakter;digit15++)	 
																{
																	for (digit16=1;digit16<=JumlahKarakter;digit16++)
																	{
          									huruf01 = huruf_apa(digit01);
          									huruf02 = huruf_apa(digit02);
          									huruf03 = huruf_apa(digit03);
          									huruf04 = huruf_apa(digit04);
          									huruf05 = huruf_apa(digit05);
          									huruf06 = huruf_apa(digit06);
          									huruf07 = huruf_apa(digit07);
          									huruf08 = huruf_apa(digit08);
          									huruf09 = huruf_apa(digit09);
          									huruf10 = huruf_apa(digit10);
          									huruf11 = huruf_apa(digit11);
          									huruf12 = huruf_apa(digit12);
          									huruf13 = huruf_apa(digit13);
          									huruf14 = huruf_apa(digit14);
          									huruf15 = huruf_apa(digit15);
          									huruf16 = huruf_apa(digit16);
	KataPenebak=huruf01+huruf02+huruf03+huruf04+huruf05+huruf06+huruf07+huruf08+huruf09+huruf10+huruf11+huruf12+huruf13+huruf14+huruf15+huruf16;
                                cout << KataPenebak <<" ";
                                KataAsli=KataPenebak;
								  KataPenebak = md5(KataPenebak);
												  if (KataPenebak==KataPenebakProses)
         {
             cout<<" sukses ketebak: ";
      
      cout<<KataAsli<<'-';
      cout<<""<<endl;
     cout<<"Waktu Running:";
  	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	    return 0; }   }
										  cout << endl;
								  }
								  }}}
							  }
						}}
					  }}}}}}
				  }}
				  break;}
				  break;}
				  	
	case 14: 
	cout<<"Berhasil Keluar"<<endl;
	break;

          default :
            cout<<"Pilihan Tidak Ditemukan"<<endl;
            
            break;
   
    }

//cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
   return 0;
   
}
