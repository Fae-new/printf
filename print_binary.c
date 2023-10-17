/**
 * print_binary - Prints the binary representation of an unsigned integer.
 * @num: The unsigned integer to be printed in binary format.
 *
 * Description: This function takes an unsigned integer as input and prints
 * its binary representation to the standard output. The function omits leading
 * zeros and prints the significant bits of the binary representation.
 */

void print_binary(unsigned int num) {
    if (num == 0) {
        write(STDOUT_FILENO, "0", 1);
        return;
    }

    bool leadingZero = true;
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        bool bit = num & (1 << i);
        if (bit) {
            write(STDOUT_FILENO, "1", 1);
            leadingZero = false;
        } else if (!leadingZero) {
            write(STDOUT_FILENO, "0", 1);
        }
    }
}
