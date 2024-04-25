/***********************************************************
Author: Peter Meas
Date: 1/25/2024
Effort: 1 hour 30 minutes
Purpose: Get used to knowing when/how to use bitwise left shifts and AND/OR
***********************************************************/
#include <stdio.h>

void set_flag(int* pFlag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);

void set_flag(int* pFlag_holder, int flag_position)
{
    *pFlag_holder |= (1 << flag_position);
}

int check_flag(int flag_holder, int flag_position)
{
   int result = flag_holder  & (1 << flag_position);
   return result != 0;
}

int main(int argc, char* argv[])
{
    int flag_holder = 0;
    int i;

    set_flag(&flag_holder, 3);
    set_flag(&flag_holder, 16);
    set_flag(&flag_holder, 31);

    for(i=31; i>=0; i--)
    {
        printf("%d", check_flag(flag_holder, i));
        if(i%4 == 0)
        {
             printf(" ");
        }
    }
    printf("\n");
    return 0;
}