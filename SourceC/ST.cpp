#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include "unistd.h"
#include <string> 

using namespace std;

int main()
    {
    	 	  string str = "shutdown -s -t "; //Const olarak çevrilecek string deðiþkenini tanýmla, komut ekranýnda kapatma iþlemi için.
              int shutdowntime=0, isCancel=0; // Kullanýcýdan kapatma zamaný al / Kullanýcý kapatma iþlemini iptal etmek isterse deðer girmesi için deðiþken tanýmla
              bool itsokay=false; // Bool tipinde deðiþken tanýmla, girilen deðer uygunsa true deðerini döndür if yapýsýna dallan, girilen deðer uygun deðilse false deðerini döndür ve tekrar sayý almaya dallan
              tekrar: 
              	shutdowntime = 0; // deðerleri sýfýrla
              	isCancel=0; // deðerleri sýfýrla
			  cout<< "kac saniye sonra kapatilsin?"<<endl; //<< yazdýr
              cin>>shutdowntime; // veriyi al
              
			  if(shutdowntime>0 && shutdowntime<=60) // alýnan veri uygunsa
			  itsokay = true; // bool deðerini true yap
             
			  else //deðilse
			  {
			  	itsokay=false; // bool deðerini false yap
                cout<<"Girilen sayi 0 ve 60 arasinda olmalidir"<<endl; // << yazdýr
                goto tekrar; // tekrar noktasýna dallan
				}
				
				if(itsokay == true){ // bool deðeri true ise
					str = "shutdown -s -t "; // önceki verileri temizle
					stringstream ss; 
					ss << shutdowntime; // int verisini string tipindeki deðiþkene aktar
					//cout<<endl<<ss.str(); - bu kýsýmýn yorum satýrý kaldýrýlýrsa, deðiþkenin veri kontrolü yapýlabilir -
					
					str = str + ss.str();	// int (kullanýcýdan alýnan zaman deðeri verisini) içerisindeki verileri string içerisindeki veri ile birleþtir (shutdown -s -t XX)
					 const char *command = str.c_str(); // str deðiþkenini consta çevir
					cout<<"Sistem " << shutdowntime << " saniye icerisinde kapatilacak!" << endl; // << yazdýr
                    sleep(1); // bir saniye bekle
                   //cout<<endl<<command; - bu kýsýmýn yorum satýrý kaldýrýlýrsa, sisteme gönderilecek verinin kontrolü konsol üzerinde yapýlabilir -
				   system(command); // sisteme command içerisindeki veriyi gönder
				   }
				else{ // herhangi bir problem çýkarsa
				
				cout<<"bugwashere"; // <<yazdýr
				goto tekrar; // tekrar noktasýna dallan
               }
               
                cout<<endl<<"iptal etmek icin 1 tusuna basiniz"<<endl; // << yazdýr
				   cin>>isCancel; // veriyi al
				   if(isCancel == 1) // eðer kullanýcý 1 verisini döndürürse
				   {
				   	system("shutdown /a"); // týrnak içerisindeki veriyi sisteme göndererek kapatmayý iptal et
				   	cout<<"Kapatma islemi iptal edildi"<<endl; // << yazdýr
				   	goto tekrar; // tekrar noktasýna dallan
				   }
				   else{ // isCancel 1 harici bir deðer alýrsa
				   	cout<<"kapatiliyor..."; // << yazdýr
				   }
                   return 0;
    }
 

