#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Function to add a new expense
void addExpense() {
    ofstream file("Expenses.txt", ios::app);
    if (!file) {
        cout << "Error opening file!\n";
        return;
    }

    string date, category;
    double amount;

    cout << "Enter date (YYYY-MM-DD): ";
    cin >> date;
    cout << "Enter category (Food, Transport, Shopping, etc.): ";
    cin.ignore();
    getline(cin, category);
    cout << "Enter amount: ";
    cin >> amount;

    file << date << " " << category << " " << fixed << setprecision(2) << amount << endl;
    file.close();

    cout << "Expense added successfully!\n";
}

// Function to view all recorded expenses
void viewExpenses() {
    ifstream file("Expenses.txt");
    if (!file) {
        cout << "No expenses found.\n";
        return;
    }

    string date, category;
    double amount;
    cout << "\nRecorded Expenses:\n";
    cout << "-----------------------------\n";
    cout << "Date       | Category       | Amount\n";
    cout << "-----------------------------\n";

    while (file >> date >> category >> amount) {
        cout << date << " | " << setw(12) << left << category << " | $" << fixed << setprecision(2) << amount << endl;
    }

    file.close();
}

// Function to calculate total expenses
void totalExpenses() {
    ifstream file("Expenses.txt");
    if (!file) {
        cout << "No expenses found.\n";
        return;
    }

    double total = 0, amount;
    string date, category;

    while (file >> date >> category >> amount) {
        total += amount;
    }

    file.close();
    cout << "Total Expenses: $" << fixed << setprecision(2) << total << endl;
}

// Main menu function
void menu() {
    int choice;
    do {
        cout << "\nExpense Tracker Menu\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Total Expenses\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addExpense(); break;
            case 2: viewExpenses(); break;
            case 3: totalExpenses(); break;
            case 4: cout << "Exiting... Thank you!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);
}

// Driver function
int main() {
    menu();
    return 0;
}
