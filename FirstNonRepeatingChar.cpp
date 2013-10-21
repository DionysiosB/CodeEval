#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

void firstNonrepeating(char* inputName) {
	string line;short int N=128;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			unsigned freqArray[N];for(int k=0;k<N;++k){freqArray[k]=0;}
			for(unsigned k=0;k<line.size();++k){freqArray[int(line[k])]++;}
			for(unsigned k=0;k<line.size();++k){if(freqArray[int(line[k])]==1){cout <<line[k]; break;}}
			cout <<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	firstNonrepeating(argv[1]);
	return 0;
}


