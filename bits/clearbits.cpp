#include <stdio.h>
#include <stdint.h>

/* clear bit at pos i from lsb */
unsigned int ClearBit(unsigned int n, short ind) {
    short mask = ~(1 << ind); // 0000 1000 -> 1111 0111
    return (n & mask);
}

/* clear numbits from lsb */
unsigned int ClearNBitsLsb(unsigned int n, short numbits) {
    short mask = -1 << numbits;   //1111 1111 -> 11110000
    return (n & mask);
}

/* clear numbits from msb */
unsigned int ClearNBitsMsb(unsigned int n, short numbits) {
    numbits = 32 - numbits;
    unsigned int mask = 1 << numbits ;// 0001 0000 eg numbits = 4
    mask = mask - 1;		// 0000 1111
    return (n & mask);
}

/* clear numbits from msb, uint8 version */
uint8_t ClearNBitsMsb8(uint8_t n, short numbits) {
    numbits = 8 - numbits;
    uint8_t mask = 1 << numbits ;
    mask = mask - 1;		
    return (n & mask);
}

int main() {

    unsigned int n[5] = {1,2,3,4,5};
    short j[5] = {0,1,0,2,2};
    for(int i=0;i<5;i++) {
        printf("Clear bit for %d at pos %d is %d \n", n[i],j[i], ClearBit(n[i],j[i]));
    }

    unsigned int x = 7;
    printf("Clear 2 lsb bits from %d is %d \n",x,ClearNBitsLsb(x,2));

    unsigned int y = 0x0FFFFFFF; // FF FF FF FF - 4 bytes - 32 bits
    printf("Clear 8 MSB bits from %d is %d \n",y,ClearNBitsMsb(y,8));
    printf("Clear 16 MSB bits from %d is %d \n",y,ClearNBitsMsb(y,16));
    printf("Clear 24 MSB bits from %d is %d \n",y,ClearNBitsMsb(y,24));
    printf("Clear 28 MSB bits from %x is %x \n",y,ClearNBitsMsb(y,28));
   
    uint8_t p = 0xFF; 
    printf("Clear 4 MSB bits from %d is %d \n",p,ClearNBitsMsb8(p,4));
    
}
