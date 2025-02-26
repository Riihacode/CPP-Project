#include <iostream>
using namespace std;

int rekursi(int n);

int main (){
    int n;

    cout << "S = 2 + 4 + 8 + 10 + ... + 2^n" << endl;
    cout << "Masukkan n = ";
    cin >> n;

    cout << "hasil dari penjumlahan deret adalah " << rekursi(n);
}

int rekursi(int n) {
    if (n == 1) {
        return 2;
    } else {
        return 2*rekursi(n - 1) + 2;
    }
}