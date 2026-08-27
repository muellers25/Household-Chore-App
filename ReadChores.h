#ifndef READCHORES_H
#define READCHORES_H

#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Loads saved chore information from chores.txt.
void readChores(string chores[], int points[], bool completed[], int &choreCount)
{
    ifstream file("chores.txt");

    // Check whether a saved chore file exists.
    if (!file)
    {
        cout << "No chores have been saved yet.\n";
        return;
    }

    choreCount = 0;

    string line;

    // Read each saved chore until the file ends or the array is full.
    while (getline(file, line) && choreCount < 10)
    {
        stringstream ss(line);
        string chore;
        string pointValue;
        string completedValue;

        // Separate the saved values using the pipe delimiter.
        getline(ss, chore, '|');
        getline(ss, pointValue, '|');
        getline(ss, completedValue);

        chores[choreCount] = chore;
        points[choreCount] = stoi(pointValue);
        completed[choreCount] = stoi(completedValue);

        choreCount++;
    }

    file.close();

    cout << "Chores loaded successfully.\n";
}

#endif