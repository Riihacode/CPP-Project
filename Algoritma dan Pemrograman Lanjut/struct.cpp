/*#include <iostream>
#include <string.h>
using namespace std;
int main()
{
struct data_tanggal
{
int tanggal, bulan, tahun;
};
struct data_rekan
{
char nama[30];
struct data_tanggal tgl_lahir;
};
struct data_rekan info_rekan;
strcpy(info_rekan.nama, "Mr. Sumanto");
info_rekan.tgl_lahir.tanggal = 3;
info_rekan.tgl_lahir.bulan = 11;
info_rekan.tgl_lahir.tahun = 1968;
cout << "Nama : " << info_rekan.nama << endl;
cout << "Tanggal lahir : " << info_rekan.tgl_lahir.tanggal
<< "-" << info_rekan.tgl_lahir.bulan
<< "-" << info_rekan.tgl_lahir.tahun << endl;
getchar();
}
*/
#include <iostream>
#include <string.h>
using namespace std;
int main(){

struct data_tanggal
{
    int tanggal, bulan, tahun;
};
    struct data_rekan
{
    char nama[30];
    struct data_tanggal tgl_lahir;
};
    struct data_rekan info_rekan;
    strcpy(info_rekan.nama, "Mr. Sumanto");
    info_rekan.tgl_lahir.tanggal = 3;
    info_rekan.tgl_lahir.bulan = 11;
    info_rekan.tgl_lahir.tahun = 1968;
    cout << "Nama : " << info_rekan.nama << endl;
    cout << "Tanggal lahir : " << info_rekan.tgl_lahir.tanggal
    << "-" << info_rekan.tgl_lahir.bulan
    << "-" << info_rekan.tgl_lahir.tahun << endl;
    getchar();
}
