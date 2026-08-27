#ifndef SAVECHORE_H
#define SAVECHORE_H

#include <fstream>
#include <string>
using namespace std;

// Saves chore names, point values, and completion status to chores.txt.
void saveChores(string chores[], int points[], bool completed[], int choreCount)
{
    ofstream file("chores.txt");

    // Check that the file opened successfully.
    if (!file)
    {
        cout << "Error opening file.\n";
        return;
    }

    // Write each chore and its related data to the file.
    for (int i = 0; i < choreCount; i++)
    {
        file << chores[i] << "|"
             << points[i] << "|"
             << completed[i] << endl;
    }

    file.close();

    cout << "Chores saved successfully.\n";
}

#endif