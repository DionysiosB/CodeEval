#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

void bitPositions(char* inputName) {

	string line,inputStr;
	int firstComma,secondComma,number,first,second;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			firstComma=line.find(",");secondComma=line.find(",",firstComma+1);
			inputStr=line.substr(0,firstComma);number=atoi(inputStr.c_str());
			inputStr=line.substr(firstComma+1,secondComma-firstComma-1);first=atoi(inputStr.c_str());
			inputStr=line.substr(secondComma+1);second=atoi(inputStr.c_str());
			if((number/int(pow(2.0,first-1)))%2 ==(number/int(pow(2.0,second-1)))%2) cout <<"true"<<endl;
			else cout <<"false"<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	bitPositions(inputName);
	return 0;
}


