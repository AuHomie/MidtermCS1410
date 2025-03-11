#include <iostream>
using namespace std;
#include "MidtermH.h"

int main() {
    Closet myCloset;
    int choice;

    // Initial items
    myCloset.addClothing(" Prada T-Shirt", Top, MED, Black, None);
    myCloset.addClothing("Blue Star Jeans", Bottom, LRG, Blue, None);
    myCloset.addClothing("RedLeather Eddy Murphy Jacket", Jacket, XL, Red, Leather);

    // Main menu loop
    while (true) {
        cout << "\nCloset Checkout System\n";
        cout << "1. Check Out Item.\n";
        cout << "2. Return Item\n";
        cout << "3. Add New Clothing\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string person;
            cout << "Enter Item ID you wish to check out: \n";
            cin >> id;
            cout << "What is your name:  \n";
            cin.ignore();
            getline(cin, person);
            myCloset.checkOutItem(id, person);
        } 
        else if (choice == 2) {
            int id;
            cout << "Enter Item ID to return: \n";
            cin >> id;
            myCloset.returnItem(id);
        } 
        else if (choice == 3) {
            string name;
            int type, size, color, detail;
            cout << "Enter clothing brand / nick-name: \n";
            cin.ignore();
            getline(cin, name);
            cout << "What type (0 = Top, 1 = Bottom, 2 = Jacket): \n";
            cin >> type;
            cout << "What size (0 = XSM, 1 = SM, 2 = MED, 3 = LRG, 4 = XL, 5 = XXL): \n";
            cin >> size;
            cout << "What color family (0 = Black, 1 = White, 2 = Red, 3 = Orange, 4 = Yellow, 5 = Green, 6 = Blue, 7 = Violet, 8 = Multi) \n";
            cin >> color;
            cout << "Does this item have any details? 0 = None, 1 =Dots, 2 = Stripes, 3 = Pattern, 4 = Sheer, 5 = Sequins,6 =  Leather, 7 = Latex, 8 = Lace,9 =Beaded, 10 = Embroidery, 11 = Studs\n";
            cin >> detail;
             // Input validation
             if (type >= 0 && type <= 2 && size >= 0 && size <= 5 && color>=0 && color<=8 && detail>=0 && detail<=11) {
                myCloset.addClothing(name, static_cast<ClothingType>(type), static_cast<ClothingSize>(size), static_cast<ColorFam>(color),static_cast<ItemDetail>(detail));
            } else {
                cout << "Invalid input.\n";
            }
        } 
        else if (choice == 4) {
            cout << "Exiting closet program. Byeeeee! \n";
            break;  
        } 
        else {
            cout << "Invalid choice. Umm.. Somethings not right. Circle the block babe! (Try again.)\n" ;
        }
    }

    return 0;
}
