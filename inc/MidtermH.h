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

// Struct to store clothing information
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
    ClothingItem inventory[100];   // closet size
    int itemCount = 0;             // Track the number of clothing items
    int nextId = 1;

    // Private function to get type as a string
    string getTypeString(ClothingType type) {
        switch (type) {
            case Top: return "Top";
            case Bottom: return "Bottom";
            case Jacket: return "Jacket";
            default: return "Unknown";
        }
    }

    // Private function to get size as a string
    string getSizeString(ClothingSize size) {
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
    // Function to add clothing to the closet
    void addClothing(string name, ClothingType type, ClothingSize size) {
        if (itemCount < 100) {
            inventory[itemCount].id = nextId++;
            inventory[itemCount].name = name;
            inventory[itemCount].type = type;
            inventory[itemCount].size = size;
            inventory[itemCount].isCheckedOut = false;
            inventory[itemCount].checkedOutBy = "None";
            itemCount++;
            cout << "Added: " << name << " (" << getTypeString(type) 
                 << ", Size: " << getSizeString(size) << ")\n";
        } else {
            cout << "Your closet is full! Stop shopping or donate some stuff.\n";
        }
    }

    // Function to display all items
    void displayInventory() {
        cout << "\nCloset Inventory:\n";
        for (int i = 0; i < itemCount; i++) {
            cout << "ID: " << inventory[i].id
                 << " | Name: " << inventory[i].name
                 << " | Type: " << getTypeString(inventory[i].type)
                 << " | Size: " << getSizeString(inventory[i].size)
                 << " | Status: " << (inventory[i].isCheckedOut ? "Checked Out" : "Available")
                 << " | Checked Out By: " << inventory[i].checkedOutBy << "\n";
        }
    }

    // Function to check out an item
    void checkOutItem(int id, string personName) {
        for (int i = 0; i < itemCount; i++) {
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

    // Function to return an item
    void returnItem(int id) {
        for (int i = 0; i < itemCount; i++) {
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

