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
        cout << endl << "Closet Checkout System"<< endl;
      
        cout << "1. Check Out Item"<< endl;
        cout << "2. Return Item"<< endl;
        cout << "3. Add New Clothing"<< endl;
        cout << "4. Exit"<< endl;
        cout << "Choose an option: '\n'";
        cin >> choice;

        if (choice == 1) {
            int id;
            string person;
            cout << "Enter Item ID you wish to check out: "<< endl;
            cin >> id;
            cout << "What is your name: "<< endl;
            cin.ignore();
            getline(cin, person);
            myCloset.checkOutItem(id, person);
        } 
        else if (choice == 2) {
            int id;
            cout << "Enter Item ID to return: "<< endl;
            cin >> id;
            myCloset.returnItem(id);
        } 
        else if (choice == 3) {
            string name;
            int type, size;
            cout << "Enter clothing brand / nick name: "<< endl;
            cin.ignore();
            getline(cin, name);
            cout << "What type (0 = Top, 1 = Bottom, 2 = Jacket): "<< endl;
            cin >> type;
            cout << "What size (0 = XSM, 1 = SM, 2 = MED, 3 = LRG, 4 = XL, 5 = XXL): "<< endl;
            cin >> size;
             // Input validation
             if (type >= 0 && type <= 2 && size >= 0 && size <= 5) {
                myCloset.addClothing(name, static_cast<ClothingType>(type), static_cast<ClothingSize>(size));
            } else {
                cout << "Invalid type or size."<< endl;
            }
        } 
        else if (choice == 4) {
            cout << "Exiting closet program. Byeeeee!"<< endl;
            break;  
        } 
        else {
            cout << "Invalid choice. Umm.. Somethings not right. Circle the block babe! (Try again.)" << endl;
        }
    }

    return 0;
}
