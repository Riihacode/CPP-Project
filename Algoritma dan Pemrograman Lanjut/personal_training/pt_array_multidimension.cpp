// #####################################
// array 3d / multidimensi
#include <iostream>
using namespace std;

int  main() {
    int data[2][3][4];
    int dataTest[2][2][2] = {
        { {1, 2}, {3, 4} },
        { {5, 6}, {7, 8} }
    };
    int dataCube[2][2][2];

    cout << dataTest[1][0][1];

    // input
    for(int i = 0; i < sizeof(dataCube[0][0]) / sizeof(dataCube[0][0][0]); i++ ){
        cout << "Block - " << i << endl;
        for (int j = 0; j < sizeof(dataCube[0]) / sizeof(dataCube[0][0]); j++) {
            cout << "Row - " << j << endl;
            for (int k = 0; k < sizeof(dataCube) / sizeof(dataCube[0]); k++ ) {
                cout << "Coloumn - "<< k << ": ";
                cin >> dataCube[i][j][k];
            }
        }
    }

    // output 
    for (int i = 0; i < sizeof(dataCube[0][0]) / sizeof(dataCube[0][0][0]); i++) {
        for (int j = 0; j < sizeof(dataCube[0]) / sizeof(dataCube[0][0]); j++ ) {
            for (int k = 0; k < sizeof(dataCube) / sizeof(dataCube[0]); k++) {
                cout << dataCube[i][j][k] << " ";
            }
        }
    }

    cout << endl << endl;

    // edit
    for (int i = 0; i < sizeof(dataCube[0][0]) / sizeof(dataCube[0][0][0]); i++) {
        for (int j = 0; j < sizeof(dataCube[0]) / sizeof(dataCube[0][0]); j++ ) {
            for (int k = 0; k < sizeof(dataCube) / sizeof(dataCube[0]); k++) {
                int changeIndexValue;

                cout << "Input to change index value (value of each coloumn): ";
                cin >> changeIndexValue;
                dataCube[i][j][k] = changeIndexValue;
            }
        }
    }

    // output 
    for (int i = 0; i < sizeof(dataCube[0][0]) / sizeof(dataCube[0][0][0]); i++) {
        for (int j = 0; j < sizeof(dataCube[0]) / sizeof(dataCube[0][0]); j++ ) {
            for (int k = 0; k < sizeof(dataCube) / sizeof(dataCube[0]); k++) {
                cout << dataCube[i][j][k] << " ";
            }
        }
    }
}


/*
// Array 2 dimensi
#include <iostream>
using namespace std;

int main() {
    int matrix[2][3];

    // input 
    for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++) {
        cout << "Row - " << i << endl;
        for (int j = 0; j < sizeof(matrix[0]) / sizeof(matrix[0][0]); j++) {
            cin >> matrix[i][j];
        }
    }

    // output
    for (int i = 0; i < sizeof(matrix) / sizeof(matrix[0]); i++) {
        for (int j = 0; j < sizeof(matrix[0]) / sizeof(matrix[0][0]); j++) {
            cout << matrix[i][j] << " ";
        }
    }
}
*/


//////////////////////////////////////
// Array dasar
/*
#include <iostream>
using namespace std;

int main() {
    int number[5];
    int numberTest1[3] = {2, 3, 5};
    int length = sizeof(number) / sizeof(number[0]);

    cout << sizeof(numberTest1) / sizeof(numberTest1[0]) << endl;

    int inputNumber;

    for (int i = 0; i <  length; i++){
        cout << i + 1 << ". Input number = ";
        cin >> number[i];
    }

    cout << number[1] << endl;
    cout << number[2] << endl;
    cout << number[3] << endl;

    number[3] = 1000;
    cout << number[3];
}
*/