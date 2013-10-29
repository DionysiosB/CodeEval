#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

void capitalizeWords(char * inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	bool first=0;
	if(inputFile){		
		while(getline(inputFile,line)){
			first=1;
			for(unsigned k=0;k<line.size();k++){
				if(isspace(line[k]) || ispunct(line[k])){first=1;}
				else if(first){first=0;if(line[k]>='a' && line[k]<='z'){line[k]+='A'-'a';}}
				cout << line[k];				
			}
			cout <<endl;
		}
		inputFile.close();
	}
}	

int main (int argc, char * const argv[]) {
	capitalizeWords(argv[1]);
	return 0;
}