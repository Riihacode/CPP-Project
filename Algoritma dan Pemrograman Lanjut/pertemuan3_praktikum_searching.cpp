////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <string>

using namespace std;

int searching(int element, int *numbers, int length);

int main() {
  int numbers[20] = {20, 1,  6,  17, 23, 51, 67, 85,  91, 4,
                     2,  16, 22, 82, 76, 29, 33, 106, 3,  11};

  int searchElement = 16;

  int foundIndex =
      searching(searchElement, numbers, sizeof(numbers) / sizeof(int));
  if (foundIndex >= 0) {
    cout << to_string(searchElement) + " ditemukan pada indeks ke-" +
                to_string(foundIndex);
  } else {
    cout << to_string(searchElement) + " tidak terdapat di dalam array numbers";
  }
}

int searching(int element, int *numbers, int length) {
    for (int i = 0; i < length ; i++) {
        if (numbers[i] == element) {
            return i;
        }
    }

    return -1;
}
*/


////////////////////////////////////////////////////////////
// Penjelasan ulang dari asdos krn mayoritas pada bingung
/*
#include <iostream>
#include <string>
using namespace std;

int main () {
    int numbers[5] = { 10, 30, 20 ,50, 100 };

    for (int i = 0; i < 5; i++){
        cout <<numbers[i] << endl;
    }

    int temp = numbers[4];

    int i = 0;

    while (numbers[i] != 50) {
        i++;
    }

    numbers[4] = temp;

    if (numbers[4] != 50 && i == 4) {
        cout << "Tidak ditemukan";

    } else {
        cout << "ditemukan pada indeks ke-" + to_string(i);
    }
}
*/


/////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

int main () {
    int numbers[5] = { 1, 6, 8, 16, 20 };
    int left = 0;
    int right = 4;
    bool found = false;

    while (left<=right) {
        int mid = (left + right) / 2;

        /*
        if (numbers[mid] == 16) {
            //cout << "elemen ditemukan pada indeks ke-" + to_string(mid);
            cout << "elemen ditemukan pada indeks ke-" << mid;
            found = true;
            break;
        } 
            

        if (16 < numbers[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
        */

        if (numbers[mid] == 100) {
            //cout << "elemen ditemukan pada indeks ke-" + to_string(mid);
            cout << "elemen ditemukan pada indeks ke-" << mid;
            found = true;
            break;
        } 
            

        if (100 < numbers[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (!found) {
        cout << "elemen tidak ditemukan";
    }
}