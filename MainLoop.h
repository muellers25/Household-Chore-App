#ifndef MAINLOOP_H
#define MAINLOOP_H

#include <iostream>
#include <string>

#include "Menu.h"
#include "SaveChore.h"
#include "ReadChores.h"
#include "CountCompleted.h"
#include "CalculatePoints.h"

using namespace std;

// Controls the main program loop and connects all application functions.
void mainLoop()
{
    string chores[10];
    int points[10];
    bool completed[10];

    int choreCount = 0;
    int choice;

    do
    {
        displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

         // View all current chores.
        if (choice == 1)
        {
            cout << "\nYour Chores:\n";

            if (choreCount == 0)
            {
                cout << "No chores available.\n";
            }

            for (int i = 0; i < choreCount; i++)
            {
                cout << i + 1 << ". "
                     << chores[i]
                     << " - "
                     << points[i]
                     << " points - ";

                if (completed[i])
                {
                    cout << "Completed\n";
                }
                else
                {
                    cout << "Not Completed\n";
                }
            }
        }

        // Add a new chore and assign its point value.
        else if (choice == 2)
        {
            if (choreCount < 10)
            {
                cout << "Enter chore name: ";
                getline(cin, chores[choreCount]);

                cout << "Enter point value: ";
                cin >> points[choreCount];
                cin.ignore();

                completed[choreCount] = false;

                choreCount++;

                cout << "Chore added successfully.\n";
            }
            else
            {
                cout << "Chore list is full.\n";
            }
        }

         // Mark a selected chore as completed.
        else if (choice == 3)
        {
            if (choreCount == 0)
            {
                cout << "No chores available.\n";
            }
            else
            {
                cout << "\nSelect a chore to complete:\n";

                for (int i = 0; i < choreCount; i++)
                {
                    cout << i + 1 << ". " << chores[i] << endl;
                }

                int choreNumber;

                cout << "Enter chore number: ";
                cin >> choreNumber;
                cin.ignore();

                if (choreNumber >= 1 && choreNumber <= choreCount)
                {
                    completed[choreNumber - 1] = true;
                    cout << "Chore marked complete.\n";
                }
                else
                {
                    cout << "Invalid chore number.\n";
                }
            }
        }

         // Display completed chore count and total earned points.
        else if (choice == 4)
        {
            int completedCount =
                countCompleted(completed, choreCount);

            int totalPoints =
                calculatePoints(points, completed, choreCount);

            cout << "\nStatistics\n";
            cout << "Completed chores: "
                 << completedCount << endl;

            cout << "Total points: "
                 << totalPoints << endl;
        }

        // Save all chore data to the file.
        else if (choice == 5)
        {
            saveChores(
                chores,
                points,
                completed,
                choreCount
            );
        }

        // Load previously saved chore data.
        else if (choice == 6)
        {
            readChores(
                chores,
                points,
                completed,
                choreCount
            );
        }

        // Exit the application.
        else if (choice == 7)
        {
            cout << "Goodbye!\n";
        }

        else
        {
            cout << "Invalid choice.\n";
        }

    } while (choice != 7);
}

#endif