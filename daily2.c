/***********************************************************
Author: Peter Meas
Date: 1/23/2023
Effort: 50 minutes
Purpose: To be able to play around with the left shift operator and using it with an unsigned integer through an iteration
***********************************************************/
#include <stdio.h>


int main(int argc, char* argv[])
{
    unsigned int x = 1;
    unsigned int i;

    for (i = 0; x != 0; i++)
    {
        printf("%u: %u", i, x);
        x = x<<1;
        printf("\n");
    }
    return 0;
}