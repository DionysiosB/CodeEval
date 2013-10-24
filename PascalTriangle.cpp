#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

void flavius(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){	
			unsigned n=atoi(line.c_str());
			unsigned pascalMatrix[n][n];
			for(unsigned row=0;row<n;++row){
				for(unsigned col=0;col<=row;++col){
					if(col==0 || col==row){pascalMatrix[row][col]=1;}
					else {pascalMatrix[row][col]=pascalMatrix[row-1][col-1]+pascalMatrix[row-1][col];}
					cout << pascalMatrix[row][col]<<" ";
				}
			}
			cout <<endl;	
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	flavius(argv[1]);
	return 0;
}


