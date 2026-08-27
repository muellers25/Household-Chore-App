#ifndef COUNTCOMPLETED_H
#define COUNTCOMPLETED_H

// Counts how many chores are marked as completed.
int countCompleted(bool completed[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (completed[i] == true)
        {
            count++;
        }
    }

    return count;
}

#endif