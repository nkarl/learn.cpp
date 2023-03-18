#include <stdio.h>
const char *bit_rep[16] = {
    [ 0] = "0000", [ 1] = "0001", [ 2] = "0010", [ 3] = "0011",
    [ 4] = "0100", [ 5] = "0101", [ 6] = "0110", [ 7] = "0111",
    [ 8] = "1000", [ 9] = "1001", [10] = "1010", [11] = "1011",
    [12] = "1100", [13] = "1101", [14] = "1110", [15] = "1111",
};

void print_byte(unsigned int byte)
{
    printf("%s%s\n", bit_rep[byte >> 4], bit_rep[byte & 0x0F]);
}
struct bits {
    unsigned int bit0       : 1;
    unsigned int bit123     : 3;
    unsigned int otherbits  : 27;
    unsigned int lastbit    : 1;
} var;

int main() {
    struct bits myBits;
    myBits.bit0 = 1;
    myBits.bit123 = 5;
    myBits.otherbits = 53;
    myBits.lastbit = 0;
    print_byte(myBits.bit0);
    print_byte(myBits.bit123);
    print_byte(myBits.otherbits);
    print_byte(myBits.lastbit);
    /*printf("%x\n", myBits.bit0);*/
    /*printf("%x\n", myBits.bit123);*/
    /*printf("%x\n", myBits.otherbits);*/
    /*printf("%x\n", myBits.lastbit);*/
    return 0;
}
