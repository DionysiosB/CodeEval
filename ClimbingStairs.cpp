#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>
using namespace std;

int fibonacciSequence(int n){
	double phi=(1+sqrt(5))/2;
	double psi=(1-sqrt(5))/2;
	return round((pow(phi,n)-pow(psi,n))/sqrt(5));
}

void climbingStairs(char* inputName) {
	string line;int n;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			n=atoi(line.c_str());
			cout<<fibonacciSequence(n+1)<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	climbingStairs(argv[1]);
	return 0;
}