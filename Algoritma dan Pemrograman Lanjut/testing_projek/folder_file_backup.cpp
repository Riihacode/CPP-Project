#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// ---------------------- Struct ----------------------
struct File {
    string name;
    int size;
};


struct Folder {
    string name;
    File files[10];
    int fileCount;
};

// ---------------------- Variabel Global ----------------------
Folder folders[10];
int folderCount = 0;

// ---------------------- Fungsi Prototipe ----------------------
void addFolder();
void addFileToFolder();
void generateInputData();
void showAllFolders();
void searchFile();
void sortFilesInFolder();
void saveDataToFile();
void loadDataFromFile();
void menuSearching();
void seqNonSentinelBelumUrut();
void seqNonSentinelSudahUrut();
void seqSentinelBelumUrut();
void seqSentinelSudahUrut();
void binarySearchSudahUrut();
void tampilkanFolderBersarang();

// ---------------------- Fungsi Utama ----------------------
int main() {
    int choice;
    loadDataFromFile(); // Load data jika ada file sebelumnya

    do {
        cout << "\n====== Menu Folder & File ======" << endl;
        cout << "0. Generate Tambah Folder & File";
        cout << "1. Tambah Folder\n";
        cout << "2. Tambah File ke Folder\n";
        cout << "3. Tampilkan Semua Folder dan File\n";
        cout << "4. Cari File\n";
        cout << "5. Urutkan File dalam Folder (Bubble Sort)\n";
        cout << "6. Simpan Data ke File\n";
        cout << "7. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;
        cin.ignore(); // Agar getline tidak bermasalah

        switch (choice) {
            case 0: generateInputData();                    break;
            case 1: addFolder();                        break;
            case 2: addFileToFolder();                  break;
            case 3: showAllFolders();                   break;
            case 4: menuSearching();                    break;
            case 5: sortFilesInFolder();                break;
            case 6: saveDataToFile();                   break;
            case 7: cout << "Keluar dari program.\n";   break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 7);
    
    return 0;
}

// ---------------------- Fungsi Implementasi ----------------------

// Tambah Folder
void addFolder() {
    if (folderCount >= 10) {
        cout << "Jumlah folder maksimum tercapai!\n";
        return;
    }

    cout << "Masukkan nama folder: ";
    getline(
        cin, 
        folders[folderCount].name
    );
    folders[folderCount].fileCount = 0;
    folderCount++;
    cout << "Folder berhasil ditambahkan!\n";
}

// Tambah File ke Folder
void addFileToFolder() {
    showAllFolders();
    int index;
    cout << "Pilih index folder: ";
    cin >> index;
    cin.ignore();

    if (index < 0 || index >= folderCount) {
        cout << "Index folder tidak valid!\n";
        return;
    }

    if (folders[index].fileCount >= 10) {
        cout << "Folder penuh, tidak bisa menambah file lagi!\n";
        return;
    }

    cout << "Masukkan nama file: ";
    getline(
        cin, 
        folders[index]
        .files[folders[index].fileCount]
        .name
    );
    cout << "Masukkan ukuran file (KB): ";
    cin >> 
        folders[index]
        .files[folders[index].fileCount]
        .size;
    folders[index].fileCount++;
    cout << "File berhasil ditambahkan!\n";
}

// ✅ Fungsi otomatis input data folder dan file
void generateInputData() {
    // Tentukan jumlah folder
    folderCount = 3;

    // Folder 1
    folders[0].name = "folder 1";
    folders[0].fileCount = 2;
    folders[0].files[0] = {"file 1 folder 1", 10};
    folders[0].files[1] = {"file 2 folder 1", 20};

    // Folder 2
    folders[1].name = "folder 2";
    folders[1].fileCount = 3;
    folders[1].files[0] = {"file 1 folder 2", 15};
    folders[1].files[1] = {"file 2 folder 2", 25};
    folders[1].files[2] = {"file 3 folder 2", 35};

    // Folder 3
    folders[2].name = "folder 3";
    folders[2].fileCount = 1;
    folders[2].files[0] = {"file 1 folder 3", 12};

    cout << "Data folder dan file otomatis berhasil dimasukkan!\n";
}

// Tampilkan Semua Folder dan File
void showAllFolders() {
    if (folderCount == 0) {
        cout << "Belum ada folder!\n";
        return;
    }
    
    for (int i = 0; i < folderCount; i++) {
        cout << "Folder [" << i << "]: " << folders[i].name << endl;
        for (int j = 0; j < folders[i].fileCount; j++) {
            cout << "  - "  << folders[i].files[j].name 
                 << " ("    << folders[i].files[j].size << " KB)" 
                 << endl;
        }
    }
}

// ✅ Menu tambahan pilihan searching
void menuSearching() {
    cout << "\n=== Pilih Algoritma Searching ===" << endl;
    cout << "1. Sequential Non Sentinel (Belum Urut)\n";
    cout << "2. Sequential Non Sentinel (Sudah Urut)\n";
    cout << "3. Sequential dengan Sentinel (Belum Urut)\n";
    cout << "4. Sequential dengan Sentinel (Sudah Urut)\n";
    cout << "5. Binary Search (Sudah Urut)\n";
    cout << "Pilihan: ";
    int pilih;
    cin >> pilih;
    cin.ignore();

    switch (pilih) {
        case 1: seqNonSentinelBelumUrut(); break;
        case 2: seqNonSentinelSudahUrut(); break;
        case 3: seqSentinelBelumUrut(); break;
        case 4: seqSentinelSudahUrut(); break;
        case 5: binarySearchSudahUrut(); break;
        default: cout << "Pilihan tidak valid!\n";
    }
}


// Cari File (Sequential Search non sentinel - data belum urut)
void searchFile() {
    cout << "Masukkan nama file yang dicari: ";
    string target;
    getline(cin, target);

    bool found = false;
    for (int i = 0; i < folderCount; i++) {
        for (int j = 0; j < folders[i].fileCount; j++) {
            if (folders[i].files[j].name == target) {
                cout << "File ditemukan di folder: " 
                     << folders[i].name 
                     << endl;

                found = true;
            }
        }
    }

    if (!found) {
        cout << "File tidak ditemukan.\n";
    }
}

void seqNonSentinelBelumUrut() {
    cout << "Masukkan nama file yang dicari: ";
    string target;
    getline(
        cin, 
        target
    );

    bool foundOverall = false;

    for (int i = 0; i < folderCount; i++) {
        bool found = false;
        int j = 0;
        
        while (
            (j < folders[i].fileCount) 
            && (!found)
        ) {
            if (folders[i].files[j].name == target) {
                found = true;
            }
            else {
                j++;
            } 
        }

        if (found) {
            cout << "File \"" << target 
                 << "\" ditemukan di folder \"" << folders[i].name 
                 << "\" pada index ke-" << j 
                 << endl;
                 
            foundOverall = true;
        }
    }

    if (!foundOverall) {
        cout << "File \"" << target << "\" tidak ditemukan.\n";
    }
}

void seqNonSentinelSudahUrut() {
    cout << "Masukkan nama file yang dicari: ";
    string target;
    getline(cin, target);

    bool foundOverall = false;

    for (int i = 0; i < folderCount; i++) {
        bool found = false;
        int j = 0;

        while (
            (j < folders[i].fileCount) 
            && (!found) 
            && (target >= folders[i].files[j].name)
        ) {
            if (folders[i].files[j].name == target) {
                found = true;
            } else {
                j++;
            }
        }

        if (found) {
            cout << "File \"" << target 
                 << "\" ditemukan di folder \"" << folders[i].name 
                 << "\" pada index ke-" << j 
                 << endl;

            foundOverall = true;
        }
    }
    if (!foundOverall) {
        cout << "File \"" << target << "\" tidak ditemukan.\n";
    }
}

void seqSentinelBelumUrut() {
    cout << "Masukkan nama file yang dicari: ";
    string target;
    getline(cin, target);

    bool foundOverall = false;

    for (int i = 0; i < folderCount; i++) {
        int n = folders[i].fileCount;
        folders[i].files[n].name = target; // Sentinel
        int j = 0;

        while (folders[i].files[j].name != target) {
            j++;
        }

        if (j < n) {
            cout << "File \"" << target 
                 << "\" ditemukan di folder \"" << folders[i].name 
                 << "\" pada index ke-" << j 
                 << endl;
                 
            foundOverall = true;
        }
    }

    if (!foundOverall) {
        cout << "File \"" << target << "\" tidak ditemukan.\n";
    }
}

void seqSentinelSudahUrut() {
    cout << "Masukkan nama file yang dicari: ";
    string target;
    getline(
        cin, 
        target
    );

    bool foundOverall = false;

    for (int i = 0; i < folderCount; i++) {
        int n = folders[i].fileCount;
        folders[i].files[n].name = target; // Sentinel
        int j = 0;

        while (
            folders[i].files[j].name 
            < target
        ) {
            j++;
        }
        
        if (
            j < n 
            && folders[i].files[j].name == target
        ) {
            cout << "File \"" << target 
                 << "\" ditemukan di folder \"" << folders[i].name 
                 << "\" pada index ke-" << j 
                 << endl;

            foundOverall = true;
        }
    }

    if (!foundOverall) {
        cout << "File \"" << target << "\" tidak ditemukan.\n";
    }
}

void binarySearchSudahUrut() {
    cout << "Masukkan nama file yang dicari: ";
    string target;
    getline(
        cin, 
        target
    );

    bool foundOverall = false;

    for (int i = 0; i < folderCount; i++) {
        int kiri = 0, kanan = folders[i].fileCount - 1;
        bool found = false;
        int tengah;

        while (
            kiri <= kanan 
            && !found
        ) {
            tengah = (kiri + kanan) / 2;
            if (folders[i].files[tengah].name == target) {
                found = true;
            } else if (target < folders[i].files[tengah].name) {
                kanan = tengah - 1;
            } else {
                kiri = tengah + 1;
            }
        }

        if (found) {
            cout << "File \"" << target 
                 << "\" ditemukan di folder \"" << folders[i].name 
                 << "\" pada index ke-" << tengah 
                 << endl;

            foundOverall = true;
        }
    }

    if (!foundOverall) {
        cout << "File \"" << target << "\" tidak ditemukan.\n";
    }
}

// Sorting File dalam Folder (Bubble Sort)
void sortFilesInFolder() {
    showAllFolders();

    int index;
    cout << "Pilih index folder yang ingin diurutkan: ";
    cin >> index;

    if (index < 0 || index >= folderCount) {
        cout << "Index folder tidak valid!\n";
        return;
    }

    int n = folders[index].fileCount;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (
                folders[index].files[j].name 
                > folders[index].files[j + 1].name
            ) {
                swap(folders[index].files[j], folders[index].files[j + 1]);
            }
        }
    }

    cout << "File berhasil diurutkan berdasarkan nama (Ascending).\n";
}

// Simpan Data ke File
void saveDataToFile() {
    ofstream out("data.txt");
    out << folderCount << endl;
    for (int i = 0; i < folderCount; i++) {
        out << folders[i].name << " " << folders[i].fileCount << endl;
        for (int j = 0; j < folders[i].fileCount; j++) {
            out << folders[i].files[j].name << " " << folders[i].files[j].size << endl;
        }
    }
    out.close();
    cout << "Data berhasil disimpan ke file.\n";
}

// Load Data dari File
void loadDataFromFile() {
    ifstream in("data.txt");
    if (!in) return; // Jika file belum ada, abaikan
    in >> folderCount;
    for (int i = 0; i < folderCount; i++) {
        in >> folders[i].name >> folders[i].fileCount;
        for (int j = 0; j < folders[i].fileCount; j++) {
            in >> folders[i].files[j].name >> folders[i].files[j].size;
        }
    }
    in.close();
}

