#include <iostream>
using namespace std;
#include "MidtermH.h"

int main() {
    Closet myCloset;
    int choice;

    // Initial items
    myCloset.addClothing("Black Prada T-Shirt", Top, MED);
    myCloset.addClothing("Blue Star Jeans", Bottom, LRG);
    myCloset.addClothing("RedLeather Eddy Murphy Jacket", Jacket, XL);

    // Main menu loop
    while (true) {
        cout << "'\n'Closet Checkout System";
      
        cout << "1. Check Out Item'\n'";
        cout << "2. Return Item'\n'";
        cout << "3. Add New Clothing'\n'";
        cout << "4. Exit'\n'";
        cout << "Choose an option: '\n'";
        cin >> choice;

        if (choice == 1) {
            int id;
            string person;
            cout << "Enter Item ID you wish to check out: '\n'";
            cin >> id;
            cout << "What is your name:  '\n'";
            cin.ignore();
            getline(cin, person);
            myCloset.checkOutItem(id, person);
        } 
        else if (choice == 2) {
            int id;
            cout << "Enter Item ID to return: '\n'";
            cin >> id;
            myCloset.returnItem(id);
        } 
        else if (choice == 3) {
            string name;
            int type, size;
            cout << "Enter clothing brand / nick name: '\n'";
            cin.ignore();
            getline(cin, name);
            cout << "What type (0 = Top, 1 = Bottom, 2 = Jacket): '\n'";
            cin >> type;
            cout << "What size (0 = XSM, 1 = SM, 2 = MED, 3 = LRG, 4 = XL, 5 = XXL): '\n'";
            cin >> size;
             // Input validation
             if (type >= 0 && type <= 2 && size >= 0 && size <= 5) {
                myCloset.addClothing(name, static_cast<ClothingType>(type), static_cast<ClothingSize>(size));
            } else {
                cout << "Invalid type or size.'\n'";
            }
        } 
        else if (choice == 4) {
            cout << "Exiting closet program. Byeeeee!'\n'";
            break;  
        } 
        else {
            cout << "Invalid choice. Umm.. Somethings not right. Circle the block babe! (Try again.)'\n'" ;
        }
    }

    return 0;
}
