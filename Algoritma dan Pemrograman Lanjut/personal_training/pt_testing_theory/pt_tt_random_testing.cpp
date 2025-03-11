#include <iostream>
#include <string>
using namespace std;

//############################################
// Constraint Declaration For Array 2D
const int MAX_ARRAY = 50;
const int OUTSIDE = 5;
const int INSIDE = 10;



//############################################
// Struct Declaration (been using re-definition as a paramareter on function)
struct DetailId {
    string classId = "A";
    string id[OUTSIDE][INSIDE];
};

struct Customer {
    DetailId idDetail;
    string name;
    int age;
};



//############################################
// Re-definition of all function (for the main core of bussiness logic)
// -------------------------------------------
// Menu 1
void generateDataDummy(
    Customer customers[OUTSIDE][INSIDE], 
    int &indexOutside, 
    int &indexInside, 
    int &totalDataIndex
);
void inputByAdmin(
    Customer customers[OUTSIDE][INSIDE],
    string customerOfName,
    int customerOfAge,
    int &indexIdOutside, 
    int &indexIdInside,
    int &totalData
);

// -------------------------------------------
// Menu 2
void showAllData(Customer customers[OUTSIDE][INSIDE], int totalData);
void searchIdRecursive(
    Customer customers[OUTSIDE][INSIDE], 
    string targetId, 
    int low, 
    int high
);
void searchByName(Customer customers[OUTSIDE][INSIDE], string targetName, int totalData);
void searchByAge(Customer customers[OUTSIDE][INSIDE], int targetAge, int totalData);

// -------------------------------------------
// Menu 3
void bubbleSortById(Customer customers[OUTSIDE][INSIDE], int totalData);
void bubbleSortByName(Customer customers[OUTSIDE][INSIDE], int totalData);
void bubbleSortByAge(Customer customers[OUTSIDE][INSIDE], int totalData);
void displayCustomers(Customer customers[OUTSIDE][INSIDE], int totalData);
void swap(Customer &a, Customer &b);



//############################################
// Function Main as UI (only for user (admin) data input)
int main () {
    int chooseMenu;
    Customer customerInMenu[OUTSIDE][INSIDE] = { };
    int cIndexIdOutside = 0;
    int cIndexIdInside = 0;
    int totalData = 0;

    do {
        cout << "=====================" << endl;
        cout << "1. Input Customer Data" << endl;
        cout << "2. Searching / Show Customer Data" << endl;
        cout << "3. Sorting & Display Customer Data"<< endl;
        cout << "=====================" << endl;
        cout << "What you choose? ";
        cin >> chooseMenu;
        cout << endl;

        switch (chooseMenu)
        {
            case 1:
                {
                    int chooseMenuInMenu1;
                    cout << "=====================" << endl;
                    cout << "1. Generate dummy data" << endl;
                    cout << "2. Input by admin" << endl;
                    cout << "=====================" << endl;
                    cout << "What you choose? ";
                    cin >> chooseMenuInMenu1;
                    cout << endl;

                    switch(chooseMenuInMenu1) {
                        case 1:
                            generateDataDummy(customerInMenu, cIndexIdOutside, cIndexIdInside, totalData);
                            break;
                        
                        case 2:
                            {
                                string customerName;
                                int customerAge;

                                cin.ignore();
                                cout << "Input customer name    : ";
                                getline(cin, customerName);

                                // Age
                                cout << "Input customer age     : ";
                                cin >> customerAge;

                                inputByAdmin(customerInMenu, customerName, customerAge, cIndexIdOutside, cIndexIdInside, totalData);
                            }
                            
                            break;
                        
                        default:
                            break;
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
                    cout << endl;

                    switch (chooseMenuInsideOfMenu2)
                    {
                        case 1:
                            {
                                showAllData(customerInMenu, totalData);
                                
                            }
                            
                            break;
                        
                        case 2:
                            {
                                string searchId;
                                
                                cin.ignore(); // clear buffer
                                cout << "Enter ID to search: ";
                                getline(cin, searchId);
                                searchIdRecursive(customerInMenu, searchId, 0, totalData); // seraching from index 0 to the last index

                                cout << endl;
                                
                                break;
                            }
                            
                        case 3:
                            {
                                string searchName;

                                cin.ignore();
                                cout << "Is there any customer name you need to looking for? ";
                                getline(cin, searchName);
                                searchByName(customerInMenu, searchName, totalData);
                                cout << endl;
                            }

                            break;

                        case 4:
                            int searchAge;

                            cout << "Is there any specific customer age you need to looking for? ";
                            cin >> searchAge;
                            searchByAge(customerInMenu, searchAge, totalData);
                            cout << endl;

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
                int chooseMenuInMenu3;
                cout << "1. Display Customer Data" << endl;
                cout << "2. Sorting By ID (Bubble Sort)" << endl;
                cout << "3. Sorting By Name (Bubble Sort)" << endl;
                cout << "4. Sorting By Age (Bubble Sort)" << endl;
                cout << "What you choose? ";
                cin >> chooseMenuInMenu3;
                cout << endl;

                switch (chooseMenuInMenu3) {
                    case 1:
                        cout << "Diplay Customer Data: " << endl;
                        displayCustomers(customerInMenu, totalData);
                        cout << endl;
                        
                        break;

                    case 2:
                        cout << "Sorted by ID: " << endl;
                        bubbleSortById(customerInMenu, totalData);
                        cout << endl;

                        break;
                    
                    case 3:
                        cout << "Sorted by Name: " << endl;
                        bubbleSortByName(customerInMenu, totalData);
                        cout << endl;
                        
                        break;
                    
                    case 4:
                        cout << "Sorted by Age: " << endl;
                        bubbleSortByAge(customerInMenu, totalData);
                        cout << endl;

                        break;
                    
                    case 5:
                        /*code*/
                        break;
                    
                    default:
                        break;
                }
                break;
            
            case 4:
                cout << "Thank you!" << endl;
                break;

            default:
                break;
        }
    } while (chooseMenu !=4);

    return 0;
}



//############################################
// Bussiness Logic Core
//============================================
// Generating data dummy (just wanna filling 50 customer data fastly)
void generateDataDummy(
    Customer customers[OUTSIDE][INSIDE], 
    int &indexOutside, 
    int &indexInside, 
    int &totalDataIndex
) {
    string namesDummy[] = { "TEST A", "TEST B", "TEST C", "TEST D", "TEST E", "TEST F", "TEST G", "TEST H", "TEST I" };
    int agesDummy[] = { 65, 66, 67, 68, 69, 70, 71, 72, 73 };   // 9 Dummy Data
    int count = 0;

    if (indexOutside < OUTSIDE && indexInside < INSIDE) {
        for(int i = indexOutside; i < OUTSIDE; i++) {
            for (int j = indexInside; j < INSIDE; j++) {
                if (count >= 9 || totalDataIndex >= OUTSIDE * INSIDE) {
                    return;
                }

                // ID must unique
                // int idNumberInt = (i * INSIDE) + (j + 1); => cant be used because of needed to stop nested for bracket line code in order to add another data from sub menu on menu 1
                int idNumberInt = totalDataIndex + 1;
                string idNumberString;
                
                // validate to make sure it has `0` after `A` when the total calculation value of idNumberInt was < 10. 
                if (idNumberInt < INSIDE) {
                    idNumberString = "0" + to_string(idNumberInt);
                } else {
                    idNumberString = to_string(idNumberInt);
                }

                // Generate ID with string + string calculation by using string library (#include <string>)
                customers[indexOutside][indexInside].idDetail.id[indexOutside][indexInside] = 
                    customers[indexOutside][indexInside].idDetail.classId + idNumberString;

                customers[i][j].name = namesDummy[count];
                customers[i][j].age = agesDummy[count];

                count++;
                indexInside++;
                totalDataIndex++;

                if (indexInside >= INSIDE) {
                    indexInside = 0;
                    indexOutside++;
                }
            }
        }
    } else {
        cout << "Customer data storage was already full! ";
    }
}

//============================================
// Manual input customer data by admin (one-by-one)
void inputByAdmin(
    Customer customers[OUTSIDE][INSIDE],
    string customerOfName,
    int customerOfAge,
    int &indexIdOutside, 
    int &indexIdInside,
    int &totalData
) {
    if (indexIdOutside < OUTSIDE && indexIdInside < INSIDE) {
        // ID must unique
        int idNumberInt = (indexIdOutside * INSIDE) + (indexIdInside + 1);
        string idNumberString;
        
        // validate to make sure it has `0` after `A` when the total calculation value of idNumberInt was < 10. 
        if (idNumberInt < INSIDE) {
            idNumberString = "0" + to_string(idNumberInt);
        } else {
            idNumberString = to_string(idNumberInt);
        }

        // Generate ID with string + string calculation by using string library (#include <string>)
        customers[indexIdOutside][indexIdInside].idDetail.id[indexIdOutside][indexIdInside] = 
            customers[indexIdOutside][indexIdInside].idDetail.classId + idNumberString;

        // Name
        customers[indexIdOutside][indexIdInside].name = customerOfName;

        // Age
        customers[indexIdOutside][indexIdInside].age = customerOfAge;

        indexIdInside++;
        totalData++;
        if (indexIdInside >= INSIDE) {
            indexIdInside = 0;
            indexIdOutside++;
        }
        
        cout << endl;
    } else {
        cout << "Customer data storage was already full! ";
    }
}

//============================================
// Showing all of the customer data that has already been input
void showAllData(Customer customers[OUTSIDE][INSIDE], int totalData) {
    int counter = 0;
    for (int i = 0; i < OUTSIDE; i++) {
        for (int j = 0; j < INSIDE; j++) {
            if (counter >= totalData) break;
            cout << "ID: " << customers[i][j].idDetail.id[i][j]
            << ", Name: " << customers[i][j].name
            << ", Age: " << customers[i][j].age << endl;

            counter++;
        }

        if (counter >= totalData) break;
    }

    cout << endl;
}

//============================================
// Recursive implementation to search customer id data
void searchIdRecursive(
    Customer customers[OUTSIDE][INSIDE], 
    string targetId, 
    int low, 
    int high
) {
    if (low > high) {
        cout << "[!] Data with ID " << targetId << " not found." << endl;
        return;
    }

    // Calculating mid
    int mid = (low + high) / 2;
    int midRow = mid / INSIDE;
    int midCol = mid % INSIDE;

    // Take current ID
    string currentId = customers[midRow][midCol].idDetail.id[midRow][midCol];

    // Comparing ID with target ID
    if (currentId == targetId) {
        cout << "[FOUND] ID: " << currentId
             << ", Name: " << customers[midRow][midCol].name
             << ", Age: " << customers[midRow][midCol].age << endl;
        return; // selesai
    } 
    else if (targetId < currentId) {
        // If targert was smaller, do recursive to the left
        searchIdRecursive(customers, targetId, low, mid - 1);
    } 
    else {
        // If targert was greater, do recursive to the right
        searchIdRecursive(customers, targetId, mid + 1, high);
    }
}

//============================================
// Searching customer name with sequential search implemntation
void searchByName(Customer customers[OUTSIDE][INSIDE], string targetName, int totalData) {
    bool found = false;
    int counter = 0;

    for (int i = 0; i < OUTSIDE; i++) {
        for (int j = 0; j < INSIDE; j++) {
            if (counter >= totalData) {
                break;
            }

            if (customers[i][j].name == targetName) {
                cout << "[FOUND] ID: " << customers[i][j].idDetail.id[i][j]
                     << ", Name: " << customers[i][j].name
                     << ", Age: " << customers[i][j].age;
                
                cout << endl;

                found = true;
            }

            counter++;
        }

        if (counter >= totalData) {
            break;
        }
    }

    if (!found) {
        cout << "[NOT-FOUND] Data with 'Name " << targetName << "' was not found." << endl;
    }
}

//============================================
// Searching customer age with sequential search implemntation
void searchByAge(Customer customers[OUTSIDE][INSIDE], int targetAge, int totalData) {
    bool found = false;
    int counter = 0;

    for (int i = 0; i < OUTSIDE; i++) {
        for (int j = 0; j < INSIDE; j++) {
            if (counter >= totalData) {
                break;
            }

            if (customers[i][j].age == targetAge) {
                cout << "[FOUND] ID: " << customers[i][j].idDetail.id[i][j]
                     << ", Name: " << customers[i][j].name
                     << ", Age: " << customers[i][j].age;

                cout << endl;

                found = true;
            }

            counter++;
        }

        if (counter >= totalData) {
            break;
        }
    }

    if(!found) {
        cout << "[NOT-FOUND] Data with Age: " << targetAge << " was not found." << endl;
    }
}

//====================================
void bubbleSortById(Customer customers[OUTSIDE][INSIDE], int totalData) {
    for (int i = 0; i < totalData - 1; i++) {
        for (int j = 0; j < totalData - i - 1; j++) {
            int 
                row1 = j / INSIDE,
                col1 = j % INSIDE;
            
            int 
                row2 = (j + 1) / INSIDE,
                col2 = (j + 1) % INSIDE;
            
            if (
                customers[row1][col1].idDetail.id[row1][col1] 
                > customers[row2][col2].idDetail.id[row2][col2]
            ) {
                swap(customers[row1][col1], customers[row2][col2]);
            }
        }
    }
}

//====================================
void bubbleSortByName(Customer customers[OUTSIDE][INSIDE], int totalData) {
    for (int i = 0; i < totalData - 1; i++) {
        for (int j = 0; j < totalData - i - 1; j++) {
            int 
                row1 = j / INSIDE,
                col1 = j % INSIDE;

            int 
                row2 = (j + 1) / INSIDE,
                col2 = (j + 1) % INSIDE;
            
            if (
                customers[row1][col1].name
                > customers[row2][col2].name
            ) {
                swap(customers[row1][col1], customers[row2][col2]);
            }
        }
    }
}

//====================================
void bubbleSortByAge(Customer customers[OUTSIDE][INSIDE], int totalData) {
    for (int i = 0; i < totalData - 1; i++) {
        for (int j = 0; j < totalData - i - 1; j++) {
            int 
                row1 = j / INSIDE,
                col1 = j % INSIDE;
            
            int 
                row2 = (j + 1) / INSIDE,
                col2 = (j + 1) % INSIDE;
            
            if (
                customers[row1][col1].age
                > customers[row2][col2].age
            ) {
                swap(customers[row1][col1], customers[row2][col2]);
            }
        }
    }
}

void displayCustomers(Customer customers[OUTSIDE][INSIDE], int totalData) {
    int counter = 0;
    for (int i = 0; i < OUTSIDE; i++) {
        for (int j = 0; j < INSIDE; j++) {
            if (counter >= totalData) {
                break;
            }

            cout << "ID: " << customers[i][j].idDetail.id[i][j]
                 << ", Name: " << customers[i][j].name
                 << ", Age: " << customers[i][j].age;
                 
            cout << endl;

            counter++;
        }

        if (counter >= totalData) {
            break;
        }
    }
}



//############################################
// Utility Function
//============================================
// Utility Function for swapping
void swap(Customer &a, Customer &b) {
    Customer temp = a;
    a = b;
    b = temp;
}