#include <iostream>
#include <string>
using namespace std;

// Linked list node for farmer requests
struct Farmer {
    int id;
    string name;
    string location;
    string crop;
    float quantity;
    Farmer* next;
};

// Linked list node for transport vehicles
struct Transport {
    int id;
    string driver;
    string location;
    float capacity;
    bool available;
    Transport* next;
};

Farmer* farmerHead = nullptr;
Transport* transportHead = nullptr;

// Add a farmer request
void addFarmer() {
    Farmer* f = new Farmer;

    cout << "Enter Farmer ID: ";
    cin >> f->id;

    cout << "Enter Farmer Name: ";
    getline(cin >> ws, f->name);

    cout << "Enter Pickup Location: ";
    getline(cin, f->location);

    cout << "Enter Crop Name: ";
    getline(cin, f->crop);

    cout << "Enter Crop Quantity (tons): ";
    cin >> f->quantity;

    if (f->quantity <= 0) {
        cout << "Quantity must be greater than zero.\n";
        delete f;
        return;
    }

    f->next = nullptr;

    if (farmerHead == nullptr) {
        farmerHead = f;
    } else {
        Farmer* temp = farmerHead;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = f;
    }

    cout << "Farmer request added successfully!\n";
}

// Add a transport vehicle
void addTransport() {
    Transport* t = new Transport;

    cout << "Enter Vehicle ID: ";
    cin >> t->id;

    cout << "Enter Driver Name: ";
    getline(cin >> ws, t->driver);

    cout << "Enter Vehicle Location: ";
    getline(cin, t->location);

    cout << "Enter Vehicle Capacity (tons): ";
    cin >> t->capacity;

    if (t->capacity <= 0) {
        cout << "Capacity must be greater than zero.\n";
        delete t;
        return;
    }

    t->available = true;
    t->next = nullptr;

    if (transportHead == nullptr) {
        transportHead = t;
    } else {
        Transport* temp = transportHead;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = t;
    }

    cout << "Transport vehicle added successfully!\n";
}

// Display farmer requests
void displayFarmers() {
    Farmer* f = farmerHead;

    if (f == nullptr) {
        cout << "\nNo farmer requests available.\n";
        return;
    }

    cout << "\n===== FARMER REQUESTS =====\n";

    while (f != nullptr) {
        cout << "ID: " << f->id
             << " | Name: " << f->name
             << " | Location: " << f->location
             << " | Crop: " << f->crop
             << " | Quantity: " << f->quantity
             << " tons\n";

        f = f->next;
    }
}

// Display transport vehicles
void displayTransport() {
    Transport* t = transportHead;

    if (t == nullptr) {
        cout << "\nNo transport vehicles registered.\n";
        return;
    }

    cout << "\n===== TRANSPORT VEHICLES =====\n";

    while (t != nullptr) {
        cout << "Vehicle ID: " << t->id
             << " | Driver: " << t->driver
             << " | Location: " << t->location
             << " | Capacity: " << t->capacity
             << " tons | Status: "
             << (t->available ? "Available" : "Booked")
             << '\n';

        t = t->next;
    }
}

// Match farmer requests with vehicles
void matchTransport() {
    if (farmerHead == nullptr) {
        cout << "\nNo farmer requests available.\n";
        return;
    }

    bool foundAny = false;
    Farmer* f = farmerHead;

    while (f != nullptr) {
        Transport* t = transportHead;
        bool matched = false;

        while (t != nullptr) {
            if (t->available &&
                t->location == f->location &&
                t->capacity >= f->quantity) {

                cout << "\n--- TRANSPORT MATCH FOUND ---\n";
                cout << "Farmer: " << f->name << '\n';
                cout << "Crop: " << f->crop << '\n';
                cout << "Quantity: " << f->quantity << " tons\n";
                cout << "Driver: " << t->driver << '\n';
                cout << "Vehicle ID: " << t->id << '\n';
                cout << "Pickup Location: " << f->location << '\n';

                t->available = false;
                matched = true;
                foundAny = true;
                break;
            }

            t = t->next;
        }

        if (!matched) {
            cout << "\nNo suitable vehicle found for "
                 << f->name << ".\n";
        }

        f = f->next;
    }

    if (!foundAny) {
        cout << "\nNo transport matches found.\n";
    }
}

// Release allocated linked-list memory
void cleanup() {
    while (farmerHead != nullptr) {
        Farmer* temp = farmerHead;
        farmerHead = farmerHead->next;
        delete temp;
    }

    while (transportHead != nullptr) {
        Transport* temp = transportHead;
        transportHead = transportHead->next;
        delete temp;
    }
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n====================================\n";
        cout << " SMART AGRICULTURE TRANSPORT SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Add Farmer Request\n";
        cout << "2. Add Transport Vehicle\n";
        cout << "3. Display Farmer Requests\n";
        cout << "4. Display Transport Vehicles\n";
        cout << "5. Match Transport\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addFarmer();
                break;

            case 2:
                addTransport();
                break;

            case 3:
                displayFarmers();
                break;

            case 4:
                displayTransport();
                break;

            case 5:
                matchTransport();
                break;

            case 6:
                cleanup();
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}
