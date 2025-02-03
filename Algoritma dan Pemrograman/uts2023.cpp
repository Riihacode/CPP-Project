#include <iostream>
#include <string>
using namespace std;

int main() {
    string nim, nama;
    int totalSKS, sksPilihan, sksNilaiD, sksNilaiE, lamaLulus;
    float ipk;

    // Input data mahasiswa
    cout << "Masukkan NIM: ";
    cin >> nim;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, nama);
    cout << "Masukkan Total SKS: ";
    cin >> totalSKS;
    cout << "Masukkan IPK: ";
    cin >> ipk;
    cout << "Masukkan Jumlah SKS Mata Kuliah Pilihan: ";
    cin >> sksPilihan;
    cout << "Masukkan Jumlah SKS dengan Nilai D: ";
    cin >> sksNilaiD;
    cout << "Masukkan Jumlah SKS dengan Nilai E: ";
    cin >> sksNilaiE;
    cout << "Masukkan Lama Lulus (dalam semester): ";
    cin >> lamaLulus;

    // Cek kelulusan
    bool lulus = false;
    string predikat = "";
    bool karyaCendikia = false;

    if (ipk >= 2.25 && totalSKS >= 144 && sksPilihan >= 15 && sksNilaiD <= 0.25 * totalSKS && sksNilaiE == 0) {
        lulus = true;

        // Menentukan predikat kelulusan
        if (ipk >= 3.51 && lamaLulus <= 8) {
            predikat = "Dengan Pujian (Cumlaude)";
            karyaCendikia = true;
        } else if ((ipk >= 3.01 && ipk <= 3.50) || (ipk >= 3.51 && lamaLulus > 8)) {
            predikat = "Sangat Memuaskan";
        } else if (ipk >= 2.76 && ipk <= 3.00) {
            predikat = "Memuaskan";
        }
    }

    // Output hasil
    if (lulus) {
        cout << "\nMahasiswa " << nama << " (" << nim << ") dinyatakan LULUS.\n";
        cout << "Predikat Kelulusan: " << predikat << endl;
        if (karyaCendikia) {
            cout << "Mahasiswa diusulkan mendapatkan Karya Cendikia.\n";
        }
    } else {
        cout << "\nMahasiswa " << nama << " (" << nim << ") dinyatakan TIDAK LULUS.\n";
    }

    return 0;
}
