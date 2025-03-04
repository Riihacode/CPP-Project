////////////////////////////////////////////////
// selectionsort.cpp 
// #include "stdafx.h"
#include <iostream>
using namespace std;

void SelectSort(int a[], int n){
	int i = 0, j, k, x;
	for(i = 0; i < 5; i++) {
		k = i;
       for(j = i + 1; j < n; j++) {
       	if (a[j] < a[k]) {
              k = j;
           }
       }
		swap(a[i], a[k]);   // Tukar Posisi
		printf("   Iterasi Ke-%d :  ", i+1);
		for(x = 0; x < n; x++) {
			printf("%d  ", a[x]);
		}
		printf("\n\n");
   }
}
int main() {
    int i, n = 6;
    int a[] = {7, 23, 4, 29, 11, 9};
    printf("Straight Selection Sort\n");
    printf("\n   Data Sebelum diurutkan :  ");
    for (i = 0; i < n; i++) {
        printf(" %d ", a[i]);
    }
    printf("\n\nProses Pengurutan Data:\n\n");
    SelectSort(a, n);
    printf("   Data Setelah Diurutkan : ");
    for (i = 0; i < n; i++) {
        printf("  %d", a[i]);
    }
    getchar();
}





////////////////////////////////////////////////
// bubble_sort.cpp   
/*
//#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{ int i,j, n=7, x[7]={7,23,4,29,11,9,14};
  cout <<"Data Sebelum diurutkan:\n"; 
  for(i=0; i<n; i++){
	cout <<x[i]<<" "; 
  }
 for(i=0; i<n-1; i++){
    for(j=i+1; j<n; j++){
        if(x[i]>x[j]){
	      swap(x[i],x[j]);    // Tukar posisi
        }   
    }
  }  
  cout <<"\n\nData Setelah diurutkan:\n";
  for(i=0; i<n; i++){
	cout <<x[i]<<" "; 
  }
  cout <<"\n\n";
  system("pause");
}
  */
