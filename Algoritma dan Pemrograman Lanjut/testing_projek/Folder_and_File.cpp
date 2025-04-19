#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct File {
    string namaFile;
    int ukuran; // dalam KB
};

struct Folder {
    string namaFolder;
    File file[10]; // maksimal 10 file
    int jumlahFile;
    Folder* subfolder[5]; // maksimal 5 subfolder
    int jumlahSubfolder;
};

// Fungsi rekursif untuk menampilkan isi folder
void tampilkanFolder(Folder* folder, int level = 0) {
    for (int i = 0; i < level; i++) cout << "  ";
    cout << "[Folder] " << folder->namaFolder << endl;

    for (int i = 0; i < folder->jumlahFile; i++) {
        for (int j = 0; j < level + 1; j++) cout << "  ";
        cout << "- " << folder->file[i].namaFile << " (" << folder->file[i].ukuran << " KB)" << endl;
    }

    for (int i = 0; i < folder->jumlahSubfolder; i++) {
        tampilkanFolder(folder->subfolder[i], level + 1); // Rekursif ke subfolder
    }
}

// Fungsi untuk menambahkan file ke folder
void tambahFile(Folder* folder, string namaFile, int ukuran) {
    if (folder->jumlahFile < 10) {
        folder->file[folder->jumlahFile++] = { namaFile, ukuran };
    } else {
        cout << "Folder penuh!" << endl;
    }
}

// Fungsi untuk menambahkan subfolder ke folder
void tambahSubfolder(Folder* folder, string namaSubfolder) {
    if (folder->jumlahSubfolder < 5) {
        Folder* newFolder = new Folder;
        newFolder->namaFolder = namaSubfolder;
        newFolder->jumlahFile = 0;
        newFolder->jumlahSubfolder = 0;
        folder->subfolder[folder->jumlahSubfolder++] = newFolder;
    } else {
        cout << "Terlalu banyak subfolder!" << endl;
    }
}

// Fungsi rekursif untuk mencari file
void cariFile(Folder* folder, string namaCari) {
    for (int i = 0; i < folder->jumlahFile; i++) {
        if (folder->file[i].namaFile == namaCari) {
            cout << "File ditemukan di folder: " << folder->namaFolder << " -> " << folder->file[i].namaFile << endl;
        }
    }

    for (int i = 0; i < folder->jumlahSubfolder; i++) {
        cariFile(folder->subfolder[i], namaCari); // Rekursif cari di subfolder
    }
}

// Fungsi untuk mengurutkan file berdasarkan nama (Bubble Sort)
void urutkanFile(Folder* folder) {
    for (int i = 0; i < folder->jumlahFile - 1; i++) {
        for (int j = i + 1; j < folder->jumlahFile; j++) {
            if (folder->file[i].namaFile > folder->file[j].namaFile) {
                swap(folder->file[i], folder->file[j]);
            }
        }
    }
    // Rekursif sorting ke subfolder
    for (int i = 0; i < folder->jumlahSubfolder; i++) {
        urutkanFile(folder->subfolder[i]);
    }
}

// Fungsi rekursif simpan data folder ke file
void simpanKeFile(Folder* folder, ofstream &file, int level = 0) {
    file << level << ",FOLDER," << folder->namaFolder << endl;
    for (int i = 0; i < folder->jumlahFile; i++) {
        file << level << ",FILE," << folder->file[i].namaFile << "," << folder->file[i].ukuran << endl;
    }
    for (int i = 0; i < folder->jumlahSubfolder; i++) {
        simpanKeFile(folder->subfolder[i], file, level + 1);
    }
}

// Fungsi statistik array 2D: hitung jumlah file & folder per level
void statistikFolder(Folder* folder, int statistik[][2], int level = 0) {
    statistik[level][1]++; // Hitung folder
    statistik[level][0] += folder->jumlahFile; // Hitung file

    for (int i = 0; i < folder->jumlahSubfolder; i++) {
        statistikFolder(folder->subfolder[i], statistik, level + 1); // Rekursif ke subfolder
    }
}

int main() {
    Folder root;
    root.namaFolder = "Root";
    root.jumlahFile = 0;
    root.jumlahSubfolder = 0;

    // Tambah file di root
    tambahFile(&root, "File1.txt", 100);
    tambahFile(&root, "File2.docx", 200);

    // Tambah subfolder di root
    tambahSubfolder(&root, "FolderA");
    tambahFile(root.subfolder[0], "FileA1.pdf", 300);
    tambahFile(root.subfolder[0], "FileA2.jpg", 400);

    // Tambah sub-subfolder
    tambahSubfolder(root.subfolder[0], "FolderA1");
    tambahFile(root.subfolder[0]->subfolder[0], "FileA1_1.pptx", 500);

    // Tampilkan semua isi
    cout << "=== Isi Folder ===" << endl;
    tampilkanFolder(&root);

    // Cari file
    cout << "\n=== Cari File ===" << endl;
    cariFile(&root, "FileA1.pdf");

    // Sorting
    urutkanFile(&root);
    cout << "\n=== Setelah Sorting ===" << endl;
    tampilkanFolder(&root);

    // Statistik (Array 2D)
    int statistik[5][2] = {0}; // [level][0=file, 1=folder]
    statistikFolder(&root, statistik);
    cout << "\n=== Statistik ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Level " << i << ": " << statistik[i][0] << " file, " << statistik[i][1] << " folder" << endl;
    }

    // Simpan ke file
    ofstream outFile("struktur_folder.txt");
    simpanKeFile(&root, outFile);
    outFile.close();
    cout << "\nData berhasil disimpan ke 'struktur_folder.txt'" << endl;

    return 0;
}
