// ###########################
// Pointer
#include <iostream>
using namespace std;

int main() {
    int number = 10;
    int *ptr = &number;
    int ptr = &number;

    cout << "Number value: "<< number << endl;
    cout << "Number address: " << &number << endl;
    cout << "ptr value (number address): "<< ptr << endl;
    cout << "The value of pointer that points to: " << *ptr << endl;
}