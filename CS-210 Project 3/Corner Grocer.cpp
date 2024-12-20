#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequency;

    // Private method to load data from input file
    void loadDataFromFile(const string& fileName) {
        ifstream inputFile(fileName);
        string item;

        if (inputFile.is_open()) {
            while (inputFile >> item) {
                itemFrequency[item]++;
            }
            inputFile.close();
        }
        else {
            cerr << "Error: Unable to open file " << fileName << endl;
        }
    }

    // Private method to write frequency data to the backup file
    void writeFrequencyToFile(const string& fileName) {
        ofstream outFile(fileName);

        if (outFile.is_open()) {
            for (const auto& entry : itemFrequency) {
                outFile << entry.first << " " << entry.second << endl;
            }
            outFile.close();
        }
        else {
            cerr << "Error: Unable to open file " << fileName << endl;
        }
    }

public:
    // Constructor that loads data and writes to backup file
    ItemTracker(const string& inputFile, const string& backupFile) {
        loadDataFromFile(inputFile);
        writeFrequencyToFile(backupFile);
    }

    // Method to search for an item and return its frequency
    void searchItemFrequency(const string& item) const {
        auto it = itemFrequency.find(item);
        if (it != itemFrequency.end()) {
            cout << "The item '" << item << "' was purchased " << it->second << " time(s)." << endl;
        }
        else {
            cout << "The item '" << item << "' was not found in the purchase records." << endl;
        }
    }

    // Method to display the frequency of all items
    void displayAllFrequencies() const {
        cout << "\nItem Purchase Frequencies:\n" << endl;
        for (const auto& entry : itemFrequency) {
            cout << entry.first << " " << entry.second << endl;
        }
    }

    // Method to display a histogram of all items
    void displayHistogram() const {
        cout << "\nItem Purchase Histogram:\n" << endl;
        for (const auto& entry : itemFrequency) {
            cout << setw(15) << left << entry.first << " " << string(entry.second, '*') << endl;
        }
    }
};

// Function to display the main menu
void displayMenu() {
    cout << "\nMenu Options:\n";
    cout << "1. Search for an item\n";
    cout << "2. Display all item frequencies\n";
    cout << "3. Display item frequency histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice (1-4): ";
}

int main() {
    ItemTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");
    int choice;
    string item;

    do {
        displayMenu();
        cin >> choice;

        // Input validation
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            cout << "\nEnter the item you wish to search for: ";
            cin >> item;
            tracker.searchItemFrequency(item);
            break;
        case 2:
            tracker.displayAllFrequencies();
            break;
        case 3:
            tracker.displayHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
