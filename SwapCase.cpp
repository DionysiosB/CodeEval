#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

void swapCase(char* inputName) {

	string line;char currentChar;
	ifstream inputFile (inputName);	
	if(inputFile){
		while(getline(inputFile,line)){
			for(size_t k = 0; k<line.size() ; k++){
				if( islower(line[k]) ){currentChar = toupper(line[k]);}
				else if( isupper(line[k]) ){currentChar = tolower(line[k]);}
				else {currentChar = line[k];}
				cout << currentChar ;
			}
			cout <<endl;	
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	swapCase(inputName);
	return 0;
}


