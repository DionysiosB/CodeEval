#include <iostream>
using namespace std;

void checkEndianness(){
	union {uint32_t i;char c[4];} bint = {0x01020304};	
	if(bint.c[0] == 1) {cout <<"BigEndian";}
	if(bint.c[0] == 4) {cout <<"LittleEndian";}
}

int main (int argc, char * const argv[]) {
	 checkEndianness();
	 return 0;
}
