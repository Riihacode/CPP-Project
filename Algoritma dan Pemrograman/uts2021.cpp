#include <iostream>
#include <string>
using namespace std;

int main() {
    int gejala[4];  // Menyimpan jawaban gejala
    string nama_pasien;
    int no_diagnosa = 123210038;  // Nomor diagnosa
    string tgl_diagnosa = "18 Oktober 2021";  // Tanggal diagnosa statis
    
    // Input nama pasien
    cout << "Masukkan nama pasien: ";
    getline(cin, nama_pasien);
    
    // Pertanyaan gejala
    cout << "\nPertanyaan Gejala:\n";
    
    cout << "1. Apakah anda mengalami gejala [G15] tidak terasa sakit bila disentuh? (Y/T) "; 
    char input;
    cin >> input;
    if (input == 'y' || input == 'Y') gejala[0] = 15;
    else gejala[0] = 0;
    
    cout << "2. Apakah anda mengalami gejala [G05] berukuran besar? (Y/T) "; 
    cin >> input;
    if (input == 'y' || input == 'Y') gejala[1] = 5;
    else gejala[1] = 0;
    
    cout << "3. Apakah anda mengalami gejala [G11] menyebar ke bagian tubuh? (Y/T) "; 
    cin >> input;
    if (input == 'y' || input == 'Y') gejala[2] = 11;
    else gejala[2] = 0;
    
    cout << "4. Apakah anda mengalami gejala [G16] bentuknya melebar? (Y/T) "; 
    cin >> input;
    if (input == 'y' || input == 'Y') gejala[3] = 16;
    else gejala[3] = 0;
    
    // Cetak informasi diagnosa
    cout << "\nNo. Diagnosa  = " << no_diagnosa << endl;
    cout << "Tgl Diagnosa  = " << tgl_diagnosa << endl;
    cout << "Nama Pasien   = " << nama_pasien << endl;
    cout << "-----------------------------------------------------------\n";
    
    cout << "Jumlah Pertanyaan Gejala = 4\n";
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout << "HASIL DIAGNOSA PENYAKIT JERAWAT (" << nama_pasien << "):\n";
    
    // Logika untuk menentukan hasil diagnosa berdasarkan gejala yang dipilih
    if (gejala[2] == 11 && gejala[3] == 16) {
        cout << "[P088] Acne Rosacea" << endl;
    } else if (gejala[0] == 15 && gejala[1] == 5) {
        cout << "[P02] Blackheads" << endl;
    } else if (gejala[1] == 5 && gejala[2] == 11) {
        cout << "[P06] Cyst" << endl;
    } else {
        cout << "Gejala tidak sesuai dengan penyakit yang terdaftar." << endl;
    }

    return 0;
}
