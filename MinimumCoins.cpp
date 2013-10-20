#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

void minCoins(char* inputName) {
	string line;int n;int total;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			n=atoi(line.c_str());
			total=(n/5);
			n=(n-5*(n/5));
			total+=n/3;
			total+=n-3*(n/3);
			cout << total<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	minCoins(argv[1]);
	return 0;
}


