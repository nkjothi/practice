#include <stdio.h>

/*reverse all bits in a integer*/
//eg 1011 -> 1101
unsigned int reversebits(unsigned int n) {
	//bruteforce mtd: 
	//iterate the number from lsb and store all 
	//of it in another integer in reverse

  unsigned int r = 0;
	while(n > 0) {
		r <<= 1;

		if((n&1) == 1) {
			r ^= 1;//r |= 1;
		}
		n >>= 1;
	}
	return r;
}

int main() {

	int a = 11;
	printf("\nReverse bits for no %x is %x", a,reversebits(a));
	printf("\n");
  return 0;	
}
