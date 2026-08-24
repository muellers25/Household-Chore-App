#include <iostream> 
#include <fstream> 
using namespace std; 

void readChores() { 
    ifstream file("chores.txt"); 
    string chore; 

    if (!file) { 
        cout << "No chores have been saved yet.\n"; 
        return; 
    } 

     while (getline(file, chore)) { 
        cout << chore << endl; 
    } 

    file.close(); 
} 
 
int main() { 
    readChores(); 
    return 0; 
} 