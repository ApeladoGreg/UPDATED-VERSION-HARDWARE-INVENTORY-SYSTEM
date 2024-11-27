#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Item {
  string name;
  int quantity;
  double price;
  string description;
};

void addItem(vector<Item>& inventory) {
  Item item;
  cout << "Enter item name: ";
  cin >> item.name;
  cout << "Enter item quantity: ";
  cin >> item.quantity;
  cout << "Enter item price: ";
  cin >> item.price;
  cout << "Enter item description: ";
  cin.ignore(); 
  getline(cin, item.description);
  inventory.push_back(item);
  cout << "Item added successfully!\n";
}

void removeItem(vector<Item>& inventory) {
  string itemName;
  cout << "Enter item name to remove: ";
  cin >> itemName;
  for (int i = 0; i < inventory.size(); i++) {
    if (inventory[i].name == itemName) {
      inventory.erase(inventory.begin() + i);
      cout << "Item removed successfully!\n";
      return;
    }
  }
  cout << "Item not found!\n";
}

void searchItem(const vector<Item>& inventory) {
    string itemName;
    cout << "Enter item name to search: ";
    cin >> itemName;

    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory[i].name == itemName) {
            cout << "Item found:\n";
            cout << "Name: " << inventory[i].name << endl;
            cout << "Quantity: " << inventory[i].quantity << endl;
            cout << "Price: " << inventory[i].price << endl;
            cout << "Description: " << inventory[i].description << endl;
            return;
        }
    }

    cout << "Item not found!\n";
}

void displayInventory(const vector<Item>& inventory) {
  if (inventory.empty()) {
    cout << "Inventory is empty!\n";
    return;
  }
  cout << "Inventory:\n";
  for (int i = 0; i < inventory.size(); ++i) {
    const Item& item = inventory[i];  
    cout << "Name: " << item.name << endl;
    cout << "Quantity: " << item.quantity << endl;
    cout << "Price: " << item.price << endl;
    cout << "Description: " << item.description << endl;
    cout << "--------\n";
  }
}

int main() {
  vector<Item> inventory;

  int choice;
  do {
    cout << "Output:\n";
    cout << "1. Add Item\n";
    cout << "2. Remove Item\n";
    cout << "3. Search Item\n";
    cout << "4. Display Inventory\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        addItem(inventory);
        break;
      case 2:
        removeItem(inventory);
        break;
      case 3:
        searchItem(inventory);
        break;
      case 4:
        displayInventory(inventory);
        break;
      case 5:
        cout << "Exiting program...\n";
        break;
      default:
        cout << "Invalid choice!\n";
    }
  } while (choice != 5);

  return 0;
}
