//##########################################
// Latihan praktikum yang ada di modul


//##########################################
/*
// Latihan praktikum yang ada di modul
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] < arr[j+1]) {        // Perubahannya ada di sini saja
                swap(arr[j], arr[j+1]); 
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = 7;
    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);

    bubbleSortDescending(arr, n);

    cout << "Array setelah diurutkan: ";
    printArray(arr, n);
    return 0;
}
*/



//##########################################
/*
// asdos praktikum
// selection sort
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = 7;
    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Array setelah diurutkan: ";
    printArray(arr, n);
    return 0;
}
*/


//##########################################
/*
// asdos praktikum
// insertion sort
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j+1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = 7;
    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Array setelah diurutkan: ";
    printArray(arr, n);
    return 0;
}
*/


//##########################################
// asdos praktikum
/*
#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]); 
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = 7;
    cout << "Array sebelum diurutkan: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Array setelah diurutkan: ";
    printArray(arr, n);
    return 0;
}

//--------------------------------------------------------------
//Note = 
//1. i adalah iterasi pertama untuk perulangan dari sekali run pada array untuk operasi pengurutan dari `arr` yang disimbolkan dengan `j`
//2. arr[j] & arr[j+1] maksudnya adalah nilai array yang disimpan di indeks j dan j+1
*/
//==============================================================





//##########################################
/*
// modul praktikum
// Bubble sort
#include <iostream>
#include <stdlib.h>

using namespace std;

void bubble_sort(int array[], int size) {
    int temp, i, j;

    for (i = 0; i < size; i++) {
        for (j = 0; j < size -1 - i; j++) {
            if (array[j] > array[j+1]) {
                temp = array[j+1];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main () {
    int data_size = 30;
    int values[data_size], i;

    // data yang belum diurutkan diambil dari hasil random
    cout << "Data yang belum urut : " << endl;
    for (i = 0; i < data_size; i++) {
        values[i] = rand % 100;
        cout << values[i] << " ";
    }

    cout << endl;

    bubble_sort(values, data_size);

    // data yang sudah diurutkan
}
*/