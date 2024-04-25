#ifndef NUMBERFILTER_H
#define NUMBERFILTER_H

typedef struct
{
    unsigned char* bit_array;
}BitFlags;

void set_bit(BitFlags* flags, int val);
int is_bit_set(BitFlags* flags, int val);
BitFlags* init_bit_array(void);
void destroy_bit_flags(BitFlags* flags);
int read_bit_flags_input(BitFlags* flags);
void print_bit_flags(BitFlags* flags);

#endif