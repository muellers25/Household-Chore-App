#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_CHORES = 10;

string chores[MAX_CHORES];
bool completed[MAX_CHORES] = {false};
int choreCount = 0;

// Display main menu
void displayMenu() {
    cout << "\n===== Household Chore App =====\n";
    cout << "1. View Chores\n";
    cout << "2. Add Chore\n";
    cout << "3. Complete Chore\n";
    cout << "4. View Statistics\n";
    cout << "5. Save Chores\n";
    cout << "6. Load Chores\n";
    cout << "7. Exit\n";
}

// View all chores
void viewChores() {
    if (choreCount == 0) {
        cout << "No chores available.\n";
        return;
    }

    cout << "\nChore List:\n";

    for (int i = 0; i < choreCount; i++) {
        cout << i + 1 << ". " << chores[i];

        if (completed[i]) {
            cout << " [Completed]";
        }

        cout << endl;
    }
}

// Add a new chore
void addChore() {
    if (choreCount >= MAX_CHORES) {
        cout << "Chore list is full.\n";
        return;
    }

    cout << "Enter chore description: ";
    getline(cin, chores[choreCount]);

    completed[choreCount] = false;
    choreCount++;

    cout << "Chore added.\n";
}

// Mark a chore complete
void completeChore() {
    if (choreCount == 0) {
        cout << "No chores available.\n";
        return;
    }

    viewChores();

    int choreNumber;

    cout << "Enter chore number to complete: ";
    cin >> choreNumber;
    cin.ignore();

    if (choreNumber >= 1 && choreNumber <= choreCount) {
        completed[choreNumber - 1] = true;
        cout << "Chore marked complete.\n";
    }
    else {
        cout << "Invalid chore number.\n";
    }
}

// Display statistics
void viewStatistics() {
    int completedCount = 0;

    for (int i = 0; i < choreCount; i++) {
        if (completed[i]) {
            completedCount++;
        }
    }

    int points = completedCount * 10;

    cout << "\n===== Chore Statistics =====\n";
    cout << "Total chores: " << choreCount << endl;
    cout << "Completed chores: " << completedCount << endl;
    cout << "Points earned: " << points << endl;
}

// Save chores to file
void saveChores() {
    ofstream file("chores.txt");

    if (!file) {
        cout << "Unable to open file.\n";
        return;
    }

    for (int i = 0; i < choreCount; i++) {
        file << chores[i] << "|" << completed[i] << endl;
    }

    file.close();

    cout << "Chores saved successfully.\n";
}

// Load chores from file
void loadChores() {
    ifstream file("chores.txt");

    if (!file) {
        cout << "No saved chore file found.\n";
        return;
    }

    choreCount = 0;

    string line;

    while (getline(file, line) && choreCount < MAX_CHORES) {
        size_t separator = line.find('|');

        if (separator != string::npos) {
            chores[choreCount] = line.substr(0, separator);

            string status = line.substr(separator + 1);
            completed[choreCount] = (status == "1");

            choreCount++;
        }
    }

    file.close();

    cout << "Chores loaded successfully.\n";
}

// Main application
int main() {
    int choice;

    do {
        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            viewChores();
            break;

        case 2:
            addChore();
            break;

        case 3:
            completeChore();
            break;

        case 4:
            viewStatistics();
            break;

        case 5:
            saveChores();
            break;

        case 6:
            loadChores();
            break;

        case 7:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);

    return 0;
}