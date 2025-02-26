#include <iostream>
using namespace std;

int rekursi(int n);

int main () {
    int n;

    cout << "2 + 4 + 6 + 8 + 10 + ... +2n"<< endl;
    cout << "Masukkan jumlah n = ";
    cin >> n;

    //rekursi(n);
    cout << "Hasil penjumlahan deret adalah : " << rekursi(n);
}

int rekursi(int n){
    if ( n == 0) {
        return 0;
    } else {
        return 2*n + rekursi(n - 1);
    }
}
