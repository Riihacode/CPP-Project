#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// =============================
// Struktur data untuk menyimpan informasi file
// =============================
struct FileInfo {
    char name[100];
    int size;
    char dateModified[20];
};

// =============================
// Struktur data untuk folder yang memiliki file dan subfolder
// =============================
struct Folder {
    char name[100];
    FileInfo *files;      // Pointer ke array dinamis file
    int fileCount;        // Jumlah file di folder ini
    Folder **subFolders;  // Pointer ke array dinamis pointer folder (subfolder)
    int subFolderCount;   // Jumlah subfolder
};

// =============================
// Fungsi untuk membuat folder baru (alokasi dinamis)
// =============================
Folder* createFolder(const char* name) {
    Folder* folder = new Folder;
    strcpy(folder->name, name);
    folder->files = nullptr;
    folder->fileCount = 0;
    folder->subFolders = nullptr;
    folder->subFolderCount = 0;
    return folder;
}

// =============================
// Fungsi untuk menambahkan file ke folder
// =============================
void addFile(Folder* folder, const char* fileName, int size, const char* date) {
    // Alokasi array FileInfo baru dengan ukuran yang lebih besar
    FileInfo* newFiles = new FileInfo[folder->fileCount + 1];
    for (int i = 0; i < folder->fileCount; i++) {
        newFiles[i] = folder->files[i];
    }
    // Menambahkan file baru
    strcpy(newFiles[folder->fileCount].name, fileName);
    newFiles[folder->fileCount].size = size;
    strcpy(newFiles[folder->fileCount].dateModified, date);
    // Menghapus array lama (jika ada)
    if (folder->files != nullptr) {
        delete[] folder->files;
    }
    folder->files = newFiles;
    folder->fileCount++;
}

// =============================
// Fungsi untuk menambahkan subfolder ke folder
// =============================
void addSubFolder(Folder* parent, Folder* sub) {
    Folder** newSubFolders = new Folder*[parent->subFolderCount + 1];
    for (int i = 0; i < parent->subFolderCount; i++) {
        newSubFolders[i] = parent->subFolders[i];
    }
    newSubFolders[parent->subFolderCount] = sub;
    if (parent->subFolders != nullptr) {
        delete[] parent->subFolders;
    }
    parent->subFolders = newSubFolders;
    parent->subFolderCount++;
}

// =============================
// Fungsi rekursif untuk mencetak struktur folder dan file
// =============================
void printFolder(Folder* folder, int level = 0) {
    // Indentasi sesuai level folder
    for (int i = 0; i < level; i++) cout << "  ";
    cout << "Folder: " << folder->name << endl;
    // Cetak file-file pada folder ini
    for (int i = 0; i < folder->fileCount; i++) {
        for (int j = 0; j < level + 1; j++) cout << "  ";
        cout << "File: " << folder->files[i].name 
             << " | Size: " << folder->files[i].size 
             << " | Date: " << folder->files[i].dateModified << endl;
    }
    // Rekursif untuk setiap subfolder
    for (int i = 0; i < folder->subFolderCount; i++) {
        printFolder(folder->subFolders[i], level + 1);
    }
}

// =============================
// Fungsi pengurutan (sorting) sederhana: mengurutkan file dalam folder berdasarkan nama (Bubble Sort)
// =============================
void sortFilesByName(Folder* folder) {
    for (int i = 0; i < folder->fileCount - 1; i++) {
        for (int j = 0; j < folder->fileCount - i - 1; j++) {
            if (strcmp(folder->files[j].name, folder->files[j + 1].name) > 0) {
                FileInfo temp = folder->files[j];
                folder->files[j] = folder->files[j + 1];
                folder->files[j + 1] = temp;
            }
        }
    }
}

// =============================
// Fungsi pencarian: mencari file berdasarkan nama di dalam folder (tanpa rekursif)
// Mengembalikan indeks file jika ditemukan, atau -1 jika tidak ditemukan.
// =============================
int searchFile(Folder* folder, const char* fileName) {
    for (int i = 0; i < folder->fileCount; i++) {
        if (strcmp(folder->files[i].name, fileName) == 0)
            return i;
    }
    return -1;
}

// =============================
// Fungsi rekursif untuk mencari file dalam folder dan subfolder
// =============================
bool recursiveSearch(Folder* folder, const char* fileName) {
    if (searchFile(folder, fileName) != -1) {
        return true;
    }
    for (int i = 0; i < folder->subFolderCount; i++) {
        if (recursiveSearch(folder->subFolders[i], fileName))
            return true;
    }
    return false;
}

// =============================
// Fungsi operasi file: menyimpan struktur folder ke dalam file teks
// =============================
void saveFolderToFile(Folder* folder, ofstream &out, int level = 0) {
    for (int i = 0; i < level; i++) out << "  ";
    out << "Folder: " << folder->name << "\n";
    for (int i = 0; i < folder->fileCount; i++) {
        for (int j = 0; j < level + 1; j++) out << "  ";
        out << "File: " << folder->files[i].name 
            << " | Size: " << folder->files[i].size 
            << " | Date: " << folder->files[i].dateModified << "\n";
    }
    for (int i = 0; i < folder->subFolderCount; i++) {
        saveFolderToFile(folder->subFolders[i], out, level + 1);
    }
}

// =============================
// Contoh penggunaan array dua dimensi (misalnya untuk menampilkan grid data file)
// =============================
void displayFileGrid() {
    const int rows = 3, cols = 3;
    // Baris: tiap file, Kolom: [Nama, Ukuran, Tanggal]
    string grid[rows][cols] = {
        {"fileA.txt", "100", "2023-01-01"},
        {"fileB.txt", "200", "2023-02-01"},
        {"fileC.txt", "150", "2023-03-01"}
    };
    
    cout << "\nFile Grid (Array 2D):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << "\t";
        }
        cout << endl;
    }
}

// =============================
// Fungsi utama
// =============================
int main() {
    // Membuat folder root
    Folder* root = createFolder("Root");

    // Menambahkan file ke folder root
    addFile(root, "fileA.txt", 100, "2023-01-01");
    addFile(root, "fileB.txt", 200, "2023-02-01");

    // Membuat subfolder dan menambahkan file ke dalamnya
    Folder* sub1 = createFolder("SubFolder1");
    addFile(sub1, "fileC.txt", 150, "2023-03-01");
    addFile(sub1, "fileD.txt", 250, "2023-04-01");

    // Menambahkan subfolder ke folder root
    addSubFolder(root, sub1);

    // Menampilkan struktur folder secara rekursif
    cout << "Struktur Folder:" << endl;
    printFolder(root);

    // Menampilkan array dua dimensi untuk simulasi grid data file
    displayFileGrid();

    // Mengurutkan file di folder root berdasarkan nama
    sortFilesByName(root);
    cout << "\nStruktur Folder setelah pengurutan file di Root:" << endl;
    printFolder(root);

    // Mencari file secara rekursif
    const char* searchName = "fileC.txt";
    bool found = recursiveSearch(root, searchName);
    cout << "\nPencarian file \"" << searchName << "\": " << (found ? "Ditemukan" : "Tidak Ditemukan") << endl;

    // Menyimpan struktur folder ke file (operasi file)
    ofstream outFile("folder_structure.txt");
    if (outFile.is_open()) {
        saveFolderToFile(root, outFile);
        outFile.close();
        cout << "\nStruktur folder telah disimpan ke file folder_structure.txt" << endl;
    } else {
        cout << "\nGagal membuka file untuk penulisan." << endl;
    }

    // Catatan: Untuk aplikasi nyata, pastikan untuk menghapus (delete) semua alokasi memori secara rekursif.
    // Di sini, untuk kesederhanaan, pembersihan memori tidak dilakukan sepenuhnya.

    return 0;
}
