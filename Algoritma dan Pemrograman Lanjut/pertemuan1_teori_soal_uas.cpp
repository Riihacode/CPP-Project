#include <iostream>
using namespace std;

double countAverage(int arrayInput[], int totalData);

int main () {
    int nData;

    cout << "How much data ?  ";
    cin >> nData;

    int arrayData[nData];

    for (int i = 0; i < nData; i++) {
        int numberDataNow = i + 1;
        cout << "Data-"<<numberDataNow << " = ";
        cin>>arrayData[i];
    }

    double averageData = countAverage(arrayData, nData);
    cout << "Average Data is " << averageData; 
}

double countAverage(int arrayInput[], int totalData){
    int total = 0;
    for (int i = 0; i < totalData; i++) {
        total += arrayInput[i];
    }

    double totalAverage = total / totalData;

    return totalAverage;
}