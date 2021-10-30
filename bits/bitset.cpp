#include <iostream>
#include <bitset>
#include <string>

using namespace std;
int main() {
	bitset<8> byte(std::string("00000000"));

	byte.set(3); //setbit 00001000
	cout << byte << endl;
	byte.reset(3); // clear 00000000
	cout << byte << endl;
	byte.flip(3); // flip 00001000
	cout << byte << endl;

	return 0;
}

