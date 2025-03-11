#include <iostream>
#include <string>
using namespace std;

const int MAX_ARRAY = 50;
const int OUTSIDE = 5;
const int INSIDE = 10;

struct DetailId {
    string classId = "A";
    string id[OUTSIDE][INSIDE];
};

struct Customer {
    DetailId idDetail;
    string name;
    int age;
};

/*
string searchIdRecursive (Customer *customer) {
    string searchId;
    int searchIdOutside = 0;
    int searchIdInside = 0;

    cout << "What ID you want to search? ";
    getline(cin, searchId);

    if (searchIdOutside <  OUTSIDE) {
        if (searchIdInside < INSIDE) {

        } else {
        
        }

    } else {
        return searchIdRecursive()
    }
    cout << "[RESULT] Retrieve Data from ID " << searchIdIndexIteration << ": ";
}
*/

/*
void generateDataDummy(Customer customers[OUTSIDE][INSIDE], int indexOutside, int indexInside) {
    string namesDummy[] = { "TEST A", "TEST B", "TEST C", "TEST D", "TEST E", "TEST F", "TEST G", "TEST H", "TEST I" };
    int agesDummy[] = {65, 66, 67, 68, 69, 70, 71, 72, 73};

    for(int i = 0; i < indexOutside; i++) {
        for (int j = 0; j < indexInside; j++) {
            customers[i][j].idDetail = i + 1;
        }
    }
}
    */

void searchIdRecursive(Customer customers[OUTSIDE][INSIDE], string targetId, int low, int high) {
    if (low > high) {
        cout << "[!] Data with ID " << targetId << " not found." << endl;
        return;
    }

    int mid = (low + high) / 2;
    int midRow = mid / INSIDE;
    int midCol = mid % INSIDE;

    string currentId = customers[midRow][midCol].idDetail.id[midRow][midCol];

    if (currentId == targetId) {
        cout << "[FOUND] ID: " << currentId
             << ", Name: " << customers[midRow][midCol].name
             << ", Age: " << customers[midRow][midCol].age << endl;
        return;
    } else if (currentId < targetId) {
        searchIdRecursive(customers, targetId, mid + 1, high);
    } else {
        searchIdRecursive(customers, targetId, low, mid - 1);
    }
}

int main () {
    int chooseMenu;
    Customer customerInMenu[OUTSIDE][INSIDE] = { };
    int cIndexIdOutside = 0;
    int cIndexIdInside = 0;
    int totalData = 0;

    do {
        cout << "=====================" << endl;
        cout << "1. Input Customer" << endl;
        cout << "2. Search / Show Data Customer" << endl;
        cout << "3. Exit"<< endl;
        cout << "=====================" << endl;
        cout << "What you choose? ";
        cin >> chooseMenu;
        cout << endl;

        switch (chooseMenu)
        {
            case 1:
                {
                    //generateDataDummy(customerInMenu, cIndexIdOutside, cIndexIdInside);
                    if (cIndexIdOutside < OUTSIDE && cIndexIdInside < INSIDE) {
                        // ID must unique
                        int idNumberInt = (cIndexIdOutside * INSIDE) + (cIndexIdInside + 1);
                        string idNumberString;
                        
                        // validate to make sure it has `0` after `A` when the total calculation value of idNumberInt was < 10. 
                        if (idNumberInt < INSIDE) {
                            idNumberString = "0" + to_string(idNumberInt);
                        } else {
                            idNumberString = to_string(idNumberInt);
                        }

                        // Generate ID with string + string calculation by using string library (#include <string>)
                        customerInMenu[cIndexIdOutside][cIndexIdInside].idDetail.id[cIndexIdOutside][cIndexIdInside] = 
                            customerInMenu[cIndexIdOutside][cIndexIdInside].idDetail.classId + idNumberString;

                        // Name
                        cin.ignore();
                        cout << "Input your name    : ";
                        getline(cin, customerInMenu[cIndexIdOutside][cIndexIdInside].name);

                        // Age
                        cout << "Input your age     : ";
                        cin >> customerInMenu[cIndexIdOutside][cIndexIdInside].age;
                        
                        cIndexIdInside++;
                        totalData++;
                        if (cIndexIdInside >= INSIDE) {
                            // totalData += cIndexIdInside;
                            cIndexIdInside = 0;
                            cIndexIdOutside++;
                        }

                        if (cIndexIdOutside >= OUTSIDE) {
                            cIndexIdOutside = 0;
                        }
                        

                        cout << endl;
                    } else {
                        cout << "Customer data storage was already full! ";
                    }

                }
                    
                break;
            
            case 2:
                int chooseMenuInsideOfMenu2;
                
                do {
                    cout << "1. Show All Data"<< endl;
                    cout << "2. Search customer by their ID" << endl;
                    cout << "3. Search customer by their Name" << endl;
                    cout << "4. Search customer by their Age"<< endl;
                    cout << "5. Back" << endl;
                    cout << "What you choose? ";
                    cin >> chooseMenuInsideOfMenu2;

                    switch (chooseMenuInsideOfMenu2)
                    {
                        case 1:
                            {
                                int counter = 0;
                                for (int i = 0; i < OUTSIDE; i++) {
                                    for (int j = 0; j < INSIDE; j++) {
                                        if (counter >= totalData) break;
                                        cout << "ID: " << customerInMenu[i][j].idDetail.id[i][j]
                                            << ", Name: " << customerInMenu[i][j].name
                                            << ", Age: " << customerInMenu[i][j].age << endl;
                                        counter++;
                                    }
                                    if (counter >= totalData) break;
                                }
                                cout << endl;
                            }
                            
                            break;
                        
                        case 2:
                            {
                                cin.ignore(); // clear buffer
                                string searchId;
                                cout << "Enter ID to search: ";
                                getline(cin, searchId);
                                searchIdRecursive(customerInMenu, searchId, 0, totalData); // cari dari index 0 ke akhir
                                
                                break;
                            }
                            

                        case 3:
                            /* code */
                            break;

                        case 4:
                            /* code */
                            break;

                        case 5:
                            /* code */
                            break;

                        default:
                            break;
                    }
                } while (chooseMenuInsideOfMenu2 < 1 && chooseMenuInsideOfMenu2 > 5);
                
                break;

            case 3:
                cout << "Thank you!" << endl;
                break;

            default:
                break;
        }
    } while (chooseMenu !=3);
}