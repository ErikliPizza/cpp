#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include "unistd.h"
#include <string> 

using namespace std;

int main()
    {
    	 	  string str = "shutdown -s -t "; //Const olarak �evrilecek string de�i�kenini tan�mla, komut ekran�nda kapatma i�lemi i�in.
              int shutdowntime=0, isCancel=0; // Kullan�c�dan kapatma zaman� al / Kullan�c� kapatma i�lemini iptal etmek isterse de�er girmesi i�in de�i�ken tan�mla
              bool itsokay=false; // Bool tipinde de�i�ken tan�mla, girilen de�er uygunsa true de�erini d�nd�r if yap�s�na dallan, girilen de�er uygun de�ilse false de�erini d�nd�r ve tekrar say� almaya dallan
              tekrar: 
              	shutdowntime = 0; // de�erleri s�f�rla
              	isCancel=0; // de�erleri s�f�rla
			  cout<< "kac saniye sonra kapatilsin?"<<endl; //<< yazd�r
              cin>>shutdowntime; // veriyi al
              
			  if(shutdowntime>0 && shutdowntime<=60) // al�nan veri uygunsa
			  itsokay = true; // bool de�erini true yap
             
			  else //de�ilse
			  {
			  	itsokay=false; // bool de�erini false yap
                cout<<"Girilen sayi 0 ve 60 arasinda olmalidir"<<endl; // << yazd�r
                goto tekrar; // tekrar noktas�na dallan
				}
				
				if(itsokay == true){ // bool de�eri true ise
					str = "shutdown -s -t "; // �nceki verileri temizle
					stringstream ss; 
					ss << shutdowntime; // int verisini string tipindeki de�i�kene aktar
					//cout<<endl<<ss.str(); - bu k�s�m�n yorum sat�r� kald�r�l�rsa, de�i�kenin veri kontrol� yap�labilir -
					
					str = str + ss.str();	// int (kullan�c�dan al�nan zaman de�eri verisini) i�erisindeki verileri string i�erisindeki veri ile birle�tir (shutdown -s -t XX)
					 const char *command = str.c_str(); // str de�i�kenini consta �evir
					cout<<"Sistem " << shutdowntime << " saniye icerisinde kapatilacak!" << endl; // << yazd�r
                    sleep(1); // bir saniye bekle
                   //cout<<endl<<command; - bu k�s�m�n yorum sat�r� kald�r�l�rsa, sisteme g�nderilecek verinin kontrol� konsol �zerinde yap�labilir -
				   system(command); // sisteme command i�erisindeki veriyi g�nder
				   }
				else{ // herhangi bir problem ��karsa
				
				cout<<"bugwashere"; // <<yazd�r
				goto tekrar; // tekrar noktas�na dallan
               }
               
                cout<<endl<<"iptal etmek icin 1 tusuna basiniz"<<endl; // << yazd�r
				   cin>>isCancel; // veriyi al
				   if(isCancel == 1) // e�er kullan�c� 1 verisini d�nd�r�rse
				   {
				   	system("shutdown /a"); // t�rnak i�erisindeki veriyi sisteme g�ndererek kapatmay� iptal et
				   	cout<<"Kapatma islemi iptal edildi"<<endl; // << yazd�r
				   	goto tekrar; // tekrar noktas�na dallan
				   }
				   else{ // isCancel 1 harici bir de�er al�rsa
				   	cout<<"kapatiliyor..."; // << yazd�r
				   }
                   return 0;
    }
 

