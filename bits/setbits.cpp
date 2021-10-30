#include <stdio.h>
#define arr_set(type, arr, ...) { \
    int arrsz = sizeof(arr)/sizeof(type); \
    type *parr = (type[]){__VA_ARGS__}; \
    for (int i=0;i<arrsz;i++) \
			arr[i] = *parr++ ; }

/* sets the bit at position ind to 1 */
unsigned int SetBit(unsigned int n, short ind) {
    n = n | (1 << ind);     //00001000
    return n;
}

/* set n bits from lsb */
unsigned int SetBitNLsb(unsigned int n, short nbits) {
    unsigned int mask = ~(-1 << nbits); //11110000-> 00001111
    n = n | mask;
    return n;
}

/* set n bits from msb */
unsigned int SetBitNMsb(unsigned int n, short nbits) {
    unsigned int mask = (-1 << (32 - nbits)); //11110000
    n = n | mask;
    return n;
}

int main() {
    unsigned int n[5] = {1,2,3,4,5};
    short j[5] = {2,2,2,4,4};
    for(int i=0;i<5;i++) {
	printf("Set bit for %d at pos %d is %d \n", n[i],j[i], SetBit(n[i],j[i]));
    }
    
    arr_set(int,n,2,4,8,8,10);
    arr_set(short,j,1,2,3,2,1);
    for(int i=0;i<5;i++) {
        printf("Set %d lsb bits for %d is %d \n",j[i],n[i],SetBitNLsb(n[i],j[i]));
    }

    arr_set(int, n, 0x0F000001, 0x0F000001, 0x0F000001, 0x0F000001, 0x0F000001);
    arr_set(short,j,2,4,12,16,20);
    for(int i=0;i<5;i++) {
        printf("Set %d msb bits for %x is %x \n",j[i],n[i],SetBitNMsb(n[i],j[i]));
    }
}

//g++ setbits.cpp -w
