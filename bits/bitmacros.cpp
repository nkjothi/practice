#include <stdio.h>
/*For 32 bit numbers */

#define SETBIT(n,ind) ((n) |= (1<<(ind)))
#define CLRBIT(n,ind) ((n) &= ~(1<<(ind)))
#define FLIPBIT(n,ind) ((n) ^= (1<<(ind)))
#define GETBIT(n,ind) (1 & (n>>(ind)))

#define SETNBITSLSB(n,nobits) ((n) |= (~(-1 << (nbits))))
#define CLRNBITSLSB(n,nobits) ((n) &= (-1 << (numbits)))
#define FLIPNBITSLSB(n,nobits) ((n) ^= ~(-1 << (nbits)))

#define SETNBITSMSB(n,nobits) ((n) |= (-1 << (32 - (nbits))))
#define CLRNBITSMSB(n,nobits) ((n) &= ((1 << (32 - (nbits))) - 1))
#define FLIPNBITSMSB(n,nobits) ((n) ^= (-1 << (32 - (nbits)))) 

