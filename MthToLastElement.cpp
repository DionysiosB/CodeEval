#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

void mthToLast(char * inputName) {
	
	string line;char newChar;vector<char> inputVector;unsigned m;int charsEnd;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			inputVector.clear();
			charsEnd=line.find_first_of("123456789");
			m=atoi((line.substr(charsEnd)).c_str());
			line=line.substr(0,charsEnd);
			istringstream buf(line);
			while(buf >> newChar){inputVector.push_back(newChar);}
			if(m<=inputVector.size()){cout<<inputVector[inputVector.size()-m]<<endl;}
			else {cout << -1<<endl;}			
		}
	}
}	

int main (int argc, char * const argv[]) {
	char * inputName=argv[1];
	mthToLast(inputName);
	return 0;
}
