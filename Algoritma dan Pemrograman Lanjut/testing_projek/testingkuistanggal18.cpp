#include <iostream>
using namespace std;

void tampil(int a);
main()
{ 
    int a;
    cout<<"masukkan a = "; cin>>a;
    //masukkan digit terakhir NIM Anda
    if (a>=7) a=a-1;
    if (a<=3) a=a+3;
    tampil(a);
}
void tampil(int a)
{
    if(a==1) {
        cout<<endl<<"*";
    }
    else { 
        cout<<a;
        tampil(a-1);
        cout<<a;
    }
}

/*
void inverseMatrix(
    float valueA, 
    float valueB, 
    float valueC, 
    float valueD
) {
    float determinan = valueA * valueD - valueB * valueC;
    
    if (determinan == 0) {
        cout << "Matrix tidak punya invers karena determinan = 0" << endl;
        return;
    }
    
    float valueNowA = valueA / determinan;
    float valueNowB = -valueB / determinan;
    float valueNowC = -valueC / determinan;
    float valueNowD = valueD / determinan;

    cout << "Invers matriks A adalah:\n";
    cout << valueNowD << "  " << valueNowB << endl;
    cout << valueNowC << "  " << valueNowA << endl;
}

int main() {
    float nilaiA, nilaiB, nilaiC, nilaiD;
    cout << "Masukkan elemen matrix A (2x2):\n";
    cout << "Masukkan nilai A   : ";
    cin >> nilaiA; 
    cout << "Masukkan nilai B   : ";
    cin >> nilaiB; 
    cout << "Masukkan nilai C   : ";
    cin >> nilaiC; 
    cout << "Masukkan nilai D   : ";
    cin>> nilaiD;
    
    inverseMatrix(nilaiA, nilaiB, nilaiC, nilaiD);
    
    return 0;
}

struct DateOrder{
    int hari;
    string bulan;
    int tahun;
};

struct CustomerOrder{
    DateOrder tanggalOrder;
    int nomorOrder;
    int subTotal;
    int discount;
    int total;
};

struct Customer{
    string nama;
    string alamat;
    string kota;
    string nomorTelepon;
};

struct Invoice{
    Customer customer;
    CustomerOrder customerorder;
    int nomorInvoice;
};*/