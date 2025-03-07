#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// **Struct untuk menyimpan data pasien**
struct Pasien {
    string nama;
    string gejala;
    int umur;
    int tingkatKeparahan;  // 1 (Ringan) - 5 (Kritis)
};

// **Array multi dimensi untuk mengelompokkan pasien berdasarkan tingkat keparahan**
Pasien daftarPasien[5][100];  // 5 kategori tingkat keparahan (1-5)
int jumlahPasien[5] = {0};    // Menyimpan jumlah pasien untuk setiap kategori

// **Pointer untuk menyimpan alamat array pasien**
Pasien* ptrPasien = &daftarPasien[0][0];

// **Fungsi untuk menambahkan pasien baru**
void tambahPasien() {
    Pasien p;
    cout << "Masukkan Nama Pasien: ";
    cin.ignore();
    getline(cin, p.nama);
    cout << "Masukkan Umur Pasien: ";
    cin >> p.umur;
    cout << "Masukkan Gejala (contoh: Demam, Sesak Napas, dll.): ";
    cin.ignore();
    getline(cin, p.gejala);
    cout << "Masukkan Tingkat Keparahan (1 - 5): ";
    cin >> p.tingkatKeparahan;

    int index = p.tingkatKeparahan - 1;
    daftarPasien[index][jumlahPasien[index]++] = p;
}

// **Fungsi untuk menampilkan daftar pasien berdasarkan tingkat keparahan**
void tampilkanPasien() {
    cout << "\nDaftar Pasien Berdasarkan Tingkat Keparahan:\n";
    for (int i = 4; i >= 0; i--) {  // Dari yang paling kritis ke yang paling ringan
        cout << "\n>> Tingkat Keparahan " << (i + 1) << " <<\n";
        for (int j = 0; j < jumlahPasien[i]; j++) {
            cout << daftarPasien[i][j].nama << " (Umur: " << daftarPasien[i][j].umur << ") - " << daftarPasien[i][j].gejala << endl;
        }
    }
}

// **Fungsi untuk menyimpan data pasien ke file**
void simpanKeFile() {
    ofstream file("patients.txt");
    for (int i = 4; i >= 0; i--) {
        for (int j = 0; j < jumlahPasien[i]; j++) {
            file << daftarPasien[i][j].nama << "," << daftarPasien[i][j].umur << "," << daftarPasien[i][j].gejala << "," << daftarPasien[i][j].tingkatKeparahan << "\n";
        }
    }
    file.close();
    cout << "Data pasien telah disimpan ke file.\n";
}

// **Fungsi untuk membaca data pasien dari file**
void bacaDariFile() {
    ifstream file("patients.txt");
    if (!file) {
        cout << "File tidak ditemukan.\n";
        return;
    }

    string nama, gejala;
    int umur, tingkatKeparahan;

    while (file >> nama >> umur >> gejala >> tingkatKeparahan) {
        int index = tingkatKeparahan - 1;
        daftarPasien[index][jumlahPasien[index]++] = {nama, gejala, umur, tingkatKeparahan};
    }
    file.close();
    cout << "Data pasien telah dimuat dari file.\n";
}

// **Fungsi rekursif untuk Merge Sort berdasarkan umur**
void merge(Pasien arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Pasien L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].umur <= R[j].umur) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Pasien arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// **Menu Utama**
int main() {
    int pilihan;

    while (true) {
        cout << "\n=== Hospital Emergency Triage System ===\n";
        cout << "1. Tambah Pasien\n";
        cout << "2. Tampilkan Daftar Pasien\n";
        cout << "3. Simpan Data ke File\n";
        cout << "4. Baca Data dari File\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        if (pilihan == 1) tambahPasien();
        else if (pilihan == 2) tampilkanPasien();
        else if (pilihan == 3) simpanKeFile();
        else if (pilihan == 4) bacaDariFile();
        else if (pilihan == 5) break;
        else cout << "Pilihan tidak valid.\n";
    }

    return 0;
}
