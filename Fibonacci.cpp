#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

void fibonacci(char * inputName) {
	
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			unsigned n=atoi(line.c_str());
			double phi=(1+sqrt(5))/2;
			double psi=(1-sqrt(5))/2;
			cout << round((pow(phi,1.0*n)-pow(psi,1.0*n))/sqrt(5)) <<endl;
		}
	}
}

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	fibonacci(inputName);
	return 0;
}
