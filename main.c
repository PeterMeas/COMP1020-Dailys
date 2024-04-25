/**********************************************************************
Program: Ferry Loading Simulation
Author: Peter Meas
Date: 04/20/24
Time spent: 2 hours
Purpose: Ferry loading simulation using 2 queues
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "ferryload.h"

int main(int argc, char** argv)
{
    int testCases, l, m, carLength;
    char bank[6];
    scanf("%d", &testCases);
    while (testCases--)
    {
        scanf("%d %d", &l, &m);
        QUEUE left = initQueue();
        QUEUE right = initQueue();
        for (int i = 0; i < m; i++)
        {
            scanf("%d %5c", &carLength, bank);
            if (bank[0] == 'l')
            {
                enqueue(left, carLength);
            }
            else
            {
                enqueue(right, carLength);
            }
        }
        printf("%d\n", ferryLoad(left, right, l * 100));
        free(left);
        free(right);
    }
    return 0;
}
