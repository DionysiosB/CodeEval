#include <iostream>
#include <stdint.h>
using namespace std;

int checkEndianness() {
	int i = 1;
	char *low = (char*) &i;
	return *low ? 0 : 1;
}

int main(int argc, char *argv[]){
	if(checkEndianness()){cout <<"BigEndian"<<endl;}
	else{cout <<"LittleEndian"<<endl;}		
	return 0;
}