#include <iostream>
using namespace std;
#include "MidtermH.h"

int main() {
    Closet myCloset;
    int choice;

    // Initial items
    myCloset.addClothing("Red T-Shirt", Top, MED);
    myCloset.addClothing("Blue Jeans", Bottom, LRG);
    myCloset.addClothing("Black Jacket", Jacket, XL);

    // Main menu loop
    while (true) {
        cout << "\nCloset Checkout System\n";
        cout << "1. Display Inventory\n";
        cout << "2. Check Out Item\n";
        cout << "3. Return Item\n";
        cout << "4. Add New Clothing\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            myCloset.displayInventory();
        } 
        else if (choice == 2) {
            int id;
            string person;
            cout << "Enter Item ID to check out: ";
            cin >> id;
            cout << "Enter your name: ";
            cin.ignore();
            getline(cin, person);
            myCloset.checkOutItem(id, person);
        } 
        else if (choice == 3) {
            int id;
            cout << "Enter Item ID to return: ";
            cin >> id;
            myCloset.returnItem(id);
        } 
        else if (choice == 4) {
            string name;
            int type, size;
            cout << "Enter clothing brand / nick name: ";
            cin.ignore();
            getline(cin, name);
            cout << "What type (0 = Top, 1 = Bottom, 2 = Jacket): ";
            cin >> type;
            cout << "What size (0 = XSM, 1 = SM, 2 = MED, 3 = LRG, 4 = XL, 5 = XXL): ";
            cin >> size;

            // Input validation
            if (type >= 0 && type <= 2 && size >= 0 && size <= 5) {
                myCloset.addClothing(name, static_cast<ClothingType>(type), static_cast<ClothingSize>(size));
            } else {
                cout << "Invalid type or size.\n";
            }
        } 
        else if (choice == 5) {
            cout << "Exiting closet program. Byeeeee!\n";
            break;
        } 
        else {
            cout << "Invalid choice. Umm.. Somethings not right. Try again.\n";
        }
    }

    return 0;
}
