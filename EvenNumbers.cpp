#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void evenNumbers(char* inputName) {
	FILE * inputFile = fopen(inputName,"r");
	if(inputFile){
		int temp = 0;
		while(fscanf(inputFile, "%d\n", &temp) == 1){printf("%d\n", (1 + temp) % 2 );}
		fclose(inputFile);
	}
}

int main (int argc, char * const argv[]) {
	evenNumbers(argv[1]);
	return 0;
}
