#include <stdio.h>
#include <stdlib.h>
#include "numberfilter.h"

#define MAX_NUM 2000000000
#define BIT_ARRAY_SIZE ((MAX_NUM / 8) + 1)

void set_bit(BitFlags* flags, int val)
{
    int index = val / 8;
    int bit_position = val % 8;
    (*flags).bit_array[index] |= (1 << bit_position);
}

//needs to check if bit is 1;
int is_bit_set(BitFlags* flags, int val)
{
    int index = val/8;
    int bit_position = val % 8;
    unsigned char mask = (1 << bit_position);
    return (((*flags).bit_array[index] & mask) != 0);
}

BitFlags* init_bit_array(void)
{
    BitFlags* flags = (BitFlags*)malloc(sizeof(BitFlags));
    if (flags == NULL)
    {
        printf("Allocation failed");
        exit(1);
    }
    (*flags).bit_array = (unsigned char*)malloc(sizeof(unsigned char) * BIT_ARRAY_SIZE);
    if((*flags).bit_array == NULL)
    {
        printf("Allocation failed");
        exit(1);
    }
    for (int i=0; i< BIT_ARRAY_SIZE; i++)
    {
        (*flags).bit_array[i] = 0;
    }
    return flags;
}

void destroy_bit_flags(BitFlags* flags)
{
    if (flags != NULL && (*flags).bit_array != NULL)
    {
        free((*flags).bit_array);
        free(flags);
    }
}

int read_bit_flags_input(BitFlags* flags)
{
    int val;
    do {
        printf("");
        scanf("%d", &val);
        if(val >= 0 && val <= MAX_NUM) //avoid dupe && if bit is NOT set
        {
            set_bit(flags, val);
        }
    }while(val != -1);
}

void print_bit_flags(BitFlags* flags)
{
    for(int i=0; i<= MAX_NUM; i++)
    {
        if(is_bit_set(flags, i)) //iterate through bit array
        {
            printf("%d\n", i); //printing values at bit array
        }
    }
}