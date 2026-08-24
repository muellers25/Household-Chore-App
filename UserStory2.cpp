#include <iostream> 
using namespace std; 

int getOption() { 
    int choice; 

    cout << "Enter your choice: "; 
    cin >> choice; 

    if (choice >= 1 && choice <= 7) { 
        return choice; 
    } else { 
        cout << "Invalid choice.\n"; 
        return 0; 
    } 
} 

 int main() { 
    int choice = getOption(); 

    cout << "You selected: " << choice << endl; 

    return 0; 
}