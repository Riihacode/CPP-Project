#include <iostream>
#include <string>
using namespace std;

// =====================
// 1) Struct untuk File
// =====================
struct FileInfo {
    string name;
    int size;
    string dateModified;
};

// =======================
// 2) Struct untuk Folder
// =======================
// - Menyimpan hingga 10 file secara statis (tanpa alokasi dinamis)
// - Tidak menggunakan subfolder untuk kesederhanaan
struct Folder {
    string name;
    FileInfo files[10]; // Array statis ukuran 10
    int fileCount;      // Banyak file yang sudah terisi
};

// ===================================
// 3) Fungsi untuk inisialisasi Folder
// ===================================
void createFolder(Folder* folder, const string &folderName) {
    (*folder).name = folderName;
    (*folder).fileCount = 0;
}

// =============================================
// 4) Fungsi menambahkan file ke dalam Folder
// =============================================
// - Memasukkan data ke array statis selama belum penuh
void addFile(Folder* folder, const string &fileName, int size, const string &date) {
    int count = (*folder).fileCount;
    if (count < 10) {
        (*folder).files[count].name = fileName;
        (*folder).files[count].size = size;
        (*folder).files[count].dateModified = date;
        (*folder).fileCount++;
    } else {
        cout << "Folder sudah penuh (max 10 file)!\n";
    }
}

// =====================================
// 5) Fungsi menampilkan isi Folder
// =====================================
void printFolder(Folder* folder) {
    cout << "Folder: " << (*folder).name << endl;
    for (int i = 0; i < (*folder).fileCount; i++) {
        cout << "  File " << i << ": " 
             << (*folder).files[i].name 
             << " | Size: " << (*folder).files[i].size
             << " | Date: " << (*folder).files[i].dateModified 
             << endl;
    }
}

// ============================================
// 6) Fungsi sorting file dengan Bubble Sort (by name)
// ============================================
void sortFilesByName(Folder* folder) {
    int n = (*folder).fileCount;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((*folder).files[j].name > (*folder).files[j + 1].name) {
                // Swap elemen
                FileInfo temp = (*folder).files[j];
                (*folder).files[j] = (*folder).files[j + 1];
                (*folder).files[j + 1] = temp;
            }
        }
    }
}

// ===========================================
// 7) Fungsi searching non-rekursif (Linear Search)
// ===========================================
int searchFile(Folder* folder, const string &fileName) {
    for (int i = 0; i < (*folder).fileCount; i++) {
        if ((*folder).files[i].name == fileName) {
            return i; // Return indeks file yang ditemukan
        }
    }
    return -1; // Tidak ditemukan
}

// =============================================
// 8) Fungsi searching rekursif (Linear Search)
// =============================================
// - Mencari file dimulai dari indeks "index"
bool recursiveSearchFile(Folder* folder, const string &fileName, int index = 0) {
    if (index >= (*folder).fileCount) {
        return false; // Basis: sudah melebihi jumlah file
    }
    if ((*folder).files[index].name == fileName) {
        return true;  // File ditemukan
    }
    // Rekursif ke indeks berikutnya
    return recursiveSearchFile(folder, fileName, index + 1);
}

// ================================================
// 9) Fungsi contoh penggunaan array 2D (File Grid)
// ================================================
void displayFileGrid() {
    const int rows = 3;
    const int cols = 3;
    // Contoh data array dua dimensi: [Nama, Ukuran, Tanggal]
    string grid[rows][cols] = {
        {"fileA.txt", "100", "2023-01-01"},
        {"fileB.txt", "200", "2023-02-01"},
        {"fileC.txt", "150", "2023-03-01"}
    };

    cout << "\nFile Grid (Array 2D):\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }
}

// ===================================
// 10) Fungsi main dengan menu interaktif
// ===================================
int main() {
    Folder root;           // Deklarasi Folder secara statis
    Folder* pRoot = &root; // Pointer ke Folder, tanpa new

    // Input nama folder dari pengguna
    cout << "Masukkan nama folder: ";
    string folderName;
    getline(cin, folderName);
    createFolder(pRoot, folderName);

    int choice;
    do {
        cout << "\n===== Menu =====\n";
        cout << "1. Tambah File\n";
        cout << "2. Tampilkan Isi Folder\n";
        cout << "3. Sorting File berdasarkan Nama\n";
        cout << "4. Cari File (Non-Rekursif)\n";
        cout << "5. Cari File (Rekursif)\n";
        cout << "6. Tampilkan File Grid (Array 2D)\n";
        cout << "7. Keluar\n";
        cout << "Pilih menu (1-7): ";
        cin >> choice;
        cin.ignore(); // Bersihkan buffer input

        if (choice == 1) {
            // Tambah File
            if ((*pRoot).fileCount >= 10) {
                cout << "Folder sudah penuh. Tidak bisa menambah file lagi.\n";
            } else {
                string fName, fDate;
                int fSize;
                cout << "Masukkan nama file: ";
                getline(cin, fName);
                cout << "Masukkan ukuran file (angka): ";
                cin >> fSize;
                cin.ignore();
                cout << "Masukkan tanggal modifikasi: ";
                getline(cin, fDate);
                addFile(pRoot, fName, fSize, fDate);
            }
        } else if (choice == 2) {
            // Tampilkan Isi Folder
            printFolder(pRoot);
        } else if (choice == 3) {
            // Sorting File
            sortFilesByName(pRoot);
            cout << "File telah disortir berdasarkan nama.\n";
        } else if (choice == 4) {
            // Searching Non-Rekursif
            string searchName;
            cout << "Masukkan nama file yang ingin dicari (non-rekursif): ";
            getline(cin, searchName);
            int index = searchFile(pRoot, searchName);
            if (index != -1)
                cout << "File \"" << searchName << "\" ditemukan di indeks " << index << ".\n";
            else
                cout << "File \"" << searchName << "\" tidak ditemukan.\n";
        } else if (choice == 5) {
            // Searching Rekursif
            string searchName;
            cout << "Masukkan nama file yang ingin dicari (rekursif): ";
            getline(cin, searchName);
            bool found = recursiveSearchFile(pRoot, searchName);
            if (found)
                cout << "File \"" << searchName << "\" ditemukan.\n";
            else
                cout << "File \"" << searchName << "\" tidak ditemukan.\n";
        } else if (choice == 6) {
            // Tampilkan File Grid (contoh array 2D)
            displayFileGrid();
        } else if (choice == 7) {
            cout << "Keluar dari program.\n";
        } else {
            cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 7);

    return 0;
}
