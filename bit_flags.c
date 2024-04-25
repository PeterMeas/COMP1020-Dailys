#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bit_flags.h"

/***********************************************************
Author: Peter Meas
Date: 3/1/24
Effort: a Week
Purpose: Get Familiar with using structs, allocating memory, explicit casting, array index, a flag system
Interface proposal: A function that can be added
 is a function that toggles the flags, a state of being 0 or 1 instead of having to check bit flags, using the check
 flag function you could just call a toggle function instead to flip the flags state
***********************************************************/

typedef struct bit_flags
{
    int size; //# of bits currently held
    int capacity; //# of bits object can hold
    unsigned int* flags;

}Bit_flags;

BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits)
{
    if (number_of_bits <= 0) return NULL;
    int capacity = ((number_of_bits + (sizeof(unsigned int) * 8 - 1)) / (sizeof(unsigned int) * 8)) * (sizeof(unsigned int) * 8);
    Bit_flags* pBit_flags = (Bit_flags*)malloc(sizeof(Bit_flags));
    if(pBit_flags == NULL)
    {
        return NULL;
    }

    pBit_flags->flags = (unsigned int*)calloc(capacity / (sizeof(unsigned int) * 8), sizeof(unsigned int));
    if (pBit_flags->flags == NULL)
    {
        return NULL;
    }

    pBit_flags->size = number_of_bits;
    pBit_flags->capacity = capacity;

    return (BIT_FLAGS)pBit_flags;
}


Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    if (flag_position < 0 || hBit_flags == NULL) return -1;
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;

    if (flag_position >= pBit_flags->size)
    {
        pBit_flags->size = flag_position + 1;
    }
    if (flag_position >= pBit_flags->capacity)
    {
        int newCap = ((flag_position + 1) + (sizeof(unsigned int) * 8 -1)) / (sizeof(unsigned int) * 8) *  (sizeof(unsigned int) * 8);
        unsigned int* newFlag = (unsigned int*) realloc(pBit_flags->flags, newCap / (sizeof(unsigned int) * 8) * sizeof(unsigned int));
        if (newFlag == NULL) return FAILURE;

        memset(newFlag + pBit_flags->capacity / (sizeof(unsigned int)* 8), 0, (newCap - pBit_flags->capacity) / 8);
        pBit_flags->flags = newFlag;
        pBit_flags->capacity = newCap;
    }
    (pBit_flags)->flags[flag_position / (sizeof(unsigned int) * 8)] |= (1U << flag_position % (sizeof(unsigned int) * 8));

    return SUCCESS;
}


Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    if(hBit_flags == NULL || flag_position < 0)
    {
        return FAILURE;
    }
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    if (flag_position >= pBit_flags->size)
    {
        pBit_flags->size = flag_position + 1;
    }
    if (flag_position >= pBit_flags->capacity)
    {
        int n_capacity = ((flag_position + 1) + (sizeof(unsigned int) * 8 -1))
                / (sizeof(unsigned int) * 8) * (sizeof(unsigned int) * 8);

        unsigned int* newFlags = (unsigned int*) realloc(pBit_flags->flags,
                                                         n_capacity / (sizeof(unsigned int) * 8) * sizeof(unsigned int));
        if (newFlags == NULL)
        {
            return FAILURE;
        }

        memset(newFlags + pBit_flags->capacity / (sizeof(unsigned int) * 8),
               0,
               (n_capacity - pBit_flags->capacity) / 8);

        pBit_flags->flags = newFlags;
        pBit_flags->capacity = n_capacity;

    }
    pBit_flags->flags[flag_position / (sizeof(unsigned int) *8)] &= ~(1U << flag_position % (sizeof(unsigned int) * 8));
    return SUCCESS;
}

int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position)
{
    if (flag_position < 0 || hBit_flags == NULL)
    {
        return -1;
    }
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    if (flag_position >= pBit_flags->size)
    {
        return -1; // Flag position out of bounds
    }

    unsigned int flag_value = pBit_flags->flags[flag_position / (sizeof(unsigned int) * 8)];
    int bit_index = flag_position % (sizeof(unsigned int) * 8);
    int flag_state = (flag_value >> bit_index) & 1; // Extract the bit at the flag position

    return flag_state;
}


int bit_flags_get_size(BIT_FLAGS hBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    if(pBit_flags == NULL)
    {
        return -1;
    }
    return pBit_flags->size;
}

int bit_flags_get_capacity(BIT_FLAGS hBit_flags)
{
    Bit_flags* pBit_flags = (Bit_flags*)hBit_flags;
    if(pBit_flags == NULL)
    {
        return -1;
    }
    return pBit_flags->capacity;
}

void bit_flags_destroy(BIT_FLAGS* phBit_flags)
{

    Bit_flags *pBit_flags = (Bit_flags*)*phBit_flags;
    if (pBit_flags == NULL)
    {
        exit(1);
    }
    free(pBit_flags->flags);
    free(pBit_flags);
    *phBit_flags = NULL;
}