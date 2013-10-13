#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

void fileSize(char * inputName) {
	string line;
	ifstream inputFile (inputName);	
	//ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			ifstream file(line.c_str(), ios::binary | ios::ate);
			cout << file.tellg() <<endl;
		}
	}
}

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	fileSize(inputName);
	return 0;
}
