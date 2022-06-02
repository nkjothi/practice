#include <stdio.h>

/*swap 2 bits at position i and j*/
//eg 1000 1011 -> i=2, j=7 ===>0000 1111
unsigned int swapbitspos(unsigned int n, short i, short j) {
	//Get bit logic, swap when bits at index i and j are not equal
	if((1 & (n>>(i))) != (1 & (n>>(j)))) {
		unsigned int mask = (1 << i) | (1 << j); //prepare bitmask with both indexes set
		n ^= mask;	//xor n with mask, if n is 0 - xor 1 will get 1, if 1 - xor 1 will give 0
	}
	return n;
}

/*pairwise swap - swap odd and even bit positions */
//swap 0 and 1, 2 and 3, 4 and 5 etc
//eg 1000 1011 -> 0100  0111
unsigned int swapoddeven(unsigned int n) {
	unsigned int mask_odd = 0xAAAAAAAA; // 0xaa --> 1010 1010	(bits 1,3,5 etc)
	unsigned int mask_even = 0x55555555;// 0x55 --> 0101 0101 (bits 0,2,4 etc)
	return (((n & mask_odd) >> 1) | ((n & mask_even) << 1));
}

int main() {

	int a = 0x8b;
	int i = 2;
	int j = 7;
	printf("\nSwap bit at position %d and %d for no %x is %x",i,j,a,swapbitspos(a,i,j));
	printf("\nSwap odd even bits for no %x is %x", a,swapoddeven(a));
	printf("\n");
  return 0;	
}
