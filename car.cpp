#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Structure to represent a customer
struct Customer {
    int id;
    string name;
    string contact;
};

// Structure to represent a service
struct Service {
    int id;
    string name;
    string description;
    double cost;
};

// Structure to represent a repair order
struct RepairOrder {
    int id;
    int customerID;
    vector<int> serviceIDs;
    double totalCost;
    bool completed;
};

// Function prototypes
void addCustomer(vector<Customer>& customers); // Function to add a customer
void listCustomers(const vector<Customer>& customers);
void addService(vector<Service>& services);
void listServices(const vector<Service>& services);
void createRepairOrder(const vector<Customer>& customers, const vector<Service>& services, vector<RepairOrder>& repairOrders);
void listRepairOrders(const vector<RepairOrder>& repairOrders, const vector<Customer>& customers, const vector<Service>& services);
void completeRepairOrder(vector<RepairOrder>& repairOrders);
void saveData(const vector<Customer>& customers, const vector<Service>& services, const vector<RepairOrder>& repairOrders);
void loadData(vector<Customer>& customers, vector<Service>& services, vector<RepairOrder>& repairOrders);

// Function to display the menu options
void displayMenu() {
    cout << "Car Repair Shop Management System" << endl;
    cout << "1. Add Customer" << endl;
    cout << "2. List Customers" << endl;
    cout << "3. Add Service" << endl;
    cout << "4. List Services" << endl;
    cout << "5. Create Repair Order" << endl;
    cout << "6. List Repair Orders" << endl;
    cout << "7. Complete Repair Order" << endl;
    cout << "8. Save Data" << endl;
    cout << "9. Load Data" << endl;
    cout << "10. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
     vector<Customer> customers;
    vector<Service> services;
    vector<RepairOrder> repairOrders;
    loadData(customers, services, repairOrders); // Load data from files
    
    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Consume the newline character
        
        switch (choice) {
            case 1:
                addCustomer(customers);
                break;
            case 2:
                listCustomers(customers);
                break;
            case 3:
                addService(services);
                break;
            case 4:
                listServices(services);
                break;
            case 5:
                createRepairOrder(customers, services, repairOrders);
                break;
            case 6:
                listRepairOrders(repairOrders, customers, services);
                break;
            case 7:
                completeRepairOrder(repairOrders);
                break;
            case 8:
                saveData(customers, services, repairOrders);
                cout << "Data saved to files." << endl;
                break;
            case 9:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 9);
    
    return 0;
}

// Function to add a customer
void addCustomer(vector<Customer>& customers) {
    Customer newCustomer;
    cout << "Enter customer name: ";
    getline(cin, newCustomer.name);
    cout << "Enter customer contact details: ";
    getline(cin, newCustomer.contact);
    
    // Assign a unique ID (you can implement this logic)
    newCustomer.id = customers.size() + 1;
    
    customers.push_back(newCustomer);
    cout << "Customer added successfully." << endl;
}

// Function to list customers
void listCustomers(const vector<Customer>& customers) {
    if (customers.empty()) {
        cout << "No customers found." << endl;
        return;
    }
    
    cout << "Customer List:" << endl;
    cout << setw(5) << "ID" << setw(20) << "Name" << setw(30) << "Contact" << endl;
    for (const Customer& customer : customers) {
        cout << setw(5) << customer.id << setw(20) << customer.name << setw(30) << customer.contact << endl;
    }
}

// Function to add a service
void addService(vector<Service>& services) {
    Service newService;
    cout << "Enter service name: ";
    getline(cin, newService.name);
    cout << "Enter service description: ";
    getline(cin, newService.description);
    cout << "Enter service cost: ";
    cin >> newService.cost;
    
    // Assign a unique ID (you can implement this logic)
    newService.id = services.size() + 1;
    
    services.push_back(newService);
    cout << "Service added successfully." << endl;
}

// Function to list services
void listServices(const vector<Service>& services) {
    if (services.empty()) {
        cout << "No services found." << endl;
        return;
    }
    
    cout << "Service List:" << endl;
    cout << setw(5) << "ID" << setw(20) << "Name" << setw(40) << "Description" << setw(10) << "Cost" << endl;
    for (const Service& service : services) {
        cout << setw(5) << service.id << setw(20) << service.name << setw(40) << service.description << setw(10) << service.cost << endl;
    }
}

// Function to create a repair order
void createRepairOrder(const vector<Customer>& customers, const vector<Service>& services, vector<RepairOrder>& repairOrders) {
    if (customers.empty() || services.empty()) {
        cout << "No customers or services available. Please add customers and services first." << endl;
        return;
    }

    RepairOrder newOrder;
    cout << "Enter customer ID: ";
    cin >> newOrder.customerID;

    // Validate customer ID
    bool validCustomer = false;
    for (const Customer& customer : customers) {
        if (customer.id == newOrder.customerID) {
            validCustomer = true;
            break;
        }
    }

    if (!validCustomer) {
        cout << "Invalid customer ID. Please enter a valid customer ID." << endl;
        return;
    }

    int serviceID;
    cout << "Enter service IDs (separated by spaces, -1 to finish): ";
    while (cin >> serviceID && serviceID != -1) {
        // Validate service ID
        bool validService = false;
        for (const Service& service : services) {
            if (service.id == serviceID) {
                newOrder.serviceIDs.push_back(serviceID);
                newOrder.totalCost += service.cost;
                validService = true;
                break;
            }
        }

        if (!validService) {
            cout << "Invalid service ID. Please enter a valid service ID." << endl;
        }
    }

    newOrder.id = repairOrders.size() + 1;
    newOrder.completed = false;

    repairOrders.push_back(newOrder);
    cout << "Repair order created successfully." << endl;
}

// Function to list repair orders
void listRepairOrders(const vector<RepairOrder>& repairOrders, const vector<Customer>& customers, const vector<Service>& services) {
    if (repairOrders.empty()) {
        cout << "No repair orders found." << endl;
        return;
    }

    cout << "Repair Order List:" << endl;
    cout << setw(5) << "ID" << setw(10) << "Customer" << setw(15) << "Services" << setw(10) << "Cost" << setw(12) << "Completed" << endl;
    for (const RepairOrder& order : repairOrders) {
        // Find customer name
        string customerName;
        for (const Customer& customer : customers) {
            if (customer.id == order.customerID) {
                customerName = customer.name;
                break;
            }
        }

        // Find service names
        string serviceNames;
        for (int serviceID : order.serviceIDs) {
            for (const Service& service : services) {
                if (service.id == serviceID) {
                    if (!serviceNames.empty()) {
                        serviceNames += ", ";
                    }
                    serviceNames += service.name;
                    break;
                }
            }
        }

        cout << setw(5) << order.id << setw(10) << customerName << setw(15) << serviceNames << setw(10) << order.totalCost << setw(12) << (order.completed ? "Yes" : "No") << endl;
    }
}

// Function to complete a repair order
void completeRepairOrder(vector<RepairOrder>& repairOrders) {
    if (repairOrders.empty()) {
        cout << "No repair orders found." << endl;
        return;
    }

    int orderID;
    cout << "Enter repair order ID to complete: ";
    cin >> orderID;

    bool found = false;
    for (RepairOrder& order : repairOrders) {
        if (order.id == orderID) {
            order.completed = true;
            cout << "Repair order marked as completed." << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Repair order not found. Please enter a valid repair order ID." << endl;
    }
}

// Function to save data to files
void saveData(const vector<Customer>& customers, const vector<Service>& services, const vector<RepairOrder>& repairOrders) {
    ofstream customerFile("customers.txt");
    ofstream serviceFile("services.txt");
    ofstream repairOrderFile("repair_orders.txt");

    if (!customerFile || !serviceFile || !repairOrderFile) {
        cout << "Error opening one or more files for writing." << endl;
        return;
    }

    for (const Customer& customer : customers) {
        customerFile << customer.id << "," << customer.name << "," << customer.contact << "\n";
    }
    customerFile.close();

    for (const Service& service : services) {
        serviceFile << service.id << "," << service.name << "," << service.description << "," << service.cost << "\n";
    }
    serviceFile.close();

    for (const RepairOrder& order : repairOrders) {
        repairOrderFile << order.id << "," << order.customerID << "," << order.totalCost << "," << (order.completed ? "1" : "0");
        for (int serviceID : order.serviceIDs) {
            repairOrderFile << "," << serviceID;
        }
        repairOrderFile << "\n";
    }
    repairOrderFile.close();
}

// Function to load data from files
void loadData(vector<Customer>& customers, vector<Service>& services, vector<RepairOrder>& repairOrders) {
    ifstream customerFile("customers.txt");
    ifstream serviceFile("services.txt");
    ifstream repairOrderFile("repair_orders.txt");

    if (!customerFile || !serviceFile || !repairOrderFile) {
        cout << "One or more data files not found." << endl;
        return;
    }

    string line;
    while (getline(customerFile, line)) {
        Customer customer;
        stringstream ss(line);
        ss >> customer.id;
        getline(ss, customer.name, ',');
        getline(ss, customer.contact, ',');
        customers.push_back(customer);
    }
    customerFile.close();

    while (getline(serviceFile, line)) {
        Service service;
        stringstream ss(line);
        ss >> service.id;
        getline(ss, service.name, ',');
        getline(ss, service.description, ',');
        ss >> service.cost;
        services.push_back(service);
    }
    serviceFile.close();

    while (getline(repairOrderFile, line)) {
        RepairOrder order;
        stringstream ss(line);
        ss >> order.id >> order.customerID >> order.totalCost;
        int completedInt;
        ss >> completedInt;
        order.completed = (completedInt == 1);
        while (ss.peek() == ',') {
            ss.ignore();
            int serviceID;
            ss >> serviceID;
            order.serviceIDs.push_back(serviceID);
        }
        repairOrders.push_back(order);
    }
    repairOrderFile.close();
}
