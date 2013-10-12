#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

void sumOfNumbers(char * inputName) {
	
	string line;unsigned total;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){	
		total=0;	
		while(getline(inputFile,line)){total+=atoi(line.c_str());}
		cout <<total <<endl;
	}
}

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	sumOfNumbers(inputName);
	return 0;
}
