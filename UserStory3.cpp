#include <iostream> 
#include <fstream> 
using namespace std; 

 void saveChore(string chore) { 
    ofstream file("chores.txt", ios::app); 

    file << chore << endl; 

    file.close(); 

    cout << "Chore saved successfully.\n"; 
} 

int main() { 
    saveChore("Wash dishes"); 
    return 0; 
} 