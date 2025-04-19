#include <iostream>
#include <string>
using namespace std;

// Struktur untuk menyimpan informasi file
struct FileInfo {
    string name;
    int size;
    string dateModified;
};

// Struktur untuk folder yang berisi file dan subfolder
struct Folder {
    string name;
    FileInfo* files;      // Array dinamis (satu dimensi) untuk file
    int fileCount;
    Folder** subFolders;  // Array dinamis (satu dimensi) untuk pointer ke subfolder
    int subFolderCount;
};

// Fungsi untuk membuat folder baru
Folder* createFolder(const string &name) {
    Folder* folder = new Folder;
    folder->name = name;
    folder->files = nullptr;
    folder->fileCount = 0;
    folder->subFolders = nullptr;
    folder->subFolderCount = 0;
    return folder;
}

// Fungsi untuk menambahkan file ke dalam folder
void addFile(Folder* folder, const string &fileName, int size, const string &date) {
    // Membuat array baru dengan ukuran fileCount + 1
    FileInfo* newFiles = new FileInfo[folder->fileCount + 1];
    for (int i = 0; i < folder->fileCount; i++) {
        newFiles[i] = folder->files[i];
    }
    // Menambahkan file baru
    newFiles[folder->fileCount].name = fileName;
    newFiles[folder->fileCount].size = size;
    newFiles[folder->fileCount].dateModified = date;
    
    // Menghapus array lama (jika ada)
    if (folder->files != nullptr) {
        delete[] folder->files;
    }
    folder->files = newFiles;
    folder->fileCount++;
}

// Fungsi untuk menambahkan subfolder ke dalam folder
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

// Fungsi rekursif untuk mencetak struktur folder dan file
void printFolder(Folder* folder, int level = 0) {
    for (int i = 0; i < level; i++) 
        cout << "  ";
    cout << "Folder: " << folder->name << endl;
    
    for (int i = 0; i < folder->fileCount; i++) {
        for (int j = 0; j < level + 1; j++) 
            cout << "  ";
        cout << "File: " << folder->files[i].name 
             << " | Size: " << folder->files[i].size 
             << " | Date: " << folder->files[i].dateModified << endl;
    }
    
    for (int i = 0; i < folder->subFolderCount; i++) {
        printFolder(folder->subFolders[i], level + 1);
    }
}

// Fungsi pencarian: mencari file berdasarkan nama di folder (tidak rekursif)
int searchFile(Folder* folder, const string &fileName) {
    for (int i = 0; i < folder->fileCount; i++) {
        if (folder->files[i].name == fileName)
            return i;
    }
    return -1;
}

// Fungsi rekursif untuk mencari file dalam folder dan subfolder
bool recursiveSearch(Folder* folder, const string &fileName) {
    if (searchFile(folder, fileName) != -1)
        return true;
    for (int i = 0; i < folder->subFolderCount; i++) {
        if (recursiveSearch(folder->subFolders[i], fileName))
            return true;
    }
    return false;
}

// Fungsi sorting: mengurutkan file berdasarkan nama (Bubble Sort)
void sortFilesByName(Folder* folder) {
    for (int i = 0; i < folder->fileCount - 1; i++) {
        for (int j = 0; j < folder->fileCount - i - 1; j++) {
            if (folder->files[j].name > folder->files[j + 1].name) {
                FileInfo temp = folder->files[j];
                folder->files[j] = folder->files[j + 1];
                folder->files[j + 1] = temp;
            }
        }
    }
}

// Contoh penggunaan array dua dimensi: menampilkan grid data file
void displayFileGrid() {
    const int rows = 3;
    const int cols = 3;
    // Array dua dimensi berisi data file [Nama, Ukuran, Tanggal]
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

int main() {
    // Membuat folder root dan menambahkan file serta subfolder
    Folder* root = createFolder("Root");
    addFile(root, "fileB.txt", 200, "2023-02-01");
    addFile(root, "fileA.txt", 100, "2023-01-01");
    
    Folder* sub1 = createFolder("SubFolder1");
    addFile(sub1, "fileC.txt", 150, "2023-03-01");
    addSubFolder(root, sub1);
    
    // Menampilkan struktur folder secara rekursif
    cout << "Struktur Folder:" << endl;
    printFolder(root);
    
    // Mengurutkan file di folder root berdasarkan nama
    sortFilesByName(root);
    cout << "\nStruktur Folder setelah sorting file di Root:" << endl;
    printFolder(root);
    
    // Pencarian file secara rekursif
    string searchName = "fileC.txt";
    bool found = recursiveSearch(root, searchName);
    cout << "\nPencarian file \"" << searchName << "\": " 
         << (found ? "Ditemukan" : "Tidak Ditemukan") << endl;
    
    // Menampilkan contoh array dua dimensi
    displayFileGrid();
    
    return 0;
}
