#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

void binaryRepresentation(char* inputName) {
	string line;int n;int power;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			n=atoi(line.c_str());power=1;
			while(power<=n){power *=2;};power /=2;
			while(power>0){cout << (n/power);n=n-power*(n/power);power /= 2;}
			cout <<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	binaryRepresentation(argv[1]);
	return 0;
}


