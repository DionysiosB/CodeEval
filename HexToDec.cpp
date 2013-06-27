#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int hexToDec(char * inputName) {
	
	unsigned digit=0;unsigned total=0;	
	string line;
	
	ifstream inputFile (inputName);	
	//ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			total=0;
			for(unsigned k=0;k<line.size();++k){
				if(line[k]>='0' && line[k]<='9') digit=line[k]-'0';
				if(line[k]>='a' && line[k]<='f') digit=line[k]-'a'+10;
				total=16*total+digit;
			}
			cout << total <<endl;
		}
	}
	return 0;
}	


int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	hexToDec(inputName);
	return 0;
}
