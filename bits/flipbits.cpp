#include <stdio.h>
#include <limits.h>

#define MAX_INTBITS ((sizeof(int)) * (CHAR_BIT))

unsigned int FlipBit(unsigned int n, short ind) {
    n ^= (1<<ind);  //00001000 inp eg:00001100, 00000100
    return n;       //after xor op: 00000100,00001100
}

unsigned int FlipNBitsLsb(unsigned int n, short nbits) {
    unsigned int mask = ~(-1 << nbits);
    n ^= mask;
    return n;
}

unsigned int FlipNBitsMsb(unsigned int n, short nbits) {
    //unsigned int mask = (-1 << (32-nbits));
    unsigned int mask = (-1 << (MAX_INTBITS - nbits));
    n ^= mask;
    return n;
}

short GetBit(unsigned int n, short ind) {
    bool is_set = (1 & (n>>ind));
    return is_set;
}

int main() {
    printf("Flipbit %d\n",FlipBit(3,0));
    printf("Flipbit %d\n",FlipNBitsLsb(15,3));
    printf("Flipbit %d\n",FlipNBitsLsb(10,4));
    printf("Flipbit %x\n",FlipNBitsMsb(0x0FFFFFFF,4));
    printf("Getbit %d \n",GetBit(3,1));
    printf("Getbit %d \n",GetBit(2,1));
    printf("Getbit %d \n",GetBit(2,0));
    printf("Getbit %d \n",GetBit(2,3));
    printf("Getbit %d \n",GetBit(8,3));
}
