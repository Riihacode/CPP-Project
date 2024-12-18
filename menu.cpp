#include <iostream>

using namespace std;

void showMenu() {
    cout << "===================" << endl;
    cout << "       MENU        " << endl;
    cout << "===================" << endl;
    cout << "1. Opsi 1" << endl;
    cout << "2. Opsi 2" << endl;
    cout << "3. Opsi 3" << endl;
    cout << "4. Keluar" << endl;
    cout << "===================" << endl;
    cout << "Pilih opsi: ";
}

void opsi1() {
    cout << "Anda memilih Opsi 1" << endl;
    // Tambahkan logika tambahan untuk Opsi 1 di sini
}

void opsi2() {
    cout << "Anda memilih Opsi 2" << endl;
    // Tambahkan logika tambahan untuk Opsi 2 di sini
}

void opsi3() {
    cout << "Anda memilih Opsi 3" << endl;
    // Tambahkan logika tambahan untuk Opsi 3 di sini
}

void handleMenu() {
    int pilihan;

    while (true) {
        showMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                opsi1();
                break;
            case 2:
                opsi2();
                break;
            case 3:
                opsi3();
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                return; // Kembali ke menu utama
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }

        cout << endl;
    }
}

int main() {
    bool keluar = false;

    while (!keluar) {
        handleMenu();

        char keluarMenu;
        cout << "Apakah Anda ingin keluar? (y/n): ";
        cin >> keluarMenu;

        if (keluarMenu == 'y' || keluarMenu == 'Y') {
            keluar = true;
        }
    }

    return 0;
}
