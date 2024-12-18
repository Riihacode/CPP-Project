/*#include <iostream>
using namespace std;

int main() {
    int kg_mangga, banyak_mangga, bagi_mangga, sisa_banyak_mangga;

    cout<< "Anda mau beli mangga berapa kg? ";
    cin>>kg_mangga;                 // 2
    banyak_mangga = kg_mangga*2;    // 2*2 = 4
    cout << "Banyak mangga sekarang adalah "<<banyak_mangga << " buah"<<endl;
    cout << "Berapa banyak tetangga yang akan anda bagi? ";
    cin >> bagi_mangga;
    cout << "\n";
    sisa_banyak_mangga = banyak_mangga;

    for (int i=1; i <= bagi_mangga; i++ ){
        int mangga_dibagikan, anggota_keluarga, banyak_mangga_sekarang = 0;
        cout << "Berapa jumlah anggota kelu2arga ke-"<< i <<"? ";
        cin >> anggota_keluarga; 
        banyak_mangga_sekarang = sisa_banyak_mangga; 
        
        if(banyak_mangga_sekarang < banyak_mangga){
            cout << "Mangga kurang \n";
            banyak_mangga_sekarang = sisa_banyak_mangga; // i1 = 4
            sisa_banyak_mangga = 0;
        } else if (anggota_keluarga == 1 || anggota_keluarga == 2 && banyak_mangga_sekarang >= 0) {
            banyak_mangga_sekarang = banyak_mangga - 2; // i1 = 4 - 2 = 2; i2 = 2-2 = 0
            sisa_banyak_mangga = banyak_mangga_sekarang; // i1 = 2, i2 = 0
        } else if (anggota_keluarga >= 3 && banyak_mangga_sekarang >= 0){
            if (banyak_mangga_sekarang == 0) {
                banyak_mangga_sekarang = 0;
                sisa_banyak_mangga = banyak_mangga_sekarang;
            } else if (banyak_mangga_sekarang == 2 || banyak_mangga_sekarang == 1){
                banyak_mangga_sekarang = banyak_mangga - 2;
                sisa_banyak_mangga = banyak_mangga_sekarang;
            } else if (banyak_mangga_sekarang >= 3){
                banyak_mangga_sekarang = banyak_mangga - 3; 
                sisa_banyak_mangga = banyak_mangga_sekarang;
            }  else {
                cout << "Tidak valid \n";
            }
        } else {
            cout << "Tidak valid \n";
            sisa_banyak_mangga = banyak_mangga_sekarang;
        }
    }

    cout << "Sisa banyak mangga (akan dimakan sendiri) adalah " << sisa_banyak_mangga << " buah \n";
}
*/
#include <iostream>
using namespace std;

int main() {
    int kg_mangga, banyak_mangga, bagi_mangga, sisa_banyak_mangga;
    

    cout << "Anda mau beli mangga berapa kg? ";
    cin >> kg_mangga;                 // 2
    banyak_mangga = kg_mangga * 2;    // 2*2 = 4 (1 kg mangga = 2 buah)
    cout << "Banyak mangga sekarang adalah " << banyak_mangga << " buah" << endl;
    
    cout << "Berapa banyak tetangga yang akan anda bagi? ";
    cin >> bagi_mangga;
    cout << "\n";
    
    sisa_banyak_mangga = banyak_mangga;

    for (int i = 1; i <= bagi_mangga; i++) {
        int anggota_keluarga;
        cout << "Berapa jumlah anggota keluarga tetangga ke-" << i << "? ";
        cin >> anggota_keluarga;

        // Tentukan berapa mangga yang dibagikan sesuai jumlah anggota keluarga
        if (anggota_keluarga == 1 || anggota_keluarga == 2) {
            if (sisa_banyak_mangga >= 2) {
                sisa_banyak_mangga -= 2; // 2 mangga untuk keluarga 1-2 anggota
            } else {
                cout << "Mangga kurang untuk dibagikan kepada keluarga tetangga ke-" << i << endl;
                break;  // Menghentikan pembagian mangga jika kurang
            }
        } else if (anggota_keluarga >= 3) {
            if (sisa_banyak_mangga >= 3) {
                sisa_banyak_mangga -= 3; // 3 mangga untuk keluarga dengan 3+ anggota
            } else {
                cout << "Mangga kurang untuk dibagikan kepada keluarga tetangga ke-" << i << endl;
                break;  // Menghentikan pembagian mangga jika kurang
            }
        } else {
            cout << "Jumlah anggota keluarga tidak valid.\n";
        }
    }

    // Menampilkan sisa mangga
    cout << "\nSisa mangga yang akan dimakan sendiri oleh Bu Dina: " << sisa_banyak_mangga << " buah\n";

    return 0;
}
