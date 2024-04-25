/**********************************************************************
Program: Number Filter
Author: Peter Meas
Date: April 3rd 2024
Time spent: 2 hours 40 mins
Purpose: filter standard input , terminating by user input of -1, taking in integers up to range of 2,000,000,000
 using bit flags implementation to efficiently make use of memory
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "numberfilter.h"

int main(int argc, char** argv)
{
    BitFlags* flags = init_bit_array();
    read_bit_flags_input(flags);
    print_bit_flags(flags);
    destroy_bit_flags(flags);
    return 0;
}

