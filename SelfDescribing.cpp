#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int selfDescribing(char * inputName) {
	
	string line;
	unsigned number[10];unsigned counts[10];
	unsigned short digit; bool isSD;
	
	ifstream inputFile (inputName);	
	//ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			for(unsigned k=0;k<10;++k){
				number[k]=0;counts[k]=0;
			}
			for(unsigned k=0;k<line.size();++k){
				digit=line[k]-'0';
				number[k]=digit;
				counts[digit]++;
			}
			isSD=1;
			for(unsigned k=0;k<10;++k){
				if(number[k] != counts[k]){
					isSD=0;
					break;
				}
			}
			cout <<isSD <<endl;
		}
	}
	
	
	return 0;
}	


int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	selfDescribing(inputName);
	return 0;
}
