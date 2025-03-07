#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct Pesanan {
    string namaItem;
    int hargaPerItem;
    int jumlah;
};

// Array untuk menu makanan
string ayam[] = {"Ayam goreng kampung", "Ayam bakar kampung", "Ayam goreng negri", "Ayam bakar negri"};
string ikan[] = {"Ikan lele goreng", "Ikan lele bakar", "Ikan nila goreng", "Ikan nila bakar", "Ikan bawal goreng", "Ikan bawal bakar", "Ikan gurami goreng", "Ikan gurami bakar"};
string bebek[] = {"Bebek goreng", "Bebek bakar"};
string cumi[] = {"Cumi goreng tanpa tepung", "Cumi goreng tepung", "Cumi bakar"};
string udang[] = {"Udang goreng tanpa tepung", "Udang goreng tepung", "Udang bakar"};
string sambal[] = {"Sambal bawang", "Sambel terasi", "Sambal matah", "Sambal mangga", "Sambal tomat", "Sambal hijau", "Sambal pete"};

// Array untuk menu minuman
string minuman[] = {"Es Teh Manis", "Teh Panas", "Es Jeruk", "Jeruk Panas", "Air Mineral", "Kopi", "Es Kopi Susu"};
int hargaMinuman[] = {5000, 4000, 7000, 6000, 3000, 10000, 12000};

// Harga makanan
int hargaAyam[] = {20000, 22000, 18000, 20000};
int hargaIkan[] = {15000, 17000, 14000, 16000, 18000, 20000, 22000, 24000};
int hargaBebek[] = {25000, 27000};
int hargaCumi[] = {30000, 32000, 35000};
int hargaUdang[] = {25000, 27000, 29000};
int hargaSambal[] = {3000, 4000, 5000, 4500, 3500, 4000, 5000};

// Tempat penyimpanan pesanan
vector<Pesanan> pesanan;
int totalHarga = 0;

bool login() {
    string username, password;
    int kesempatan = 0;
    while (kesempatan < 3) {
        cout << "Masukkan Username: ";
        cin >> username;
        cout << "Masukkan Password: ";
        cin >> password;
        
        if (username == "admin" && password == "admin123") {
            cout << "Login berhasil!\n";
            system("cls");
            return true;
        } else {
            cout << "Username atau Password salah!\n";
            kesempatan++;
            cout << "kesempatan anda tersisa "<<3-kesempatan<<endl;
        }
    }
    cout << "Anda telah salah memasukkan sebanyak 3 kali. Keluar dari program.\n";
    return false;
}

int pilihJenisPesanan() {
    int pilihan;
    cout << "Pilih jenis pesanan: \n";
    cout << "1. Makan di tempat\n";
    cout << "2. Dibawa pulang\n";
    cout << "Silahkan Masukan Pilihan anda (1/2): ";
    cin >> pilihan;
    return pilihan;
}

void tampilkanRincian(int jenisPesanan) {
    cout << "\nRincian Pesanan:\n";
    for (Pesanan item : pesanan) {
        cout << "- " << item.namaItem << " x" << item.jumlah << " = Rp. " << item.hargaPerItem * item.jumlah << endl;
    }
    if (jenisPesanan == 2) {
        totalHarga += 2000; // Tambahan biaya bungkus
        cout << "Biaya tambahan bungkus: Rp. 2000\n";
    }
    cout << "Total harga: Rp. " << totalHarga << endl;
}

void pilihMinuman() {
    int pilihanItem, jumlah;

        for (int i = 0; i < 7; i++) {
            cout << i + 1 << ". " << minuman[i] << " - Rp. " << hargaMinuman[i] << endl;
        }
        cout << "Pilih menu minuman (0 untuk kembali): ";
        cin >> pilihanItem;
        if (pilihanItem > 0) {
            cout << "Masukkan jumlah pesanan: ";
            cin >> jumlah;
            pesanan.push_back({minuman[pilihanItem - 1], hargaMinuman[pilihanItem - 1], jumlah});
            totalHarga += hargaMinuman[pilihanItem - 1] * jumlah;
        }
    }


void pilihKategori(int jenisPesanan) {
    int pilihan, pilihanItem, jumlah;
    do {
        cout << "\nPilih kategori menu:\n";
        cout << "1. Ayam\n";
        cout << "2. Ikan\n";
        cout << "3. Bebek\n";
        cout << "4. Cumi\n";
        cout << "5. Udang\n";
        cout << "6. Sambal\n";
        cout << "7. Minuman\n";
        cout << "8. Selesai\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                for (int i = 0; i < 4; i++) {
                    cout << i + 1 << ". " << ayam[i] << " - Rp. " << hargaAyam[i] << endl;
                }
                cout << "Pilih menu ayam (0 untuk kembali): ";
                cin >> pilihanItem;
                if (pilihanItem > 0) {
                    cout << "Masukkan jumlah pesanan: ";
                    cin >> jumlah;
                    pesanan.push_back({ayam[pilihanItem - 1], hargaAyam[pilihanItem - 1], jumlah});
                    totalHarga += hargaAyam[pilihanItem - 1] * jumlah;
                }
                break;
            case 2:
                for (int i = 0; i < 8; i++) {
                    cout << i + 1 << ". " << ikan[i] << " - Rp. " << hargaIkan[i] << endl;
                }
                cout << "Pilih menu ikan (0 untuk kembali): ";
                cin >> pilihanItem;
                if (pilihanItem > 0) {
                    cout << "Masukkan jumlah pesanan: ";
                    cin >> jumlah;
                    pesanan.push_back({ikan[pilihanItem - 1], hargaIkan[pilihanItem - 1], jumlah});
                    totalHarga += hargaIkan[pilihanItem - 1] * jumlah;
                }
                break;
            case 3:
                for (int i = 0; i < 2; i++) {
                    cout << i + 1 << ". " << bebek[i] << " - Rp. " << hargaBebek[i] << endl;
                }
                cout << "Pilih menu bebek (0 untuk kembali): ";
                cin >> pilihanItem;
                if (pilihanItem > 0) {
                    cout << "Masukkan jumlah pesanan: ";
                    cin >> jumlah;
                    pesanan.push_back({bebek[pilihanItem - 1], hargaBebek[pilihanItem - 1], jumlah});
                    totalHarga += hargaBebek[pilihanItem - 1] * jumlah;
                }
                break;
            case 4:
                for (int i = 0; i < 3; i++) {
                    cout << i + 1 << ". " << cumi[i] << " - Rp. " << hargaCumi[i] << endl;
                }
                cout << "Pilih menu cumi (0 untuk kembali): ";
                cin >> pilihanItem;
                if (pilihanItem > 0) {
                    cout << "Masukkan jumlah pesanan: ";
                    cin >> jumlah;
                    pesanan.push_back({cumi[pilihanItem - 1], hargaCumi[pilihanItem - 1], jumlah});
                    totalHarga += hargaCumi[pilihanItem - 1] * jumlah;
                }
                break;
            case 5:
                for (int i = 0; i < 3; i++) {
                    cout << i + 1 << ". " << udang[i] << " - Rp. " << hargaUdang[i] << endl;
                }
                cout << "Pilih menu udang (0 untuk kembali): ";
                cin >> pilihanItem;
                if (pilihanItem > 0) {
                    cout << "Masukkan jumlah pesanan: ";
                    cin >> jumlah;
                    pesanan.push_back({udang[pilihanItem - 1], hargaUdang[pilihanItem - 1], jumlah});
                    totalHarga += hargaUdang[pilihanItem - 1] * jumlah;
                }
                break;
            case 6:
                for (int i = 0; i < 7; i++) {
                    cout << i + 1 << ". " << sambal[i] << " - Rp. " << hargaSambal[i] << endl;
                }
                cout << "Pilih menu sambal (0 untuk kembali): ";
                cin >> pilihanItem;
                if (pilihanItem > 0) {
                    cout << "Masukkan jumlah pesanan: ";
                    cin >> jumlah;
                    pesanan.push_back({sambal[pilihanItem - 1], hargaSambal[pilihanItem - 1], jumlah});
                    totalHarga += hargaSambal[pilihanItem - 1] * jumlah;
                }
                break;
            case 7:
                pilihMinuman();
                break;
            case 8:
                tampilkanRincian(jenisPesanan);
                break;
            default:
                cout << "Pilihan tidak valid. Silahkan coba lagi.\n";
                break;
        }
    } while (pilihan != 8);
}

int main() {
    if (login()) {
        int jenisPesanan = pilihJenisPesanan();
        pilihKategori(jenisPesanan);
    }
    return 0;
}
