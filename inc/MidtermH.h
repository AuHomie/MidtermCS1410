#pragma once
#include <iostream>
#include <string>
using namespace std;

// Enum for clothing type
enum ClothingType {
    Top,
    Bottom,
    Jacket
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

// Struct to store closet info
struct ClothingItem {
    int id;
    string name;
    ClothingType type;
    ClothingSize size;
    bool isCheckedOut;
    string checkedOutBy;
};

// Class to manage the closet system
class Closet {
private:
    ClothingItem inventory[100];     // closet size
    int hangerCount = 0;             // Track the number of clothing items
    int nextId = 1;

  
    string getTypeString(ClothingType type) {   //to get type as a string
        switch (type) {
            case Top: return "Top";
            case Bottom: return "Bottom";
            case Jacket: return "Jacket";
            default: return "Unknown";
        }
    }

   
    string getSizeString(ClothingSize size) {  // to get size as a string
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

public:
   
    void addClothing(string name, ClothingType type, ClothingSize size) {  // add clothing
        if (hangerCount < 100) {
            inventory[hangerCount].id = nextId++;
            inventory[hangerCount].name = name;
            inventory[hangerCount].type = type;
            inventory[hangerCount].size = size;
            inventory[hangerCount].isCheckedOut = false;
            inventory[hangerCount].checkedOutBy = "None";
            hangerCount++;
            cout << "Added: " << name << " (" << getTypeString(type) 
                 << ", Size: " << getSizeString(size) << ")\n";
        } else {
            cout << "Your closet is full! Stop shopping or donate some stuff.\n";
        }
    }

    void displayInventory() { // display all items
        cout << "\nCloset Inventory:\n";
        for (int i = 0; i < hangerCount; i++) {
            cout << "ID: " << inventory[i].id
                 << " | Name: " << inventory[i].name
                 << " | Type: " << getTypeString(inventory[i].type)
                 << " | Size: " << getSizeString(inventory[i].size)
                 << " | Status: " << (inventory[i].isCheckedOut ? "Checked Out" : "Available")
                 << " | Checked Out By: " << inventory[i].checkedOutBy << "\n";
        }
    }


    // Function to checkout stuff
    void checkOutItem(int id, string personName) { 
    
        for (int i = 0; i < hangerCount; i++) {
            if (inventory[i].id == id) {
                if (!inventory[i].isCheckedOut) {
                    inventory[i].isCheckedOut = true;
                    inventory[i].checkedOutBy = personName;
                    cout << personName << "  Has checked out: " << inventory[i].name << endl;
                } else {
                    cout << "It is already checked out by " << inventory[i].checkedOutBy << ". Ya snooze ya loose";
                }
                return;
            }
        }
        cout << "It's not in here. Did you check the laundry'.\n";
    }

    
    void returnItem(int id) { // Function to return an item
        for (int i = 0; i < hangerCount; i++) {
            if (inventory[i].id == id) {
                if (inventory[i].isCheckedOut) {
                    cout << inventory[i].checkedOutBy << " returned: " << inventory[i].name << "\n";
                    inventory[i].isCheckedOut = false;
                    inventory[i].checkedOutBy = "None";
                } else {
                    cout << "Item was not checked out.\n";
                }
                return;
            }
        }
        cout << "I can't seem to find what you are looking for, The Emperors New Cloths?.\n";
    }
};

