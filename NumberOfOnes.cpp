#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

void numberOfOnes(char* inputName) {
	string line;int n;int total;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			n=atoi(line.c_str());total=0;
			while(n>0){total+=(n%2);n /=2;}
			cout << total <<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	numberOfOnes(argv[1]);
	return 0;
}


