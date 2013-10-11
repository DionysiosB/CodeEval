#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

void sumOfDigits(char * inputName) {
	
	string line;unsigned n;unsigned total;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			n=atoi(line.c_str());total=0;
			while(n>0){total+=n%10;n /=10;}
			cout<< total<<endl;
		}
	}
}

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	sumOfDigits(inputName);
	return 0;
}
