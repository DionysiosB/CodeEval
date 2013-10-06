#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

const int maxIterations=100000;

void happyNumbers(char * inputName) {
	
	string line;
	unsigned n;unsigned total;
	int counter;
	
	ifstream inputFile (inputName);	
	//ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			n=atoi(line.c_str());
			counter=0;
			while(counter<maxIterations){
				++counter;total=0;
				while(n>0){total+=int(pow(1.0*(n%10),2));n /=10;}
				if(total==1){cout << "1"<<endl;break;}
				if(counter>=maxIterations){cout << "0"<<endl;break;}
				n=total;
			}
		}

	}
}


int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	happyNumbers(inputName);
	return 0;
}
