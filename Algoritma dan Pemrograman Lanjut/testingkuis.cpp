#include <iostream>
#include <string>
using namespace std;

#define MAX_CUSTOMER 10 // Batas maksimal customer

// Struktur untuk menyimpan data customer
struct Customer {
    int id;
    string nama;
    float saldo;
};

// Fungsi untuk menampilkan daftar customer
void tampilkanData(Customer daftarCustomer[], int jumlahCustomer) {
    if (jumlahCustomer == 0) {
        cout << "Belum ada data customer.\n";
        return;
    }

    cout << "\n===== Data Customer =====" << endl;
    for (int i = 0; i < jumlahCustomer; i++) {
        cout << "ID: " << daftarCustomer[i].id
             << ", Nama: " << daftarCustomer[i].nama
             << ", Saldo: " << daftarCustomer[i].saldo << endl;
    }
}

int main() {
    Customer daftarCustomer[MAX_CUSTOMER]; // Array of struct dengan batas tetap
    int jumlahCustomer = 0; // Penghitung jumlah customer yang diinput

    int pilihan;
    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Tambah Customer" << endl;
        cout << "2. Lihat Data Customer" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                if (jumlahCustomer < MAX_CUSTOMER) {
                    cout << "\nMasukkan data customer ke-" << jumlahCustomer + 1 << ":" << endl;
                    daftarCustomer[jumlahCustomer].id = jumlahCustomer + 1; // ID otomatis
                    cin.ignore();
                    cout << "Nama: ";
                    getline(cin, daftarCustomer[jumlahCustomer].nama);
                    cout << "Saldo: ";
                    cin >> daftarCustomer[jumlahCustomer].saldo;

                    jumlahCustomer++; // Menambah jumlah customer yang diinput
                    cout << "Customer berhasil ditambahkan!\n";
                } else {
                    cout << "Data customer sudah penuh (maksimal " << MAX_CUSTOMER << ").\n";
                }
                break;

            case 2:
                tampilkanData(daftarCustomer, jumlahCustomer);
                break;

            case 3:
                cout << "Keluar dari program...\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 3);

    return 0;
}