#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

// Displays the main menu options for the application.
void displayMenu()
{
    cout << "\n===== Household Chore App =====\n";
    cout << "1. View Chores\n";
    cout << "2. Add Chore\n";
    cout << "3. Complete Chore\n";
    cout << "4. View Statistics\n";
    cout << "5. Save Chores\n";
    cout << "6. Load Chores\n";
    cout << "7. Exit\n";
}

#endif