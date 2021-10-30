#include <stdio.h>
#include <stdint.h>

/*Mtd1: Bruteforce - loops through bit by bit by performing right shift */
//TC - O(n) n = no of bits in binary representation
int GetParity1(int n) {
	int result = 0;
	while(n) {
		result ^= (n & 1);
		n >>= 1;
	}
	return result;
}

/*Mtd2: loops for no of bits that are set, by clearing all set bits from lsb*/
//TC - O(k) k = no of set bits
int GetParity2(int n) {
	int result = 0;
	while(n) {
		result ^= 1; //basically no of times the loop executes
		n &= (n - 1); //clears set bit in LSB 
	}
	return result;
}

//The parity table should be filled like this for 8 bit number
//static const bool paritytable256[256] = {0x0, 0x1, 0x1, 0x0,...};
//for example , for 2 bit numbers paritytable4[4] = {0x0, 0x1, 0x1, 0x0}

/*Mtd3: cache lookup method 1 */

bool paritytable256[256];

int GetParityLookup8(uint8_t n) {
	  return paritytable256[n]; 
}

int GetParityLookup32(uint32_t n) {
	  n ^= n >> 16;
		n ^= n >> 8;
	  return paritytable256[n & 0xFF]; 
}

//lookup shift and xor 
/*
int GetParityLookup32_2(uint32_t n) {
	  const int nLookupSz = 8; 
	  const int nLookupMask = 0xFF;
	  return paritytable256[n >> (3*nLookupSz)] ^ 
					 paritytable256[(n >> (2*nLookupSz)) & nLookupMask] ^ 
					 paritytable256[(n >> nLookupSz) & nLookupMask] ^ 
					 paritytable256[n & nLookupMask]; 
}
*/

//TC = O(n/nLookupSz) eg: 32/8 in this case i.e no of lookups
//all other operations shift, &, ^ are 
//word operations and cpu will take O(1)
int GetParityLookup32_2(uint32_t n) {
	  const int nLookupSz = 8; 
	  const int nLookupMask = 0xFF;
		return paritytable256[n & nLookupMask] ^ 
					 paritytable256[(n >> nLookupSz) & nLookupMask] ^ 
					 paritytable256[(n >> (2*nLookupSz)) & nLookupMask] ^ 
					 paritytable256[n >> (3*nLookupSz)]; 
}

int GetParityLookup64(uint64_t n) {
	  n ^= n >> 32;
	  n ^= n >> 16;
		n ^= n >> 8;
	  return paritytable256[n & 0xFF]; 
}

/*Mtd4: associative property of XOR */
//Recursively divide the (32 bit int) number and find the parity
//note: to use same logic for unsigned long (64 bit) , 
//will have to add 1 more line n>>32 at the beginning 
//TC - O(log n)
int GetParityXor32(uint32_t n) {
	  n ^= n >> 16;
	  n ^= n >> 8;
		n ^= n >> 4;
		n ^= n >> 2;
		n ^= n >> 1;
		return (n & 0x1);
}

int main() {
  int i = 0;
	int a[5] = {0x1, 0x2, 0x3, 0xf, 0x7};
	uint32_t b[3] = {0x0FFFFFFF, 0x0FFFF00FF, 0x0FFFFFF7};
	uint64_t c[3] = {0x0FFFFFFFFFFFFFFF, 0x0FFF00FFFFFFFFFF, 0x0FFFFFF7FFFFFFFF};

	for(i=0;i<5;i++) {
	   printf("\nGet parity of %d is %d  %d",a[i],GetParity1(a[i]), GetParity2(a[i]));
	}
	printf("\n");

	//Fill parity lookup table
  //For numbers up to 8 bits. (0 - 255) so we need the parity of all numbers 0 to 255
  //to be stored in the table as one time operation and served everytime with 
  //lookup on the index.
	for(i=0;i<256;i++) {
		paritytable256[i] = GetParity2(i);
	}
	for(i=0;i<5;i++) {
	   printf("\nGet parity of %d is %d",a[i],GetParityLookup8(a[i]));
	}
	printf("\n");

  //calculate parity of 32 bit num by using lookup table for 8 bits.
	for(i=0;i<3;i++) {
	   printf("\nGet parity of %x is %d ",b[i],GetParityLookup32(b[i]));
	}
	printf("\n");

  //calculate parity of 32 bit num by using lookup table for 8 bits, second mtd.
	for(i=0;i<3;i++) {
	   printf("\nGet parity of %x is %d ",b[i],GetParityLookup32_2(b[i]));
	}
	printf("\n");

  //calculate parity of 64 bit num by using lookup table for 8 bits.
	for(i=0;i<3;i++) {
	   printf("\nGet parity of %llx is %d ",c[i],GetParityLookup64(c[i]));
	}
	printf("\n");

  //calculate parity of 32 bit num by using XOR property.
	for(i=0;i<3;i++) {
	   printf("\nGet parity of %x is %d ",b[i],GetParityXor32(b[i]));
	}
	printf("\n");

	return 0;	
}
