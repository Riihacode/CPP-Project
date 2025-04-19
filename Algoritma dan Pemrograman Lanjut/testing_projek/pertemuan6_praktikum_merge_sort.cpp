#include <iostream>
#include <string>
using namespace std;

//#####################################
// Quick Sort
void printArray(int *numbers, int length){
    for (int i = 0; i < length;i++) {
        cout << numbers[i] << " ";
    }
}

int partition(int *numbers, int left, int right) {
    int pivot = numbers[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (numbers[j] <= pivot) {
            i++;
            swap(numbers[j], numbers[i]);
        }
    }

    i++;

    swap(numbers[i], numbers[right]);

    return i;
}

void quickSort(int *numbers, int left, int right) {
    if (left >= right) {
        return;    
    }

    int partitionIndex = partition(numbers, left, right);

    quickSort(numbers, left, partitionIndex - 1);
    quickSort(numbers, partitionIndex + 1, right);
    
}

int main(){
    int numbers[] {5, 2 ,12, 10, 17, 13, 12, 4} ;
    printArray(numbers, 8);
}

//#####################################
// Merge Sort
/*
void printArray(int *numbers, int length){
    for (int i = 0; i < length;i++) {
        cout << numbers[i] << " ";
    }
}

void merge(int *numbers, int left, int mid, int right){
    int nLeft = mid - left + 1;
    int nRight = right - mid;

    int leftArray[nLeft], rightArray[nRight];

    for (int i = 0; i < nLeft; i++) {
        leftArray = numbers[left + i];
    }

    for (int i = 0; i < nRight; i++) {  
        rightArray = numbers[mid + i + 1];
    }

    int i = 0, j = 0;
    int k = left;
    
    while(i < nLeft && j < nRight) {
        if (leftArray[i] <= rightArray[i]) {
            numbers[k] = leftArray[i];
            i++;
        } else {
            numbers[k] = rightArray[i];
            j++;
        }

        k++;
    }

    while(i < nLeft) {
        numbers[k] = leftArray[i];
        k++;
        i++;
    }
    
    while(i < nRight) {
        numbers[k] = rightArray[i];
        k++;
        j++;
    }
}

void merge(){

}

int main() {
    int number[]={1, 5, 9 , 13, 2, 10, 14, 20};
    int randomNumbers[] = {5, 2, 12, 10, 17, 13, 12, 4};
    printArray(numbers, 8);
}
*/
