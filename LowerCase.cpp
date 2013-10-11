#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

void lowercaseString(char * inputName) {
	string line;	
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			transform(line.begin(),line.end(),line.begin(),::tolower);
			cout <<line <<endl;
		}
	}
}	

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	lowercaseString(inputName);
	return 0;
}
