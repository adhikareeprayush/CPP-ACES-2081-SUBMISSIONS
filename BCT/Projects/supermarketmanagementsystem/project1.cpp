#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Product {
    int id;
    string name;
    float price;
    int quantity;
};

vector<Product> products;

void loadProducts() {
    products.clear();
    ifstream in("products.txt");
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        Product p;
        string idStr, priceStr, qtyStr;
        getline(ss, idStr, ',');
        getline(ss, p.name, ',');
        getline(ss, priceStr, ',');
        getline(ss, qtyStr);
        p.id = stoi(idStr);
        p.price = stof(priceStr);
        p.quantity = stoi(qtyStr);
        products.push_back(p);
    }
    in.close();
}

void saveProducts() {
    ofstream out("products.txt");
    for (auto& p : products)
        out << p.id << "," << p.name << "," << p.price << "," << p.quantity << "\n";
    out.close();
}

void displayProducts() {
    cout << "\n+----------+--------------------+----------+----------+\n";
    cout << "| " << setw(8) << left << "ID"
         << "| " << setw(18) << left << "Name"
         << "| " << setw(8) << left << "Price"
         << "| " << setw(8) << left << "Quantity" << "|\n";
    cout << "+----------+--------------------+----------+----------+\n";

    for (const auto& p : products) {
        cout << "| " << setw(8) << left << p.id
             << "| " << setw(18) << left << p.name.substr(0, 18)
             << "| " << setw(8) << fixed << setprecision(2) << p.price
             << "| " << setw(8) << left << p.quantity << "|\n";
    }

    cout << "+----------+--------------------+----------+----------+\n";
}

void addProduct() {
    Product p;
    cout << "Enter product ID: ";
    cin >> p.id;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, p.name);
    cout << "Enter price: ";
    cin >> p.price;
    cout << "Enter quantity: ";
    cin >> p.quantity;
    products.push_back(p);
    saveProducts();
    cout << "Product added.\n";
}

void editProduct() {
    int id;
    cout << "Enter product ID to edit: ";
    cin >> id;
    for (auto& p : products) {
        if (p.id == id) {
            cout << "Editing " << p.name << "...\n";
            cout << "Enter new name: "; cin.ignore(); getline(cin, p.name);
            cout << "Enter new price: "; cin >> p.price;
            cout << "Enter new quantity: "; cin >> p.quantity;
            saveProducts();
            cout << "Product updated.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void deleteProduct() {
    int id;
    cout << "Enter product ID to delete: ";
    cin >> id;
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->id == id) {
            products.erase(it);
            saveProducts();
            cout << "Product deleted.\n";
            return;
        }
    }
    cout << "Product not found.\n";
}

void generateBill() {
    float total = 0;
    char cont;

    struct BillItem {
        int id;
        string name;
        float price;
        int quantity;
    };

    vector<BillItem> billItems;

    do {
        int id, qty;
        cout << "Enter Product ID: "; cin >> id;
        cout << "Enter Quantity: "; cin >> qty;
        bool found = false;
        for (auto& p : products) {
            if (p.id == id) {
                if (p.quantity >= qty) {
                    float cost = qty * p.price;
                    total += cost;
                    billItems.push_back({p.id, p.name, p.price, qty});
                    p.quantity -= qty;
                    found = true;
                } else {
                    cout << "Not enough stock. Available: " << p.quantity << endl;
                    found = true;
                }
                break;
            }
        }
        if (!found) cout << "Product not found.\n";
        cout << "Add more? (y/n): "; cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    saveProducts();

    cout << "\n+--------------------------------------------+\n";
    cout << "|              ERC SUPERMARKET               |\n";
    cout << "|              🧾 BILL RECEIPT               |\n";
    cout << "+------------+----------------+--------+-----+\n";
    cout << "| Item ID    | Item Name      | Price  | Qty |\n";
    cout << "+------------+----------------+--------+-----+\n";

    for (const auto& item : billItems) {
        cout << "| " << setw(10) << left << item.id
             << "| " << setw(16) << left << item.name.substr(0, 16)
             << "| " << setw(6) << fixed << setprecision(2) << item.price
             << " | " << setw(3) << item.quantity << " |\n";
    }

    cout << "+------------+----------------+--------+-----+\n";

    cout << "| " << setw(30) << right << "TOTAL"
         << " Rs. " << setw(7) << fixed << setprecision(2) << total << " |\n";

    cout << "+--------------------------------------------+\n";

    cout << "         Thank you for shopping with us!\n";
}

void adminMenu() {
    int choice;
    do {
        cout << "\n--- ADMIN MENU ---\n";
        cout << "1. Add Product\n2. Edit Product\n3. Delete Product\n4. View Products\n5. Logout\n";
        cout << "Choice: "; cin >> choice;
        switch (choice) {
            case 1: addProduct(); break;
            case 2: editProduct(); break;
            case 3: deleteProduct(); break;
            case 4: displayProducts(); break;
            case 5: return;
            default: cout << "Invalid choice.\n";
        }
    } while (true);
}

void cashierMenu() {
    int choice;
    do {
        cout << "\n--- CASHIER MENU ---\n";
        cout << "1. View Products\n2. Generate Bill\n3. Logout\n";
        cout << "Choice: "; cin >> choice;
        switch (choice) {
            case 1: displayProducts(); break;
            case 2: generateBill(); break;
            case 3: return;
            default: cout << "Invalid choice.\n";
        }
    } while (true);
}

int main() {
    loadProducts();
    int mainChoice;
    while (true) {
        cout << "\n====== SUPERMARKET SYSTEM ======\n";
        cout << "1. Admin Menu\n2. Cashier Menu\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        if (mainChoice == 1)
            adminMenu();
        else if (mainChoice == 2)
            cashierMenu();
        else if (mainChoice == 3)
            break;
        else
            cout << "Invalid choice.\n";
    }
    return 0;
}
