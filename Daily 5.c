/***********************************************************
Author: Peter Meas
Date: 2/5/2023
Effort: 2 hours
Purpose: further messing with bitwise shifting operations, bitwise OR and bitwise AND, 
explicit casting a function, working with arrays, making sure array in bounds,
***********************************************************/

#include <stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[])
{
    unsigned int flag_holder[5] = {0}; //first int zero, all others zero default

    set_flag(flag_holder, 3);
    set_flag(flag_holder, 16);
    set_flag(flag_holder, 31);
    set_flag(flag_holder, 87);

    display_flags(flag_holder, 5);
    printf("\n\n");

    unset_flag(flag_holder, 31);
    unset_flag(flag_holder, 3);
    set_flag(flag_holder, 99);
    set_flag(flag_holder, 100);

    display_flags(flag_holder, 5);
    return 0;
}
void set_flag(unsigned int flag_holder[], int flag_position)
{
    flag_holder[flag_position/32] |= (1 << (flag_position -1));

}

void unset_flag(unsigned int flag_holder[], int flag_position)
{
    flag_holder[flag_position/32] &= ~(1 << (flag_position -1));


}

int check_flag(unsigned int flag_holder[], int flag_position)
{
    int result = flag_holder[flag_position/32] & (1 << (flag_position - 1));
    return result != 0;

}

void display_flags_as_array(unsigned int flag_holder)
{
    for (int i = 0; i<32; i++)
    {
        printf("%d", (unsigned int)check_flag(&flag_holder, i));
        if(i%4 == 3)
        {
            printf(" ");
        }
    }
    printf("\n");

}

void display_flags(unsigned int flag_holder[], int size)
{
    for (int i = 0; i < size; i++)
    {
        display_flags_as_array(flag_holder[i]);
       // printf("\n");
    }


}


