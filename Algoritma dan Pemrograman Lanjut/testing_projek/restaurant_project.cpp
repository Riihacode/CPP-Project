#include <iostream>
#include <string>
using namespace std;

const int MENU_COUNT = 5;
const int MAX_ORDERS = 10;

struct MenuItem {
    int id;
    string name;
    double price;
};

struct Order {
    int orderId;
    int tableNumber;
    MenuItem orderedMenuItem;
    int totalQuantity;
};

struct Table {
    int tableNumber;
    bool status; // false = empty, true = occupied
};

// Recursive Function: Calculate total order cost
double calculateTotalCost(Order orders[], int count, int index) {
    if (index == count) {
        return 0;
    }

    return (
        orders[index].orderedMenuItem.price 
        * orders[index].totalQuantity
    )   + calculateTotalCost(orders, count, index + 1);
}

// Searching Function: Find menu by ID
int searchMenuById(MenuItem menu[], int n, int id) {
    for (int i = 0; i < n; i++) {
        if (menu[i].id == id) {
            return i;
        }
    }

    return -1;
}

// Sorting Function: Sort menu by price ascending
void sortMenuByPrice(MenuItem menu[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (menu[j].price > menu[j + 1].price) {
                MenuItem temp = menu[j];
                menu[j] = menu[j + 1];
                menu[j + 1] = temp;
            }
        }
    }
}

void initializedMenu(MenuItem menu[MENU_COUNT]) {
    menu = {
        {1, "Fried Rice", 25000},
        {2, "Chicken Noodles", 20000},
        {3, "Chicken Satay", 30000},
        {4, "Meatball Soup", 22000},
        {5, "Iced Tea", 10000}
    }
}

int main() {
    MenuItem menu[MENU_COUNT] = { };
    initializedMenu(menu);
    /*
    MenuItem menu[MENU_COUNT] = {
        {1, "Fried Rice", 25000},
        {2, "Chicken Noodles", 20000},
        {3, "Chicken Satay", 30000},
        {4, "Meatball Soup", 22000},
        {5, "Iced Tea", 10000}
    };
    */
    
    Order orders[MAX_ORDERS];
    int orderCount = 0;

    // 2D Array: Table status (3x3)
    Table tables[3][3];
    int tableNumber = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tables[i][j].tableNumber = tableNumber++;
            tables[i][j].status = false; // empty
        }
    }

    // 3D Array: Reservations [Day][Shift][Table]
    int reservations[7][3][3] = {0}; // 0 = no reservation

    // Main Menu
    int choice;
    do {
        cout << "\n=== Restaurant System ===" << endl;
        cout << "1. Show Menu" << endl;
        cout << "2. Sort Menu by Price" << endl;
        cout << "3. Place Order" << endl;
        cout << "4. Show Orders" << endl;
        cout << "5. Calculate Total Cost (Recursive)" << endl;
        cout << "6. Show Table Status" << endl;
        cout << "7. Exit" << endl;
        cout << "Choose: "; cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n== Menu List ==" << endl;
                for (int i = 0; i < MENU_COUNT; i++) {
                    cout << menu[i].id << ". " << menu[i].name << " - Rp" << menu[i].price << endl;
                }
                break;

            case 2:
                sortMenuByPrice(menu, MENU_COUNT);
                cout << "Menu sorted by price successfully!" << endl;
                break;

            case 3:
            {
                if (orderCount >= MAX_ORDERS) {
                    cout << "Order limit reached!" << endl;
                    break;
                }

                int menuId, quantity, tableNum;
                cout << "Enter Menu ID: "; 
                cin >> menuId;
                
                int menuIndex = searchMenuById(menu, MENU_COUNT, menuId);
                if (menuIndex == -1) {
                    cout << "Menu not found!" << endl;
                    break;
                }
                cout << "Enter Quantity: "; cin >> quantity;
                cout << "Enter Table Number (1-9): "; cin >> tableNum;

                // Update table status
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (tables[i][j].tableNumber == tableNum) {
                            tables[i][j].status = true; // occupied
                        }
                    }
                }

                // Add order
                orders[orderCount] = {orderCount + 1, tableNum, menu[menuIndex], quantity};
                orderCount++;
                cout << "Order placed successfully!" << endl;
                
                break;
            }
                
            case 4:
                cout << "\n== Order List ==" << endl;
                for (int i = 0; i < orderCount; i++) {
                    cout << "Order ID: " << orders[i].orderId
                        << ", Table: " << orders[i].tableNumber
                        << ", Menu: " << orders[i].orderedMenuItem.name
                        << ", Quantity: " << orders[i].totalQuantity
                        << ", Total: Rp" << orders[i].orderedMenuItem.price * orders[i].totalQuantity << endl;
                }
                break;

            case 5:
                cout << "Total Cost of All Orders: Rp" << calculateTotalCost(orders, orderCount, 0) << endl;
                break;

            case 6:
                cout << "\n== Table Status ==" << endl;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        cout << "Table " << tables[i][j].tableNumber << " - "
                            << (tables[i][j].status ? "Occupied" : "Empty") << endl;
                    }
                }
                break;

            case 7:
                cout << "Thank you for using our system!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 7);

    return 0;
}
