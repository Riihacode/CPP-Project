// Tipe array nama_array[baris][kolom];  // Basicnya


/////////////////////////////////////////////////////////////
// Contoh Program 1.1
/*
#include <iostream>
using namespace std;

void printArray(int a[][3]);

int main () {
    int matrik1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrik2[2][3] = {{1, 2, 3}, {4, 5}};  // Pastikan semua elemen terisi
    int matrik3[2][3] = {{1, 2}, {4}};  // Sama seperti di atas

    printArray(matrik1);
    printArray(matrik2);
    printArray(matrik3);
    return 0;
}


void printArray(int a[][3]) {
    int i, j;

    for (i = 0; i <= 1; i++) {
        for (j = 0; j <= 2; j++) {
            cout << a[i][j] << " ";
        }
        cout<< endl;
    }
    cout << endl;
}
*/

//versi perbaikan ############################
/*
#include <iostream>
using namespace std;

// Fungsi untuk mencetak array 2D
void printArray(int a[][3]);

int main() {
    int matrik1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int matrik2[2][3] = {{1, 2, 3}, {4, 5, 0}};  // Pastikan semua elemen terisi
    int matrik3[2][3] = {{1, 2, 0}, {4, 0, 0}};  // Sama seperti di atas

    printArray(matrik1);
    printArray(matrik2);
    printArray(matrik3);

    return 0;
}

// Implementasi fungsi printArray
void printArray(int a[][3]) {
    int i, j;

    for (i = 0; i <= 1; i++) {  // Loop baris
        for (j = 0; j <= 2; j++) {  // Loop kolom
            cout << a[i][j] << " ";  // Cetak elemen di baris yang sama
        }
        cout << endl;  // Pindah ke baris baru setelah cetak 1 baris
    }
    cout << endl;  // Pindah baris setelah mencetak 1 matriks
}
*/

// Contoh Program 1.2
/*
#include <iostream>
using namespace std;

int main () {
    int baris, kolom, matriks[3][4];

    // input elemen array secara Row Major Order
    cout << "Input elemen Array : \n";
    for (baris = 0; baris < 3; baris++ ) {
        for (kolom = 0; kolom < 4; kolom++) {
            cout << "matriks["<<baris + 1 << "][" << kolom + 1 << "] = ";
            cin >> matriks[baris][kolom];
        }
        cout << endl;
    }

    // Tampilkan elemen Array secar Row Major Order
    cout << "Isi array : \n";
    for (baris = 0; baris < 3; baris++) {
        for (kolom = 0; kolom < 4; kolom++) {
            cout << " "<< matriks[baris][kolom];
        }
        cout << endl;
    }
}
*/

/////////////////////////////////////////////////////
// Program penjumlahan matriks dua dimensi
/*
#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
    int A[3][4],
    B[3][4],
    X[3][4],
    Y[3][4],
    i,
    j;

    // Masukkan matriks A
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++){
            cout << "input data matrik A[" << i + 1 <<"] [" << j+1 << "] : ";
            fflush(stdin); cin >> A[i][j];
        }    
        cout << endl;
    }
    cout << endl;        

    // Masukan matriks B
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++){
            cout << "input data matrik B[" << i + 1 <<"] ["<< j+1 << "] : ";
            fflush(stdin); cin >> B[i][j];
        }    
        cout << endl;
    }
    cout << endl;            

    // Proses penjumlahan matriks A dan B
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            X[i][j] = A[i][j] + B[i][j];
        }
    }

    // Cetak isi matriks A
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            cout<< " " << A[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // Cetak isi matriks B
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            cout<< " " << B[i][j];
        }
        cout << endl;
    }
    cout << endl;

    // Cetak hasil penjumlahan matriks A dan B
    cout << "\n Matriks Penjumlahan A dan B \n";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            cout<<" "<<X[i][j]; 
        }
        cout << endl;
    }
    cout<< endl;
}
*/

// Versi yang sudah disempurnakan
#include <iostream>
using namespace std;

void inputMatrix(int matrix[3][4], char name);
void printMatrix(int matrix[3][4], const string& title);
void addMatrices(int A[3][4], int B[3][4], int result[3][4]);

int main () {
    int A[3][4],
    B[3][4],
    X[3][4];

    // input data matrix
    inputMatrix(A, 'A');
    inputMatrix(B, 'B');

    // penjumlahan data matriks A dan B
    addMatrices(A, B, X);

    // print data matrix
    printMatrix(A, "Matrix A: ");
    printMatrix(B, "Matrix B: ");

    // cetak hasil
    printMatrix(X, "Matrix X: ");
}

void inputMatrix(int matrix[3][4], char name){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++){
            cout << "input data matrik "<< name << "[" << i + 1 <<"] [" << j+1 << "] : ";
            cin >> matrix[i][j];
        }    
        cout << endl;
    }
    cout << endl;
}

void printMatrix(int matrix[3][4], const string& title){
    cout << title << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout<< " " << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void addMatrices(int A[3][4], int B[3][4], int result[3][4]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}