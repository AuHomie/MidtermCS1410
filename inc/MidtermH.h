#pragma once
#include <iostream>
#include <string>
using namespace std;


class Person {
    protected:
        string name;
        string address;
        string phone;
    public:
        Person() {}
        Person(string n, string a, string p) : name(n), address(a), phone(p) {}
    
        string getName() const { return name; }
        string getAddress() const { return address; }
        string getPhone() const { return phone; }
    
        void setName(string n) { name = n; }
        void setAddress(string a) { address = a; }
        void setPhone(string p) { phone = p; }
    
        void displayInfo() const {
            cout << "Name: " << name << ", Address: " << address << ", Phone: " << phone << endl;
        }
    };
    
    // Customer inherits from Person
    class Customer : public Person {
    private:
        int id;
        int accountType; // 1 = Stylist, 2 = Regular
    public:
        Customer() {}
        Customer(int i, int at, string n, string a, string p)
            : Person(n, a, p), id(i), accountType(at) {}
    
        int getId() const { return id; }
        int getAccountType() const { return accountType; }
    
        void displayCustomer() const {
            cout << "Customer ID: " << id << ", Account Type: " << (accountType == 1 ? "Stylist" : "Regular") << endl;
            displayInfo();
        }
    };
    
// Enum for clothing type
enum ClothingType {
    Top,
    Bottom,
    Jacket,
    Belt
};

// Enum for clothing size
enum ClothingSize {
    XSM,
    SM,
    MED,
    LRG,
    XL,
    XXL
};

// Enum for color family
enum ColorFam{
    Black,
    White,
    Red,
    Orange,
    Yellow,
    Green,
    Blue,
    Violet,
    Multi
};

//Enum for detail on item
enum ItemDetail{
    None,
    Dots,
    Stripes,
    Pattern,
    Sheer,
    Sequins,
    Leather,
    Latex,
    Lace,
    Beaded,
    Embroidery,
    Studs

};



// Struct to store closet info
struct ClothingItem {
    int id;                  // id number to each hanger
    string name;                // Clothing name and 
    ClothingType type;          // type is listed below
    ClothingSize size;          // Same for size
    ColorFam color;             // Same for color
    ItemDetail detail;          // Same for details
    bool isCheckedOut;          // yes or no if it is checked out
    string checkedOutBy;        // Name of who checked it out. 
};

// Class run the closet system
class Closet {
private:
    Customer customer[50];
    int customerCount = 0;
    int nextCustomerId = 1;

    ClothingItem inventory[100];     // closet size restrictions. (Rude) Used an Array (You can't go beyond the number. )
    int hangerCount = 0;             // Track the number of clothing items 
    int nextId = 1;                     // for the hanger id math

   
            
  
    string getType(ClothingType type) {   //to get type from the input of the user and asssine the right type from the enum but put into a string. 
        switch (type) {
            case Top: return "Top";
            case Bottom: return "Bottom";
            case Jacket: return "Jacket";
                default: return "Unknown";
        }
    }

   
    string getSize(ClothingSize size) {  // to get type from the input of the user and asssine the right size from the enumbut put into a strin. 
        switch (size) {
            case XSM: return "XSM";
            case SM: return "SM";
            case MED: return "MED";
            case LRG: return "LRG";
            case XL: return "XL";
            case XXL: return "XXL";
                default: return "Unknown";
        }
    }

    string getColor(ColorFam color){
        switch (color){
            case Black: return "Black";
            case White: return "White";
            case Red: return "Red";
            case Orange: return "Orange";
            case Yellow: return "Yellow";
            case Green: return "Green";
            case Blue: return "Blue";
            case Violet: return "Violet";
            case Multi: return "Multi";
                default: return "Unknown";
        }
    }

    string getItemDetail(ItemDetail detail){
        switch (detail){
            case None: return "None";
            case Dots: return "Dots";
            case Stripes: return "Stripes";
            case Pattern: return "Pattern";
            case Sheer: return "Sheer";
            case Sequins: return "Sequins";
            case Leather: return "Leather";
            case Latex: return "Latex";
            case Lace: return "Lace";
            case Beaded: return "Beaded";
            case Embroidery: return "Embroidery";
            case Studs: return "Studs";
                default: return "Unknown";
        }
    }

    bool isCustomerExists(string name) {
        for (int i = 0; i < customerCount; i++) {
            if (customer[i].getName() == name) return true;
        }
        return false;
    }
    
public:

void viewCustomers() const {
    cout << "\n--- Registered Customers ---\n";
    if (customerCount == 0) {
        cout << "No customers registered yet.\n";
        return;
    }

    for (int i = 0; i < customerCount; i++) {
        customer[i].displayCustomer();
    }
}

    void addCustomer(string name, string address, string phone, int accountType) {
        if (customerCount < 50) {
            customer[customerCount] = Customer(nextCustomerId++, accountType, name, address, phone);
            cout << "Added customer: " << name << " (ID: " << customer[customerCount].getId() << ")" << endl;
            customerCount++;
        } else {
            cout << "Max number of customers reached!" << endl;
        }
    }
   
    void addClothing(string name, ClothingType type, ClothingSize size, ColorFam color, ItemDetail detail) {  // function to add clothing
        if (hangerCount < 100) { // is there room in the closet?
            inventory[hangerCount].id = nextId++;    //got math help from neighbor
            inventory[hangerCount].name = name;      // adds name input to hanger
            inventory[hangerCount].type = type;      // adds tyoe to hanger
            inventory[hangerCount].size = size;      // adds size to hanger
            inventory[hangerCount].color = color;    // adds color to hanger
            inventory[hangerCount].detail = detail;  // adds detail info to hanger
            inventory[hangerCount].isCheckedOut = false;        // pre adds that the item is not checked out
            inventory[hangerCount].checkedOutBy = "None";       // pre adds that no one has checked out the item
            hangerCount++; // pre loads the next hanger 
            cout << "Added: " << name << " " << getType(type) << ", Size: " << getSize(size) << " Color: "<<getColor(color)<<", With the "<<getItemDetail(detail)<< ". "<< endl;
        } else {
            cout << "Your closet is full! Stop shopping or donate some stuff."<< endl;
        }
    }

    // checkout stuff
    void checkOutItem(int id, string personName) { // fuction passing the info in on hanger id, and name
        if (!isCustomerExists(personName)) {
            cout << "Customer not found in system!" << endl;
            return;
        }
        for (int i = 0; i < hangerCount; i++) { // loop to go over array to see if the item is checked out or not, 
            if (inventory[i].id == id) {      //
                if (!inventory[i].isCheckedOut) {    // if the hanger is not marked as cheked out (f)
                    inventory[i].isCheckedOut = true;   // it marks it as check out by changing it to true
                    inventory[i].checkedOutBy = personName; // attatches the name of who is checking it out to the hanger
                    cout << personName << "  Has checked out: " << inventory[i].name << endl; // confermation output
                } else {                            
                    cout << "It is already checked out by " << inventory[i].checkedOutBy << ". Ya snooze ya loose"<< endl; // or tells you it is gone, and who had it
                }
                return;
            }
        }
        cout << "It's not in here. Did you check the laundry'."<< endl;// or it can't find the item at all
    }

    
    void returnItem(int id) { // Function to return an item
        for (int i = 0; i < hangerCount; i++) { 
            if (inventory[i].id == id) {
                if (inventory[i].isCheckedOut) {
                    cout << inventory[i].checkedOutBy << " returned: " << inventory[i].name << endl;
                    inventory[i].isCheckedOut = false;
                    inventory[i].checkedOutBy = "None";
                } else {
                    cout << "Item was not checked out."<< endl;
                }
                return;
            }
        }
        cout << "I can't seem to find what you are looking for, The Emperors New Cloths?."<< endl;
    }


    void displayAllClothes() {
        if (hangerCount == 0) {
            cout << "Closet is empty!" << endl;
            return;
        }

        
        for (int i = 0; i < hangerCount; i++) {
            cout << "ID: " << inventory[i].id
                 << ", Name: " << inventory[i].name
                 << ", Type: " << getType(inventory[i].type)
                 << ", Size: " << getSize(inventory[i].size)
                 << ", Color: " << getColor(inventory[i].color)
                 << ", Detail: " << getItemDetail(inventory[i].detail)
                 << ", Checked Out: " << (inventory[i].isCheckedOut ? "Yes" : "No")
                 << ", By: " << inventory[i].checkedOutBy << endl;
        }
    }
 
};

