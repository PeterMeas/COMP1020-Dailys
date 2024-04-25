#include <stdio.h>
#include "bit_flags.h"

int main() {
    // Initialize bit flags with 10 bits
    BIT_FLAGS flags = bit_flags_init_number_of_bits(10);

    // Check if initialization was successful
    if (flags == NULL) {
        printf("Failed to initialize bit flags\n");
        return 1;
    }

    bit_flags_set_flag(flags, 100);
    printf("State of flag at position 100: %d\n", bit_flags_check_flag(flags, 100));
    bit_flags_unset_flag(flags, 100);
    printf("State of flag at position 100: %d\n", bit_flags_check_flag(flags, 100));



    // Get size and capacity of bit flags
    printf("Size of bit flags: %d\n", bit_flags_get_size(flags));
    printf("Capacity of bit flags: %d\n", bit_flags_get_capacity(flags));

    // Destroy bit flags and free memory
    bit_flags_destroy(&flags);

    return 0;
}
