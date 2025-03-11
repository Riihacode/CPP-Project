#include <iostream>
#include <string>

using namespace std;

const int MAX_ARRAY = 10;
void dataInput(int &indexPosition);
void dataShow();

struct Student{
    string name;
    int 
        id, 
        age;
};

Student student[MAX_ARRAY];
const int indexPositionDefault = 0;

int main() {
    int chooseMenu;
    int indexPositionForRun = 0; // i have to input it on array so it have to be started wiith zero first
    string validateExit;

    do { 
        cout << "=============================="    << endl;
        cout << "1. Input Data"                     << endl;
        cout << "2. Show Data"                      << endl;
        cout << "3. Exit"                           << endl;
        cout << "=============================="    << endl;
        cout << "Choose the option above : ";
        cin >> chooseMenu;

        switch (chooseMenu)
        {
            case 1:
                dataInput(indexPositionForRun);
                validateExit = "No";  // parameter on while has validateExit to run this do-while looping, if you not define value before after the `case` is done then it going to get a Null Pointer Exception which is force close
                break;

            case 2:
                dataShow();
                validateExit = "No";  
                break;
            
            case 3:
                cout << "Do you wanna exit (Y/N)? ";
                cin >> validateExit;
                cout << "Thank you!";
                break;

            default:
                break;
        }
    } while (
        chooseMenu !=3 
        && (
            validateExit == "N" 
            || validateExit == "n" 
            || validateExit == "No" 
            || validateExit == "no" 
            || validateExit == "nO"
        )
    );
}

void dataInput(int &indexPosition){
    if (indexPosition < MAX_ARRAY) {
        // id struct
        student[indexPosition].id = indexPosition + 1; // acsess it and give itself with value

        cin.ignore();       //clear buffer character bcs cin allways implement new character after we done input with cin implicitly 

        // name struct
        cout << "input your name = ";
        getline(cin, student[indexPosition].name); 

        // age
        cout << "input your age = ";
        cin >> student[indexPosition].age;   
        
        indexPosition++;
    } else {
        cout << "Maximum student limit was already reached" << endl;
    }
}

void dataShow() {
    for(int i = 0; i < sizeof(student) / sizeof(student[0]) ; i ++) {
        cout<< "ID: " << student[i].id
            << ", Name: " << student[i].name
            << ", Age : " << student[i].age;
                    
        cout << endl;
    }
}