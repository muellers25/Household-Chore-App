#ifndef CALCULATEPOINTS_H
#define CALCULATEPOINTS_H

// Calculates the total points earned from completed chores.
int calculatePoints(int points[], bool completed[], int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        if (completed[i] == true)
        {
            total += points[i];
        }
    }

    return total;
}

#endif