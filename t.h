#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

using namespace std;
#define MAX 100


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

//menampilkan queue daftar kendaraan
void tampil() {
	if (isEmpty()) {
    cout << "Parkiran kosong"<<endl;
	}
	else {
        cout<<"parkir motor"<<endl;
		for (int i = Q.front; i < Q.rear; i++){
		//menambahkan koma jika data tidak terdapat di antrian pertama 

			cout <<"NoPLat : " << KNRDN.motor[i] << ((Q.rear-1 == i) ? "" : "\n" );
		cout << endl;
        }
        cout<<"parkir mobil"<<endl;
        for (int i = Q.front; i < Q.rear; i++){
		//menambahkan koma jika data tidak terdapat di antrian pertama 

			cout <<"NoPLat : " << KNRDN.mobil[i] << ((Q.rear-1 == i) ? "" : "\n" );
		cout << endl;
        }
        cout<<"parkir bis"<<endl;
        for (int i = Q.front; i < Q.rear; i++){
		//menambahkan koma jika data tidak terdapat di antrian pertama 

			cout <<"NoPLat : " << KNRDN.bis[i] << ((Q.rear-1 == i) ? "" : "\n" );
		cout << endl;
        }
  }
}

void antrian(){
    menu:
    string data;
    int pil;

    cout<<"1.Motor (Rp. 2000)"<<endl;
    cout<<"2.Mobil (Rp. 5000)"<<endl;
    cout<<"3.Bus (Rp. 10.000)"<<endl;
    cout<<"masukan pilihan kendaraan:"<<endl;
    cin >> pil;

    switch (pil)
    {
    case 1:
        //menambahkan data ke antrian
        cout << "Masukkan Plat Kendaraan : ";
        cin.get();
        getline(cin, data);
        KNRDN.motor[Q.rear] = data;
        Q.data[Q.rear] = data;
        //menempatkan tail pada elemen data terakhir yang ditambahkan
        Q.rear++;
        cout << "Motor ditambahkan\n";
        total_tarif+=2000;
        KNRDN.jml_motor=Q.rear;
        break;
        
    case 2:
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
        break;
    case 3:
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
        break;
    default:
        //menambahkan data ke antrian
        cout<<"masukan angka yang benar"<<endl;
        break;

    }

}

// dequeue
void hapus() {
	if (isEmpty())
	{
		cout << "Parkiran masih kosong"<<endl;
	}
	else{

		cout << "Kendaraan ber NoPlat" << Q.data[Q.front] << ""<< "keluar" << endl;
		//menggeser antrian data ke head
		for (int i = Q.front; i < Q.rear; i++)
			Q.data[i] = Q.data[i + 1];
		//menempatkan tail pada data terakhir yang digeser
		Q.rear--;
		tampil();
	}
}


void menu(){
    menu:

    system("cls");
    int pilihan;
    cout << "\n+-----------------------------------------------------------------------------------+" << endl;
    cout << "+                             PROGRAM ANTRIAN KENDARAAN                             +" << endl;
    cout << "+-----------------------------------------------------------------------------------+" << endl; 
    cout << "+                                                                                   +" << endl;   
    cout << "+      1. Antrian Parkiran                                                          +" << endl;
    cout << "+      2. Keluarkan Mobil                                                           +" << endl;
    cout << "+      3. Tampilkan Antrian Mobil                                                   +" << endl;
    cout << "+      4. Menghitung Total Pendapatan                                               +" << endl;
    cout << "+      0. Exit                                                                      +" << endl;
    cout << "+                                                                                   +" << endl; 
    cout << "+-----------------------------------------------------------------------------------+\n\n" << endl;
    cout << "Masukan Pilihan Anda : "; 
    cin >> pilihan;

    if (pilihan == 1)
    {
        antrian();
        getch();
        system("cls");
        goto menu;
    }

    else if (pilihan == 2)
    {
        hapus();
        getch();
        system("cls");
        goto menu;
    }

    else if (pilihan == 3)
    {
        tampil();
        getch();
        system("cls");
        goto menu;
    }
    
    else if(pilihan==4){
        cout<<"total pendapatan:"<<total_tarif;
        getch();
        system("cls");
        goto menu;
    }
    
    else if (pilihan == 0)
    {
        cout<<"terima kasih telah menggunakan progam ini :) \n";
        getch();
        return;
    }
    else
    {
        cout << "Masukan pilihan dengan benar!!!";
        getch();
        system("cls");
        goto menu;
    }
       
}
