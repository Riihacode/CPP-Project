#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel integer
    int x = 42;
    
    // Mendeklarasikan pointer 'p' yang menyimpan alamat variabel 'x'
    int *p = &x;
    
    // Menampilkan nilai dari x dan alamatnya
    cout << "Nilai x: " << x << endl;
    cout << "Alamat x: " << &x << endl;
    
    // Menampilkan alamat yang disimpan di pointer p dan nilai yang ditunjuk oleh p
    cout << "Alamat yang disimpan di p: " << p << endl;
    cout << "Nilai yang ditunjuk oleh p (dereference): " << *p << endl;
    
    // Mengubah nilai x melalui pointer p
    *p = 100;
    cout << "Nilai x setelah diubah melalui pointer: " << x << endl;
    
    return 0;
}
