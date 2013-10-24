#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

void primesCount(char* inputName) {
	
	string line;unsigned commaPos,lower,upper;
	
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){	
			commaPos=line.find(",");
			lower=atoi(line.substr(0,commaPos).c_str());upper=atoi((line.substr(commaPos+1)).c_str());
			bool primes[upper+1];
			primes[0]=0;primes[1]=0;
			for (unsigned k=2; k<=upper; k++) primes[k]=1;
			for (unsigned k=2; k<=upper; k++) {if (primes[k]) {for (unsigned m=2; m<=upper/k; m++) {primes[m*k]=0;}}}
			unsigned total=0;
			for (unsigned k=lower; k<=upper; k++) {if(primes[k]){++total;}}
			cout <<total<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	primesCount(argv[1]);
	return 0;
}


