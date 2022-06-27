#pragma once
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cstring>
/*list eror:
1. di bagian input kendaraan tidak bisa di inputkan string/huruf

*/
using namespace std;
#define MAX 10


struct pilihan{
    int depan, blkng;
    string pil[MAX];
}p;

struct kendaraan{
    string mobil[MAX],motor[MAX],bis[MAX];
    int jml_mobil,jml_motor,jml_bis;
}KNRDN;

int total_tarif=0;


struct Queue {
        int front, rear; 
        string data[MAX];
    }Q;

//memeriksa 
bool isFull() {
	return Q.rear == MAX;
    return p.blkng == MAX;
}

//cek apakah antrian kosong
bool isEmpty() {
	return Q.rear == 0;
    return p.blkng == MAX;
}

/*void sorting(){
     int i,n,j,xy;
    for (i=0;i<n;i++){
     j=i;
    for(int x=i+1;x<n;x++){
    xy=strcmp(Q.data[j],Q.data[x]);
    if(xy>0) {
    j=x;}
   }
   if (j!=i){
    swap(Q.data[j],Q.data[i]);
   }
  }
 }*/

void serching() {
	string temu;
	cout<<"ingin mencari kendaraan berplat mana:";
	cin>>temu;
	for(int i =Q.front; i <= Q.rear; i++) {
		if (Q.data[i].find(temu) != std::string::npos) {
			cout<<"kendaraan berada di nomor"<<i+1;
			getch();
		}
	}
}

//menampilkan queue daftar kendaraan
void tampil() {
	if (isEmpty()) {
    cout << "Parkiran kosong"<<endl;
	}
	else {
        cout<<"parkir motor"<<endl;
        
		for (int i = Q.front; i < Q.rear; i++){
        //pengecekan jika array kosong
            if (KNRDN.motor[i].empty()){
            }else{
		//menambahkan koma jika data tidak terdapat di antrian pertama 
		cout <<"parkir no"<<i+1<<"NoPLat : " << KNRDN.motor[i] << ((Q.rear-1 == i) ? "" : "\n" );
		cout << endl;
            }
        }
        
        cout<<"parkir mobil"<<endl;
        for (int i = Q.front; i < Q.rear; i++){
            if (KNRDN.mobil[i].empty()){
            }else{
		//menambahkan koma jika data tidak terdapat di antrian pertama 
			cout <<"parkir no"<<i+1<<"NoPLat : " << KNRDN.mobil[i] << ((Q.rear-1 == i) ? "" : "\n" );
		cout << endl;
        }
        }

        cout<<"parkir bis"<<endl;
        for (int i = Q.front; i < Q.rear; i++){
            if (KNRDN.bis[i].empty()){
            }else{
		//menambahkan koma jika data tidak terdapat di antrian pertama 
			cout <<"parkir no"<<i+1<<"NoPLat : " << KNRDN.bis[i] << ((Q.rear-1 == i) ? "" : "\n" );
		cout << endl;
        }
        }
  }
}

bool IsStringAllDigit(const string &str)
{
    //inisialisasi instansi dari iterator string
    string::const_iterator it = str.begin();
    //jika iterator bukan digit, maka hentikan loop
    while (it != str.end() && isdigit(*it))
        ++it;
    //mengembalikan kondisi apakah iterator sudah mencapai akhir
    return !str.empty() && it == str.end();
}

int StrToInt(string str)
{
    int isInt;
    stringstream ToInt(str);
    ToInt >> isInt;
    return isInt;
}

//fungsi enque
void input(){
    if (isFull())
    {
        cout<<"parkiran penuh!!!!";
    }else{
    system("cls");
    string data;
    int inputpil = 0;
    string pil = "";
    
    INPUT:
    cout<<"\n1.Motor (Rp. 2000)"<<endl;
    cout<<"2.Mobil (Rp. 5000)"<<endl;
    cout<<"3.Bus   (Rp. 10.000)"<<endl;
    cout<<"Masukan tipe kendaraan anda: ";
    cin >> pil;
    inputpil = StrToInt(pil);

    if ((inputpil > 0) && IsStringAllDigit(pil))
    {
        if (inputpil == 1)
        {
            //menambahkan data ke antrian
            cout << "Masukkan Plat Kendaraan : ";
            cin.get();
            getline(cin, data);
            KNRDN.motor[Q.rear] = data;
            Q.data[Q.rear] = data;
            //menempatkan tail pada elemen data terakhir yang ditambahkan
            Q.rear++;
            cout << "Motor ditambahkan\n";
            //menambahkan tarif
            total_tarif+=2000;
            KNRDN.jml_motor=Q.rear;
        }
        else if(inputpil == 2)
        {
            //menambahkan data ke antrian
            cout << "Masukkan Plat Kendaraan : ";
            cin.get();
            getline(cin, data);
            KNRDN.mobil[Q.rear] = data;
            Q.data[Q.rear] = data;
            //menempatkan tail pada elemen data terakhir yang ditambahkan
            Q.rear++;
            cout << "Mobil ditambahkan\n";
            total_tarif+=5000;
            KNRDN.jml_mobil=Q.rear;            
        }
        else if(inputpil == 3)
        {
            //menambahkan data ke antrian
            cout << "Masukkan Plat Kendaraan : ";
            cin.get();
            getline(cin, data);

            KNRDN.bis[Q.rear] = data;
            Q.data[Q.rear] = data;
            //menempatkan tail pada elemen data terakhir yang ditambahkan
            Q.rear++;
            cout << "Bus ditambahkan\n";
            total_tarif+=10000;
            KNRDN.jml_bis=Q.rear;            
        }
    }
    else
    {
        cout << "\nsilahkan masukkan angka yang sesuai yang ada dalam pilihan!!!" << endl;
        getch();
        system("cls");
        goto INPUT;
    }
}
}



// dequeue
void hapus() {
	if (isEmpty())
	{
		cout << "Parkiran masih kosong"<<endl;
	}
	else{

		cout << "Kendaraan ber NoPlat " << Q.data[Q.front] << " "<< "keluar" << endl;
		//menggeser antrian data ke head
		for (int i = Q.front; i < Q.rear; i++)
			Q.data[i] = Q.data[i + 1];
		//menempatkan tail pada data terakhir yang digeser
		Q.rear--;
		tampil();
	}
}

void Welcome()
{
    system("cls");
    cout << "\t=====================================================\n";
    cout << "\t|                                                   |\n";
    cout << "\t|            SELAMAT DATANG DI PARKIRAN             |\n";
    cout << "\t|                                                   |\n";
    cout << "\t=====================================================\n\n\n";
    cout << "\t\t  Tekan ENTER untuk melanjutkan...";
    cin.ignore();
}

void menu(){
    menu:
    int inputpil = 0;
    string pilihan = "";
    system("cls");

    cout << "\n+-----------------------------------------------------------------------------------+" << endl;
    cout << "+                             PROGRAM ANTRIAN KENDARAAN                             +" << endl;
    cout << "+-----------------------------------------------------------------------------------+" << endl; 
    cout << "+                                                                                   +" << endl;   
    cout << "+      1. Antrian Parkiran                                                          +" << endl;
    cout << "+      2. Keluarkan kendaraan                                                       +" << endl;
    cout << "+      3. Tampilkan parkiran                                                        +" << endl;
    cout << "+      4. Menghitung Total Pendapatan                                               +" << endl;
    cout << "+      5. mencari kendaraan                                                         +" << endl;
    cout << "+      0. Exit                                                                      +" << endl;
    cout << "+                                                                                   +" << endl; 
    cout << "+-----------------------------------------------------------------------------------+\n\n" << endl;
    cout << "Masukan Pilihan Anda : "; 
    cin >> pilihan;

    inputpil = StrToInt(pilihan);
    if ((inputpil >= 0) && IsStringAllDigit(pilihan))
    {
        if (inputpil == 1)
        {
            input();
            getch();
            system("cls");
            goto menu;
        }

        else if (inputpil == 2)
        {
            hapus();
            getch();
            system("cls");
            goto menu;
        }

        else if (inputpil == 3)
        {
            tampil();
            getch();
            system("cls");
            goto menu;
        }
        
        else if(inputpil==4){
            cout<<"total pendapatan: "<<total_tarif;
            getch();
            system("cls");
            goto menu;
        }

        else if(inputpil==5){
            serching();
            getch();
            system("cls");
            goto menu;
        }
        else if (inputpil == 0)
        {
            cout<<"terima kasih telah menggunakan progam ini :) \n";
            getch();
            system("cls");
        }
    }
    else
    {
        cout << "Masukan pilihan dengan benar!!!";
        getch();
        system("cls");
        goto menu;
    }
       
}
