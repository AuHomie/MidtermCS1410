#include <iostream>
#include <string>
#include "MidtermH.h"

using namespace std;

int main() {
    Closet myCloset;
    int choice;

    // Initial clothing items
    myCloset.addClothing("Prada T-Shirt", Top, MED, Black, None);
    myCloset.addClothing("Blue Star Jeans", Bottom, LRG, Blue, None);
    myCloset.addClothing("Eddy Murphy Jacket", Jacket, XL, Red, Leather);

    // Initial customers
    myCloset.addCustomer("Beyoncé Knowles", "123 Star Lane", "555-1234", 1);
    myCloset.addCustomer("Taylor Swift", "456 Heartbreak Blvd", "555-5678", 2);

    while (true) {
        cout << "\nCloset Checkout System\n";
        cout << "1. Check Out Item\n";
        cout << "2. Return Item\n";
        cout << "3. Add New Clothing\n";
        cout << "4. Exit\n";
        cout << "5. Register New Customer\n";
        cout << "6. View All Customers\n";
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string person;
            cout << "Enter Item ID to check out: ";
            cin >> id;
            cin.ignore();
            cout << "Enter your name (must be a registered customer): ";
            getline(cin, person);
            myCloset.checkOutItem(id, person);
        } 
        else if (choice == 2) {
            int id;
            cout << "Enter Item ID to return: ";
            cin >> id;
            myCloset.returnItem(id);
        } 
        else if (choice == 3) {
            string name;
            int type, size, color, detail;

            cin.ignore(); // clear input buffer
            cout << "Enter clothing brand / nickname: ";
            getline(cin, name);

            cout << "What type (0 = Top, 1 = Bottom, 2 = Jacket): ";
            cin >> type;
            cout << "Size (0 = XSM, 1 = SM, 2 = MED, 3 = LRG, 4 = XL, 5 = XXL): ";
            cin >> size;
            cout << "Color (0 = Black, 1 = White, 2 = Red, 3 = Orange, 4 = Yellow, 5 = Green, 6 = Blue, 7 = Violet, 8 = Multi): ";
            cin >> color;
            cout << "Detail (0=None, 1=Dots, 2=Stripes, 3=Pattern, 4=Sheer, 5=Sequins, 6=Leather, 7=Latex, 8=Lace, 9=Beaded, 10=Embroidery, 11=Studs): ";
            cin >> detail;

            if (type >= 0 && type <= 2 &&
                size >= 0 && size <= 5 &&
                color >= 0 && color <= 8 &&
                detail >= 0 && detail <= 11) {
                myCloset.addClothing(name,
                    static_cast<ClothingType>(type),
                    static_cast<ClothingSize>(size),
                    static_cast<ColorFam>(color),
                    static_cast<ItemDetail>(detail));
            } else {
                cout << "Invalid input.\n";
            }
        } 
        else if (choice == 4) {
            cout << "Exiting closet program. Byeeeee! \n";
            break;
        } 
        else if (choice == 5) {
            string name, address, phone;
            int type;

            cin.ignore(); // clear buffer
            cout << "Enter customer full name: ";
            getline(cin, name);
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter phone number: ";
            getline(cin, phone);
            cout << "Customer type (1 = Stylist, 2 = Regular): ";
            cin >> type;

            if (type == 1 || type == 2) {
                myCloset.addCustomer(name, address, phone, type);
            } else {
                cout << "Invalid customer type.\n";
            }
        } 
        else if (choice == 6) {
            myCloset.viewCustomers();
        } 
        else {
            cout << "Invalid choice. Umm.. Something's not right. Try again.\n";
        }
    }

    return 0;
}
