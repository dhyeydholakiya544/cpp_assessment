#include <iostream>
#include <iomanip>

// Class to represent a food item
class FoodItem {
public:
    std::string name;
    double price;

    FoodItem(std::string n, double p) : name(n), price(p) {}
};

// Class to handle food ordering and generate the bill
class FoodOrderSystem {
private:
    std::string customerName;
    double totalBill;

    // Array of available food items
    FoodItem menu[3] = {
        {"Burger", 5.99},
        {"Pizza", 8.99},
        {"Pasta", 6.99}
    };

public:
    // Constructor to initialize variables
    FoodOrderSystem() : customerName(""), totalBill(0.0) {}

    // Function to display the menu
    void displayMenu() {
        std::cout << "Menu:\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i + 1 << ". " << menu[i].name << " - $" << menu[i].price << "\n";
        }
    }

    // Function to take the order and generate the bill
    void takeOrder() {
        int choice, quantity;
        
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;

        // Validate the choice
        if (choice < 1 || choice > 3) {
            std::cout << "Invalid choice. Please try again.\n";
            return;
        }

        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        // Validate the quantity
        if (quantity <= 0) {
            std::cout << "Invalid quantity. Please try again.\n";
            return;
        }

        // Update the total bill
        totalBill += menu[choice - 1].price * quantity;

        std::cout << "Order placed successfully!\n";
    }

    // Function to display the bill
    void generateBill() {
        std::cout << "Bill for " << customerName << ":\n";
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Total Bill: $" << totalBill << "\n";
    }

    // Function to start the food ordering process
    void startOrdering() {
        std::cout << "Enter your name: ";
        std::cin >> customerName;

        char continueOrder;
        do {
            displayMenu();
            takeOrder();
            
            std::cout << "Do you want to continue ordering? (Y/N): ";
            std::cin >> continueOrder;

        } while (continueOrder == 'Y' || continueOrder == 'y');

        generateBill();
    }
};

int main() {
    FoodOrderSystem orderSystem;
    orderSystem.startOrdering();

    return 0;
}
