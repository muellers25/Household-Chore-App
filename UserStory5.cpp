#include <iostream> 
using namespace std; 

int countCompleted(bool completed[], int size) { 
    int count = 0; 

    for (int i = 0; i < size; i++) { 
        if (completed[i] == true) { 
            count++; 
        } 
    } 

    return count; 
} 

int main() { 
    bool completed[] = {true, false, true}; 

    int total = countCompleted(completed, 3); 

    cout << "Completed chores: " << total << endl; 

    return 0; 
} 