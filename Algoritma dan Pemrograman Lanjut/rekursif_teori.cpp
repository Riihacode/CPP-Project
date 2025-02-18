#include <iostream>

using namespace std;

/////////////////////////////////////////////////////
// Bilangang Fibonacci
int A(int x);

int main () 
{
    cout << A(7);

}

int A(int x) {
    if (x<= 2) {
        return x;
    } else {
        return (2*A(x-2)+A(x-3));
    }
}

/*
void soal(int x);

int main () {
    int nim ;
    cout << "Angka tiga digit nterakhir nim = ";
    cin >> nim;
    if
} 

void soal(int x) {
    if (x>0){
        soal(x-1);
        cout << endl;
        soal(x-1);
    }
}
*/


///////////////////////////////////////////////////////
/*
int fib(int n);

int main () {
    int x = fib(10);
    cout << x;
}

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n-1) + fib (n-2);
    }
}
*/


////////////////////////////////////////////
/*
void A(int x);

int main ()
{
    A(10);   
}

void A(int x) {
    if (x <= 6 && x >= 0) {
        cout << "x ke-"<<x<<": Permen \n";
        A(x-2);
    } else {
        A(x-2);
    }
}
*/


////////////////////////////////////////////////////////////////////
/*
int main () {
    int i, p , q, n, tanda;
    float S, x;

    i = 1;
    S = 0;

    while(i <=n){
        cout << i;
        S = S+i;
        i = i+1;
    }

    cout << S;
}
    */