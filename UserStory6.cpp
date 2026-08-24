#include <iostream> 
using namespace std; 
 
int calculatePoints(int points[], bool completed[], int size) { 
    int total = 0; 

    for (int i = 0; i < size; i++) { 
        if (completed[i] == true) { 
            total += points[i]; 
        } 
    } 

     return total; 
} 
 
int main() { 
    int points[] = {10, 5, 15}; 
    bool completed[] = {true, false, true}; 

    int total = calculatePoints(points, completed, 3); 

    cout << "Total points: " << total << endl; 

    return 0; 
}