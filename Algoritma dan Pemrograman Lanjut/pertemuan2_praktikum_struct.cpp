#include <iostream>
using namespace std;

struct Gaji{
    int gajiPerHari;
    int totalGaji;
};

struct Pegawai{
    string nama, nip;
    int hariKerja;
    Gaji gaji;
};

int main () {
    Pegawai dewi;

    dewi.nama = "Dewi Octaviani";
    dewi.nip = "556563633";
    dewi.hariKerja = 24;

    dewi.gaji.gajiPerHari = 55000;
    dewi.gaji.totalGaji = ((dewi.hariKerja) * (dewi.gaji.gajiPerHari));

    /////////////////////////////
    cout << "DATA GAJI PEGAWAI"<<endl;
    cout << "Nama           : "<< dewi.nama<<endl;
    cout << "Nip            : "<< dewi.nip <<endl;
    cout << "Hari Kerja     : "<< dewi.hariKerja  <<endl;
    cout << "Gaji Perhari   : "<< dewi.gaji.gajiPerHari<<endl << endl;

    cout << "Total gaji     : " <<dewi.gaji.totalGaji;
}


/*
struct TanggalLahir{
    int hari, tahun, bulan;
    
};

struct Mahasiswa {
    string nim;
    string nama;    
    TanggalLahir tanggalLahir;
};

void perkenalan(Mahasiswa mahasiswa) {
    cout<< "halo nama saya "<< mahasiswa.nama << " nim saya " << mahasiswa.nim
        << ", tanggal lahir saya "<<mahasiswa.tanggalLahir.hari << "-" 
        << mahasiswa.tanggalLahir.bulan << "-" << mahasiswa.tanggalLahir.tahun;
}

// void ubahNamaMahasiswa(Mahasiswa mahasiswa) { mahasiswa.nama = "ardi"; };
void ubahNamaMahasiswa(Mahasiswa *mahasiswa) { mahasiswa -> nama = "ardi"; };

int main () {
    
    //Mahasiswa farhan;
    //farhan.nim = "1232301900";
    //farhan.nama = "farhannivta ramadhana";
    

    Mahasiswa farhan = Mahasiswa({.nim="1232130139", .nama="farhannivta ramadhana", .tanggalLahir=TanggalLahir(12, 6, 2003)});
    Mahasiswa arji = Mahasiswa({.nim="1232130139", .nama="arji ramadhana", .tanggalLahir=TanggalLahir(28, 7, 2003)});

    cout << farhan.nim << endl;
    cout << farhan.nama << endl;
    
}
*/

/*
int main () {
    /*
    int number[3] = {1, 2, 3};
    int matrix[2][2] = {{5, 6}, {4, 3}};

    cout << matrix[0][0] << " " << matrix [0][1] << "\n";
    cout << matrix[1][0] << " " << matrix [1][1] << "\n";
    cout << endl;

    for (int i = 0; i<2; i++) {
        for (int j = 0; j<2 ; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
  


  /////////////////////////////////////////////////////


    int matrixa[2][2] = {   {2, 3}, 
                            {3, 4}};


    int matrixb[2][2] = {   {5, 6}, 
                            {7, 8}};


    int matrixhasil[2][2];

    for (int i = 0; i<2 ; i++) {
        for (int j = 0; j<2 ; j++) {
            matrixhasil[i][j] = matrixa[i][j] + matrixb[i][j];
        }
    }

    cout << "matrix hasil = "<< endl;
    for (int i = 0; i<2 ; i++) {
        for (int j = 0; j<2 ; j++) {
           cout << matrixhasil[i][j] << " ";
        }

        cout << endl;
    }
    


    Mahasiswa farhan;
    farhan.nim = "1232301900";
    farhan.nama = "farhannivta ramadhana";

    cout << farhan.nim;
    cout << farhan.nama;
}
*/

