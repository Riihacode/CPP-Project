#include <iostream>
using namespace std;

void printArray(string namaMatrik, int a[][3]);

int main () {
    int matrik1 [2][3] = {  {1, 2, 3}, 
                            {4, 5, 6}};

    int matrik2 [2][3] = {  {1, 2, 3},
                            {4, 5   }};

    int matrik3 [2][3] = {  {1, 2   },
                            {4      }};

    printArray("matrik1", matrik1);
    printArray("matrik2", matrik2);
    printArray("matrik3", matrik3);

    return 0;
}

void printArray(string namaMatrik, int a[][3]){
    int i, j;

    cout << namaMatrik << endl;

    for (i = 0; i<2 ; i++) {
        for (j = 0; j<3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}