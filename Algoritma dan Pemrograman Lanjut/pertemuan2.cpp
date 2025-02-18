#include <iostream>
//#include <bits/stdc++.h> yang dipraktikum make ini

using namespace std;

int deretBilangan(int n);

int main () {
    int bilangan;
    cout << "Anda ingin mengetahui bilangan ke berapa? ";
    cin >> bilangan;    //5

    cout <<"Bilangan ke-"<<bilangan<< " : "<<deretBilangan(bilangan);

}

int deretBilangan(int n){
    if (n == 1) {
        return 1;
    } else {
        return deretBilangan(n - 1) + 2;
    }

    /*
    int nilaiBilangan = 0;
    int nilai;
    */

    /*
    if (n <= 0) {
        return 1;
    } else {
        return n;
    }
        */
       /*
    for (int i = 0; i < n; i++) {
        //nilai = i+2;
        nilaiBilangan = nilaiBilangan + 1;
    }

    return nilaiBilangan;
    */
   
}


/*
int fibonacci(int n);

int main () {
    int fibo;
    cout << "Masukkan sebuah bilangan = " ;
    cin >> fibo;
    cout << "Bilangan fibonacci ke-"<<fibo << " adalah " << fibonacci(fibo) << endl;
    cout << "daftar bilangan fibo : " << endl;
    for (int i = 1; i <= fibo; i++) {
        cout << fibonacci(i) << " ";
    }

    cout << "\n///////////////////////////"<<endl;

    fibonacci(fibo);
}

int fibonacci(int n) {
    int kembalikanNilai;

    // Base case
    if (n == 1 || n == 2) {
        kembalikanNilai = 1;
        cout << "fibonacci(" << n << ") mengembalikan: " << kembalikanNilai << endl; // Debugging
        return kembalikanNilai;
    } 
    // Recursive case
    else {
        kembalikanNilai = fibonacci(n - 1) + fibonacci(n - 2);
        cout << "fibonacci(" << n << ") mengembalikan: " << kembalikanNilai << endl; // Debugging
        return kembalikanNilai;
    }
}
*/

/*
int fibonacci(int n){
    int kembalikanNilai;

    if ((n == 1) || (n == 2) ) {
        kembalikanNilai = 1;
        cout << kembalikanNilai<< "   ";
        return kembalikanNilai;
    } else {
        kembalikanNilai = ((fibonacci(n-1) + fibonacci(n-2)));
        cout << kembalikanNilai << "   ";
        return kembalikanNilai;
    }
}
    */

/*
int fibonacci(int n){
    if ((n == 1) || (n == 2) ) {
        return 1;
    } else {
        return ((fibonacci(n-1) + fibonacci(n-2)));
    }
}
*/



/*
///////////////////////////////////////////////////////////
// rekursif
int rekursif(int n);

int main () {
    int angka;

    cout << "Masukkan bilangan rekursif = ";
    cin >> angka;
    // cout << "Hasil rekursf dari " << angka << "adalah" << rekursif(angka);
    cout << "Hasil rekursif dari " << angka << "adalah : ";
    for (int i = angka; i >= 1; i--){
        cout << i << " ";
    }
    cout << " = " << rekursif(angka) << endl;
}

int rekursif(int n){
    if (n <= 1) {
        return 1;
    } else {
        return n * rekursif(n-1);
    }
}
*/



/*
//////////////////////////////////////////
// Program Faktorial
int faktorial(int a);

int main () {
    int n;
    cout << "Masukkan bilangan  : ";
    cin >> n;
    cout << "Faktorial "<< n << " = " << faktorial(n)<< endl;
}

int faktorial(int a){
    int hasil;
    if (a <= 1) {
        hasil = 1;
    } else {
        hasil = a*faktorial(a-1);

    }

    return hasil;
}
*/

/*
//////////////////////////////////////////
// Program FPB
int FPB(int x, int y);

int main () {
    int bil1, bil2;
    cout << "Masukkan bilangan pertama      = ";
    cin  >> bil1;
    cout << "Masukkan bilangan kedua        = ";
    cin >> bil2;
    cout << "Faktor Persekutuan Terbesar    = "<<FPB(bil1, bil2)<< endl;   
}

int FPB(int x, int y) {
    float hasil;
    if (y == 0) {
        hasil = x;
    } else {
        hasil = FPB(x, (x%y));
        cout << "Nilai x = " << x << " & Nilai y = "<<y<<endl;
    }

    return hasil;
}
*/