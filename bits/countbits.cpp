#include <stdio.h>
/* API to count the number of set bits in a binary integer */

/*bruteforce version which traverse all bits to count 1s*/
short CountSetBits(unsigned int n) {
	 short num_bits = 0;
	 while(n) {
			num_bits += n & 1;
			n = n >> 1;
	 }
	 return num_bits;
}

/*better approach which counts only 1s*/
short CountSetBits2(unsigned int n) {
	 short num_bits = 0;
	 while(n) {
			n = n & (n-1);
			num_bits++;
	 }
	 return num_bits;
}

int main() {
	 unsigned int a[5] = {1, 2, 3, 4, 5};    
	 for (int i=0;i<5;i++) {
			printf("Num bits set in %d is %d \n",a[i],CountSetBits(a[i]));
			printf("Num bits set in %d is %d \n",a[i],CountSetBits2(a[i]));
	 }
} 
