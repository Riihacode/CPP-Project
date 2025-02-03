#include <iostream>
using namespace std;
int main(){
    int nomor, angka;
    char nama;
    cout << "Nomor  = "; cin>> nomor; // 1 angka nim terakhir anda
    cout << "Nama   = "; cin>> nama; // 1 karakter lower case awal nama anda
    angka = (nomor+1)*100%2;
    switch (angka)
    {
    case 1:
        if (nomor >= 5 && nama >= 'p')
            nomor = (angka + nomor)+nomor/2+1;
        else nomor = (angka+nomor)-nomor/2+2;
        angka = (angka+1)*2+nomor;
        break;
    case 0:
        if (nomor <= 4 && nama >= 'j')
            angka = (angka + nomor)+nomor/2+1;
        else angka = (angka+nomor)-nomor/2+2;
        nomor = (angka+1)*2+nomor;
        break;
    default:
        nomor = (angka+nomor)+nomor;
        angka = (angka+1)*2+nomor; 
        break;
    }
    if (angka>5) cout <<"Hasil  = "<<angka;
    else cout<<"Hasil   = "<< nomor;
}