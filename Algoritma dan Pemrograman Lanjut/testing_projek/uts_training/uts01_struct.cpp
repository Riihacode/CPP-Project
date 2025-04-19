#include <iostream>
#include <string>
using namespace std;

/*
struct DriverAddress {
    string roadName;
    int roadNumber;
};

struct Driver {
    string name;
    DriverAddress driverAddress;
};

struct CarKind {
    char code;
    string codeNumber;
};

struct Car {
    CarKind carKind;
    Driver driver;
};

Car car[20];
int ;

int main() {

}*/

/*
void ubah(int x) {
    x = 10;
}*/

//int main() {
    /*
    int arr[6];  // Tidak diberi nilai

    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " "; // Mungkin akan menampilkan angka aneh
    }*/

    /*
    int arr[3] = {1,2,3};
    cout << arr[5]; // ❌ Error tak terdeteksi, hasil bisa random
    */
   
    /*
    int a = 5;
    ubah(a);
    cout << a << endl; // Output: 5 (tidak berubah)
    */
//}

// ERROR KARENA MASIHLAH ARRAY OF STRUCT  BUKAN BY POINTER
/*
struct LaptopId{
    char idCode;
    int idNumber;
};

struct Laptop {
    LaptopId laptopId;
    string laptopName;
    string yearReleased;
};

void inputLaptopDetail(Laptop* laptop[]);

int main (){
    Laptop* laptop[10];
    inputLaptopDetail(&laptop);
}

void inputLaptopDetail(Laptop* laptop[]){
    for (int i = 0; i < 10; i++) {
        if (i < 5) {
            laptop[i]->laptopId.idCode = 'A';
            laptop[i]->laptopId.idNumber = i + 1;
            cout << "Input Laptop-" << i + 1 << ": ";
            cout << "   Laptop Name             : ";cin >> laptop[i]->laptopName;
            cin  >> "   Laptop Year Released    : ";cin >> laptop[i]->yearReleased;
        }

        if (i >= 5 && i < 10) {
            laptop[i]->laptopId.idCode = 'B';
            laptop[i]->laptopId.idNumber = i + 1;
            cout << "Input Laptop-" << i + 1 << ": ";
            cout << "   Laptop Name             : ";cin >> laptop[i]->laptopName;
            cin  >> "   Laptop Year Released    : ";cin >> laptop[i]->yearReleased;
        }
    }
}
*/

// ARRAY OF STRUCT
/*
const int length = 3;

struct LaptopId{
    char idCode;
    int idNumber;
};

struct Laptop {
    LaptopId laptopId;
    string laptopName;
    string yearReleased;
};

void inputLaptop(Laptop laptopFunc[]);
void showDataLaptop(Laptop laptopFunc[]);

int main () {
    Laptop laptop[length];
    inputLaptop(laptop);
    showDataLaptop(laptop);
}

void inputLaptop(Laptop laptopFunc[]){
    cout << "Input Data : " << endl;
    
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            laptopFunc[i].laptopId.idCode = 'A';
        }
        
        if (i == 1) {
            laptopFunc[i].laptopId.idCode = 'B';
        }

        if (i == 2) {
            laptopFunc[i].laptopId.idCode = 'C';
        }

        laptopFunc[i].laptopId.idNumber = i;
        cout << "   Laptop name index-"<< i+1 << "      : ";
        cin >> laptopFunc[i].laptopName;
        cout << "   Laptop year released    : ";
        cin >> laptopFunc[i].yearReleased;
    }
}

void showDataLaptop(Laptop laptopFunc[]) {
    string idShow;

    for (int i = 0; i < length; i++) {
        cout << "Data-"<< i+1 << ": " << endl;
        idShow = to_string(laptopFunc[i].laptopId.idNumber + 1) + laptopFunc[i].laptopId.idCode;
        cout << "   Laptop ID               : " << idShow << endl;
        cout << "   Laptop Name             : " << laptopFunc[i].laptopName << endl;
        cout << "   Laptop Released Year    : " << laptopFunc[i].yearReleased << endl;
    }
}
*/


// POINTER KONSEP
/*
void changeData(int *a) {
    *a = 10;
}

int main () {
    int a = 5;
    changeData(&a);
    cout << a;
}
*/

// STRUCT BY POINTER
/*
const int length = 3;

struct LaptopId{
    char idCode;
    int idNumber;
};

struct Laptop {
    LaptopId laptopId;
    string laptopName;
    string yearReleased;
};

void inputData(Laptop* laptopFunc, int n);
void showData(Laptop* laptopFunc, int n);

int main(){
    Laptop laptop[length];
    inputData(laptop, length);
    showData(laptop, length);
}

void inputData(Laptop* laptopFunc, int n){
    cout << "Input Data : " << endl;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            laptopFunc[i].laptopId.idCode = 'A';
        }

        if (i == 1) {
            laptopFunc[i].laptopId.idCode = 'B';
        }

        if (i == 2) {
            laptopFunc[i].laptopId.idCode = 'C';
        }

        laptopFunc[i].laptopId.idNumber = i;
        cout << "   Laptop name index-" << i + 1 << "    : ";   cin >> laptopFunc[i].laptopName;
        cout << "   Laptop released year    : ";                cin >> laptopFunc[i].yearReleased;
    }
    
}

void showData(Laptop* laptopFunc, int n) {
    string idCombine;
    for (int i = 0; i < n; i++) {
        cout << "Data index-" << i+1 << endl;
        idCombine = to_string(laptopFunc[i].laptopId.idNumber + 1) + laptopFunc[i].laptopId.idCode;
        cout << "   Laptop ID               : " << idCombine << endl;
        cout << "   Laptop Name             : " << laptopFunc[i].laptopName << endl;
        cout << "   Laptop Released Year    : " << laptopFunc[i].yearReleased << endl;
    }
}
*/

// STRUCT BY REFERENCE
/*
const int length = 3;

struct LaptopId{
    char idCode;
    int idNumber;
};

struct Laptop {
    LaptopId laptopId;
    string laptopName;
    string yearReleased;
};

void inputLaptop(Laptop laptopFunc[], int n);
void showDataLaptop(Laptop laptopFunc[], int n);
void inputSingle(Laptop &lapt, int index);

int main () {
    Laptop laptop[length];
    inputLaptop(laptop, length);
    showDataLaptop(laptop, length);
}

void inputLaptop(Laptop laptopFunc[], int n){
    cout << "Input Data : " << endl;
    
    for (int i = 0; i < length; i++) {
        inputSingle(laptopFunc[i], i);
    }
}

void inputSingle(Laptop &lapt, int index) {
        if (index == 0) {
            lapt.laptopId.idCode = 'A';
        }
        
        if (index == 1) {
            lapt.laptopId.idCode = 'B';
        }

        if (index == 2) {
            lapt.laptopId.idCode = 'C';
        }

        lapt.laptopId.idNumber = index;
        cout << "   Laptop name index-"<< index+1 << "      : ";
        cin >> lapt.laptopName;
        cout << "   Laptop year released    : ";
        cin >> lapt.yearReleased;
}

void showDataLaptop(Laptop laptopFunc[], int n) {
    string idShow;

    for (int i = 0; i < length; i++) {
        cout << "Data-"<< i+1 << ": " << endl;
        idShow = to_string(laptopFunc[i].laptopId.idNumber + 1) + laptopFunc[i].laptopId.idCode;
        cout << "   Laptop ID               : " << idShow << endl;
        cout << "   Laptop Name             : " << laptopFunc[i].laptopName << endl;
        cout << "   Laptop Released Year    : " << laptopFunc[i].yearReleased << endl;
    }
}
*/

// STRUCT BY REFERENCE (HARUS SATU-SATU & TIDAK BISA LANGSUNG PAKE LOOP)
/*
const int length = 3;

struct LaptopId{
    char idCode;
    int idNumber;
};

struct Laptop {
    LaptopId laptopId;
    string laptopName;
    string releasedYear;
};

void inputLaptop(Laptop laptopFunc[]);
void inputLaptopSingle(Laptop &lapt, int indexArray);
void showLaptopData(Laptop laptopFunc[]);
void showLaptopDataSingle(Laptop &lapt, int indexArray);

int main () {
    Laptop laptop[length];
    inputLaptop(laptop);
    showLaptopData(laptop);
}

void inputLaptop(Laptop laptopFunc[]){
    cout << "Input Data : " << endl;

    for (int i = 0; i < length; i++) {
        inputLaptopSingle(laptopFunc[i], i);
    }
}

void inputLaptopSingle(Laptop &lapt, int indexArray) {
    if (indexArray == 0) {
        lapt.laptopId.idCode = 'A';
    }

    if (indexArray == 1) {
        lapt.laptopId.idCode = 'B';
    }

    if (indexArray == 2) {
        lapt.laptopId.idCode = 'C';
    }

    lapt.laptopId.idNumber = indexArray;
    cout << "   Laptop name index-"<< indexArray+1 << "    : " ;   cin >> lapt.laptopName;
    cout << "   Laptop year released    : "                    ;   cin >> lapt.releasedYear;
}

void showLaptopData(Laptop laptopFunc[]) {
    cout << "Output Data : " << endl;
    for (int i = 0; i < length; i++) {
        showLaptopDataSingle(laptopFunc[i], i);
    }
}

void showLaptopDataSingle(Laptop &lapt, int indexArray){
    string combineId;
    cout << "Data index-"<< indexArray + 1 << " : " << endl;
    combineId = to_string(lapt.laptopId.idNumber + 1) + lapt.laptopId.idCode;
    cout << "   Laptop ID               : " << combineId << endl;
    cout << "   Laptop Name             : " << lapt.laptopName << endl;
    cout << "   Laptop Released Year    : " << lapt.releasedYear << endl;
}
*/

struct koordinat {
    int x, y;
};

void tukar_xy(koordinat *pos_xy);

int main () {
    koordinat posisi = {21, 34};
    cout << "x, y semula = " << posisi.x << ", " << posisi.y << endl;
    tukar_xy(&posisi);
    cout << "x, y kini = " << posisi.x << ", " << posisi.y << endl;
}

void tukar_xy(koordinat *pos_xy) {
    int z;
    /*
    z = pos_xy->x;
    pos_xy->x = pos_xy->y;
    pos_xy->y = z
    ;*/

    z = (*pos_xy).x;
    (*pos_xy).x = (*pos_xy).y;
    (*pos_xy).y = z;
}
