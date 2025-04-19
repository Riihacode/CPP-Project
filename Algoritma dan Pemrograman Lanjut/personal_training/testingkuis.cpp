#include <iostream>
#include <string>

using namespace std;

struct PostCode {
    int postalCode;
    string regency;
};

struct Address{
    string city;
    string country;
    PostCode postCode;
};

struct Worker{
    string workerName;
    int workerAge;
    Address address;
};

struct Department{
    string departmentName;
    string ceoName;
    Worker worker;
};

//#####################################
// Struct
// Struct Tanggal
struct Tanggal {
    int hari;
    int bulan;
    int tahun;
};

// Struct Mahasiswa
struct Mahasiswa {
    string NIM;
    string Nama;
    Tanggal tanggalLahir; // Struct Tanggal jadi anggota
};

int main() {
    Mahasiswa mhs;

    // Input data mahasiswa
    cout << "Masukkan NIM  : "; cin >> mhs.NIM;
    cout << "Masukkan Nama : "; cin.ignore(); getline(cin, mhs.Nama);
    cout << "Masukkan Tanggal Lahir (dd mm yyyy): ";
    cin >> mhs.tanggalLahir.hari >> mhs.tanggalLahir.bulan >> mhs.tanggalLahir.tahun;

    // Output data mahasiswa
    cout << "\nData Mahasiswa:\n";
    cout << "NIM          : " << mhs.NIM << endl;
    cout << "Nama         : " << mhs.Nama << endl;
    cout << "Tanggal Lahir: " << mhs.tanggalLahir.hari << "-"
         << mhs.tanggalLahir.bulan << "-"
         << mhs.tanggalLahir.tahun << endl;

    return 0;
}


//#####################################
// Array
/*
int main () {

    int materiArray [3][3]= {{1, 2, 3}, {6, 7 ,8}};

    materiArray[1][2] = 898;
    cout << materiArray[1][2];
}*/